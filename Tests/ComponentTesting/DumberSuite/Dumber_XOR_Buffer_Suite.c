#include "unity.h"
#include "Dumber.h"
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

void setUp(void) {}
void tearDown(void) {}

// Test XOR_Buffer pour un message simple
void test_XOR_Buffer(void)
{
    const char* key = "ABC";
    const uint8_t input[5] = {1, 2, 3, 4, 5};
    uint8_t output[5];
    uint8_t expected[5];

    for (int i = 0; i < 5; i++)
        expected[i] = input[i] ^ key[i % 3];

    Dumber_XOR_Buffer(input, 5, key, output);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, output, 5);
}


int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_XOR_Buffer);
    return UNITY_END();
}
