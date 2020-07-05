#include <gtest/gtest.h>
#include <string>
#include <fstream>

#include <hardware/chip.hpp>

// Prime number near 10Kb
// Prime because tests on chips with larger memory need to wrap addresses.
#define CHIP_REGISTER_SIZE 10243

#define STR(S) STR_(S)
#define STR_(S) #S

unsigned char register_memory[CHIP_REGISTER_SIZE];

template <class T>
void __sanitiseRegisterForTest(T** reg) {
    *reg = (T*)((long(*reg) % CHIP_REGISTER_SIZE) + register_memory);
}

#define SANITISE_REG_FOR_TEST(REG) __sanitiseRegisterForTest(&REG)

// TODO Ensure correct program flow. (Tasks take turns. Halted tasks don't
//  prevent other tasks.) This may need to be done on a real chip.
// TODO Ensure that callbacks occur within a reasonable number of clock cycles.

// Uses a record to determine if any side effects or memory accesses have
//  changed between tests.
// Not foolproof, but better than nothing.

// r/w [function] [[read code] | ([addr] [a] [b])*]
std::map<std::string, std::string>* record = nullptr;
std::map<std::string, std::string>* missing = nullptr;
bool update = false;

int main(int argc, char **argv) {
    if(argc >= 2) {
        update = (strcmp(argv[1], "-u") == 0);
    }

    ::testing::InitGoogleTest(&argc, argv);

    const int result = RUN_ALL_TESTS();

    return update ? 0 : result;
}

struct MyEnvironment : public ::testing::Environment {
    std::fstream recordFile;

    ~MyEnvironment() override {
        if(missing->size() > 0) {
            if(update) {
                for(auto it = missing->begin(); it != missing->end(); it++) {
                    recordFile << it->first;

                    if(it->second.size() > 0) {
                        recordFile << " " << it->second;
                    }

                    recordFile << std::endl;
                }

                std::cout << "Record updated. Run test again to verify." << std::endl;
            } else {
                std::cout << "Missing records:" << std::endl;

                for(auto it = missing->begin(); it != missing->end(); it++) {
                    std::cout << it->first << " " << it->second << std::endl;
                }
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

        std::string recordPath = "record_" + std::string(STR(CHIP));

        if(update) {
            recordFile.open(recordPath, std::fstream::out | std::fstream::in | std::fstream::trunc);
        } else {
            recordFile.open(recordPath, std::fstream::in);
        }

        char buffer[1024];

        while(recordFile.getline(buffer, 1024)) {
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

        recordFile.clear();
        recordFile.seekg(0, std::ios::beg);
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

// Macros and functions for testing function side effects and memory access.

template <class F>
void test_reg_write(F f, const char* str) {
    std::stringstream ss;

    for(int c = 0x00; ; c = 0xff) {
        memset(register_memory, c, CHIP_REGISTER_SIZE);

        f();

        for(int i = 0; i < CHIP_REGISTER_SIZE; i++) {
            if(register_memory[i] != c) {
                ss << std::setfill('0') << std::setw(2) << std::hex << i << ":";
                ss << std::setfill('0') << std::setw(2) << c << ":";
                ss << std::setfill('0') << std::setw(2) << (int)register_memory[i] << ":";
            }
        }

        if(c == 0xff) {
            break;
        }
    }

    std::string key;

    key += "w ";
    key += str;

    auto it = record->find(key);

    if(it == record->end()) {
        ADD_FAILURE() << "Couldn't find record for w " << str << " " << ss.str();
        missing->insert(std::pair<std::string, std::string>(key, ss.str()));
    } else {
        std::string current = ss.str();
        std::string previous = it->second;
        EXPECT_EQ(current, previous) << "The side effect of " << str << " has changed";
        record->erase(it);
    }
}

template <class T, class F>
void test_reg_read_write(F f, const char* str) {
    uint64_t seed = 59329876;

    std::stringstream ss;

    for(int i = 0; i < 32; i++) {
        for(int _r = 0; _r < CHIP_REGISTER_SIZE; _r++) {
            register_memory[_r] = uint8_t((seed / 65536) % 32768);
            seed = seed * 1103515245 + 12345;
        }

        auto t = (int)f();

        ss << std::hex << (int)t;
    }

    std::string key;

    key += "r ";
    key += str;

    auto it = record->find(key);

    if(it == record->end()) {
        ADD_FAILURE() << "Couldn't find record for r " << str << " " << ss.str();
        missing->insert(std::pair<std::string, std::string>(key, ss.str()));
    } else {
        std::string current = ss.str();
        std::string previous = it->second;
        EXPECT_EQ(current, previous) << "The return value of " << str << " has changed";
        record->erase(it);
    }
}

#define TEST_REG_WRITE(FUNC) TEST_REG_WRITE_(FUNC)
#define TEST_REG_WRITE_(FUNC) \
    test_reg_write([]() { FUNC; }, #FUNC)

#define TEST_REG_READ_WRITE(FUNC) TEST_REG_READ_WRITE_(FUNC)
#define TEST_REG_READ_WRITE_(FUNC) \
    TEST_REG_WRITE(FUNC); \
    test_reg_read_write<decltype(FUNC)>([]() { return FUNC; }, #FUNC)

#include <nblib.hpp>
