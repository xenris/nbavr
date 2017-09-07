# Random

## Example

```c++
nbavr::Random random;

int16_t i = random.next<int16_t>();
float f = random.next<float>();
```

## class Random

#### Random()
Constructor with seed defaulting to 1.

#### Random(uint32_t seed)
Constructor with user defined seed.

#### T next()
Get the next random value.
