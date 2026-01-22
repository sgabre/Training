#include <unity.h>
#include <Dummy.h> // prototype de Dummy_PublicFunction
#include <stdint.h>
#include <stdbool.h>

void setUp(void) {}
void tearDown(void) {}

// Test si la valeur paire renvoie true
void test_Dummy_PublicFunction_IsZeroEven(void)
{
    TEST_ASSERT_TRUE(Dummy_PublicFunction(0));   // 0 est pair
}
// Test si la valeur paire renvoie true
void test_Dummy_PublicFunction_even(void)
{
    TEST_ASSERT_TRUE(Dummy_PublicFunction(2));
}

// Test si la valeur impaire renvoie false
void test_Dummy_PublicFunction_odd(void)
{
    TEST_ASSERT_FALSE(Dummy_PublicFunction(1));
}

// Test valeurs limites int8_t
void test_Dummy_PublicFunction_LowerLimitlimits(void)
{
    TEST_ASSERT_TRUE(Dummy_PublicFunction(INT8_MIN));   // -128 est pair
}

void test_Dummy_PublicFunction_UpperLimitlimits(void)
{
    TEST_ASSERT_FALSE(Dummy_PublicFunction(INT8_MAX));  // 127 est impair
}

// Main pour lancer les tests
int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_Dummy_PublicFunction_IsZeroEven);
    RUN_TEST(test_Dummy_PublicFunction_even);
    RUN_TEST(test_Dummy_PublicFunction_odd);
    RUN_TEST(test_Dummy_PublicFunction_LowerLimitlimits);
    RUN_TEST(test_Dummy_PublicFunction_UpperLimitlimits);
    return UNITY_END();
}
