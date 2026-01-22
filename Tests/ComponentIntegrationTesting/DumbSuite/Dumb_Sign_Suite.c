#include "unity.h"
#include "Dumb.h"
#include <string.h>
#include <stdbool.h>

void setUp(void) {}
void tearDown(void) {}

void testIntegrationComponent_SignVerify(void)
{
    const char* message = "TestMessage";
    const char* key = "Key123";
    char signed_msg[256] = {0};

    // Sign
    Dumb_Sign(message, key, signed_msg, sizeof(signed_msg));
    TEST_ASSERT_TRUE(strcmp(message, signed_msg) != 0); // signature modifie le message

    // Verify
    bool valid = Dumb_Verify(signed_msg, key);
    TEST_ASSERT_TRUE(valid);

    // Test avec message modifié -> should fail
    size_t len = strlen(signed_msg);
    signed_msg[len-1] ^= 0xFF; // corrompre le checksum à la fin
    TEST_ASSERT_FALSE(Dumb_Verify(signed_msg, key));
}


int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(testIntegrationComponent_SignVerify);
    return UNITY_END();
}
