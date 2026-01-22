#include "unity.h"
#include "Dumb.h"
#include "MockDumber.h"   // <- le mock
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

void test_SignVerify_UsesDumber(void)
{
    const char* message = "TestMessage";
    const char* key = "Key123";
    char signed_msg[256] = {0};

    // Forcer Dumber_Checksum_Compute à retourner un checksum prévisible
    uint8_t fake_checksum = 0x42;
    Dumber_Checksum_Compute_ExpectAndReturn(
        (const uint8_t*)message,
        strlen(message),
        (const char*)key,
        fake_checksum
    );

    // Sign
    Dumb_Sign(message, key, signed_msg, sizeof(signed_msg));

    TEST_ASSERT_TRUE(strcmp(message, signed_msg) != 0); // signature modifie le message

    // Pour Verify, forcer le même checksum
    Dumber_Checksum_Compute_ExpectAndReturn(
        (const uint8_t*)signed_msg,
        strlen(signed_msg),
        (const char*)key,
        fake_checksum
    );

    bool valid = Dumb_Verify(signed_msg, key);
    TEST_ASSERT_TRUE(valid);

    // Test avec message corrompu -> should fail
    size_t len = strlen(signed_msg);
    signed_msg[len-1] ^= 0xFF; // corrompre le checksum à la fin

    Dumber_Checksum_Compute_ExpectAndReturn(
        (const uint8_t*)signed_msg,
        strlen(signed_msg),
        (const char*)key,
        fake_checksum
    );

    TEST_ASSERT_FALSE(Dumb_Verify(signed_msg, key));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_SignVerify_UsesDumber);
    return UNITY_END();
}
