#include "unity.h"
#include "Dumb.h"
#include <string.h>
#include <stdbool.h>

void setUp(void) {}
void tearDown(void) {}

// Test Encrypt et Decrypt
void testIntegrationComponent_EncryptDecrypt(void)
{
    const char* message = "HelloWorld";
    const char* key = "12345";
    char encrypted[256] = {0};
    char decrypted[256] = {0};

    // Encrypt
    Dumb_Encrypt(message, key, encrypted, sizeof(encrypted));
    TEST_ASSERT_TRUE(strcmp(message, encrypted) != 0); // encrypt != original

    // Decrypt
    Dumb_Decrypt(encrypted, key, decrypted, sizeof(decrypted));
    TEST_ASSERT_EQUAL_STRING(message, decrypted); // decrypted == original
}


int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(testIntegrationComponent_EncryptDecrypt);
    return UNITY_END();
}
