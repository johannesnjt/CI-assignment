#include "unity.h"
#include "buffer.h"

void setUp(void)
{
    uint8_t array[8] = {0};
    buffer_insert(array, 6, 10, 67);
}

void tearDown(void) {}

void test_buffer_module(void)
{
    uint8_t array[8] = {0};

    uint8_t value = 67;
    buffer_insert(array, 6, 10, value);
    TEST_ASSERT_EQUAL_UINT8(value, buffer_extract(array, 6, 10));

    value = 24;
    buffer_insert(array, 6, 10, value);
    TEST_ASSERT_EQUAL_UINT8(value, buffer_extract(array, 6, 10));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_buffer_module);

    return UNITY_END();
}
