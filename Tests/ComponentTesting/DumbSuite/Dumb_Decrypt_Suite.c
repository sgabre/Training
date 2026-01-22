#include "unity.h"
#include "Dumb.h"
#include "MockDumber.h"   // <-- le mock
#include <string.h>
#include <stdbool.h>

void setUp(void)
{
    MockDumber_Init();
}

void tearDown(void)
{
    MockDumber_Verify();
    MockDumber_Destroy();
}

void test_EncryptDecrypt(void)
{
    const char* message = "HelloWorld";
    const char* key = "12345";
    char encrypted[256] = {0};
    char decrypted[256] = {0};
    size_t len = strlen(message);

    // Dumb_Encrypt appelle Dumber_XOR_Buffer
    Dumber_XOR_Buffer_Expect(
        (uint8_t*)message,
        len,
        (const char*)key,   // correction warning
        (uint8_t*)encrypted
    );

   

    // Exécution
    Dumb_Encrypt(message, key, encrypted, sizeof(encrypted));


     // Dumb_Decrypt appelle Dumber_XOR_Buffer
    Dumber_XOR_Buffer_Expect(
        (uint8_t*)encrypted,
        len,
        (const char*)key,
        (uint8_t*)decrypted
    );
    Dumb_Decrypt(encrypted, key, decrypted, sizeof(decrypted));

    // Vérification finale
    TEST_ASSERT_EQUAL_STRING(message, decrypted);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_EncryptDecrypt);
    return UNITY_END();
}
