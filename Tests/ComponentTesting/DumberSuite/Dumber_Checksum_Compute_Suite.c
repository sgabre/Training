#include "unity.h"
#include "Dumber.h"
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

void setUp(void) {}
void tearDown(void) {}

// Test Checksum_Compute / Checksum_Verify
void test_ChecksumIsCorrect(void)
{
    const uint8_t message[4] = {1,2,3,4};
    const char* key = "key";

    // On calcule le checksum
    uint8_t checksum = Dumber_Checksum_Compute(message, 4, key);

    uint8_t message_with_checksum[5];
    memcpy(message_with_checksum, message, 4);
    message_with_checksum[4] = checksum; // ajoute le checksum à la fin

    // On vérifie que le checksum est correct
    TEST_ASSERT_TRUE(Dumber_Checksum_Verify(message_with_checksum, 5, key));
}

void test_ChecksumIsIncorrect(void)
{
    const uint8_t message[4] = {1,2,3,4};
    const char* key = "key";
    uint8_t checksum = Dumber_Checksum_Verify(message, 4, key);

    uint8_t message_with_checksum[5];
    memcpy(message_with_checksum, message, 4);
    message_with_checksum[4] = checksum;

    // Test avec checksum incorrect
    message_with_checksum[4] = checksum ^ 0xFF;
    TEST_ASSERT_FALSE(Dumber_Checksum_Verify(message_with_checksum, 5, key));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_ChecksumIsCorrect);
    RUN_TEST(test_ChecksumIsIncorrect);
    return UNITY_END();
}
