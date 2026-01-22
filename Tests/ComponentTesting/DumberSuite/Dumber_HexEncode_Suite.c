#include "unity.h"
#include "Dumber.h"
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

void setUp(void) {}
void tearDown(void) {}


// Test HexEncode
void test_HexEncode(void)
{
    const uint8_t input[3] = {0x12, 0xAB, 0xFF};
    char output[7] = {0};  // 3 octets * 2 + '\0'
    Dumber_HexEncode(input, 3, output, sizeof(output));
    TEST_ASSERT_EQUAL_STRING("12ABFF", output);
}


int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_HexEncode);
    return UNITY_END();
}
