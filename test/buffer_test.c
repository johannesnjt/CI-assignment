#include "unity.h"
#include "buffer.h"

void setUp(void)
{
    uint8_t array[8] = {0};
    buffer_insert(array, 23, 6, 88);
}

void tearDown(void) {}

void test_buffer_module(void)
{
    uint8_t array[8] = {23, 6, 88};

    TEST_ASSERT_EQUAL_UINT8(2, list_nth_data(1));
    TEST_ASSERT_EQUAL_UINT8(8, list_nth_data(2));
    TEST_ASSERT_EQUAL_UINT8(10, list_nth_data(3));
    TEST_ASSERT_EQUAL_UINT8(10, list_nth_data(4));
    TEST_ASSERT_EQUAL_UINT8(20, list_nth_data(5));

    TEST_ASSERT_EQUAL_size_t(5, list_available());

    TEST_ASSERT_EQUAL_UINT8(0, list_nth_data(0));
    TEST_ASSERT_EQUAL_UINT8(0, list_nth_data(10));

    /*list_clear();
    TEST_ASSERT_EQUAL_size_t(0, list_available());*/
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_buffer_module);

    return UNITY_END();
}
