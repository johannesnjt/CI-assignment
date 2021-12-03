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

}

int main(void)
{
    UNITY_BEGIN();

    return UNITY_END();
}
