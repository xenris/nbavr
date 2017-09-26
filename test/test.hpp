#include <gtest/gtest.h>
#include <string>
#include <fstream>

#define CHIP_REGISTER_SIZE 0x200

uint8_t register_memory[CHIP_REGISTER_SIZE];
#define register_offset register_memory

#include <nbavr.hpp>

#ifndef RECORD_ID
    #error RECORD_ID not defined
#endif

using namespace nbavr;
using namespace hw;

// TODO Ensure correct program flow. (Tasks take turns. Halted tasks don't
//  prevent other tasks.) This may need to be done on a real chip.
// TODO Ensure that callbacks occur within a reasonable number of clock cycles.

// Uses a record to determine if any side effects or memory accesses have
//  changed between tests.
// Not foolproof, but better than nothing.

// r/w [function] [[read code] | ([addr] [a] [b])*]
std::map<std::string, std::string>* record = nullptr;
std::map<std::string, std::string>* missing = nullptr;

struct MyEnvironment : public ::testing::Environment {
    ~MyEnvironment() override {
        if(missing->size() > 0) {
            std::cout << "Missing records:" << std::endl;
            for(auto it = missing->begin(); it != missing->end(); it++) {
                std::cout << it->first << " " << it->second << std::endl;
            }
        }

        delete record;
        record = nullptr;
        delete missing;
        missing = nullptr;
    }

    void SetUp() override {
        record = new std::map<std::string, std::string>();
        missing = new std::map<std::string, std::string>();

        std::string recordPath = "record_" + std::string(RECORD_ID);

        std::fstream recordFile(recordPath, std::fstream::out | std::fstream::in | std::fstream::app);

        char buffer[256];

        while(recordFile.getline(buffer, 256)) {
            int length = strlen(buffer);
            char type = buffer[0];
            std::string function;
            std::string value;

            int i;

            for(i = 2 ; (i < length) && !isspace(buffer[i]); i++) {
                function += buffer[i];
            }

            for(i++ ; (i < length); i++) {
                value += buffer[i];
            }

            std::string key;
            key += type;
            key += ' ';
            key += function;

            if(record->find(key) == record->end()) {
                record->insert(std::pair<std::string, std::string>(key, value));
            } else {
                ADD_FAILURE() << "Duplicate record: " << key;
            }
        }

        recordFile.close();
    }

    void TearDown() override {
        if(record->size() > 0) {
            for(auto it = record->begin(); it != record->end(); it++) {
                ADD_FAILURE() << "Record exists but was not tested: " << it->first << " " << it->second << std::endl;
            }
        }
    }
};

::testing::Environment* const env = ::testing::AddGlobalTestEnvironment(new MyEnvironment);

// Macros for testing function side effects and memory access.

#define TEST_REG_WRITE(FUNC) \
    { \
        std::stringstream ss; \
        for(int _c = 0x00; ; _c = 0xff) { \
            memset(register_memory, _c, CHIP_REGISTER_SIZE); \
            FUNC; \
            for(int _i = 0; _i < CHIP_REGISTER_SIZE; _i++) { \
                if(register_memory[_i] != _c) { \
                    ss << std::setfill('0') << std::setw(2) << std::hex << _i << ":"; \
                    ss << std::setfill('0') << std::setw(2) << _c << ":"; \
                    ss << std::setfill('0') << std::setw(2) << (int)register_memory[_i] << ":"; \
                } \
            } \
            if(_c == 0xff) break; \
        } \
        std::string key; \
        key += "w "; \
        key += #FUNC; \
        auto it = record->find(key); \
        if(it == record->end()) { \
            ADD_FAILURE() << "Couldn't find record for w " << #FUNC << " " << ss.str(); \
            missing->insert(std::pair<std::string, std::string>(key, ss.str())); \
        } else { \
            std::string current = ss.str(); \
            std::string previous = it->second; \
            EXPECT_EQ(current, previous) << "The side effect of " << #FUNC << " has changed"; \
            record->erase(it); \
        } \
    }

#define TEST_REG_READ_WRITE(FUNC) \
    TEST_REG_WRITE(FUNC) \
    { \
        unsigned long _seed = 59329876; \
        std::stringstream ss; \
        for(int _i = 0; _i < 10; _i++) { \
            for(int _r = 0; _r < CHIP_REGISTER_SIZE; _r++) { \
                register_memory[_r] = (_seed / 65536) % 32768; \
                _seed = _seed * 1103515245 + 12345; \
            } \
            auto _t = FUNC; \
            ss << std::hex << (long)_t; \
        } \
        std::string key; \
        key += "r "; \
        key += #FUNC; \
        auto it = record->find(key); \
        if(it == record->end()) { \
            ADD_FAILURE() << "Couldn't find record for r " << #FUNC << " " << ss.str(); \
            missing->insert(std::pair<std::string, std::string>(key, ss.str())); \
        } else { \
            std::string current = ss.str(); \
            std::string previous = it->second; \
            EXPECT_EQ(current, previous) << "The return value of " << #FUNC << " has changed"; \
            record->erase(it); \
        } \
    }
