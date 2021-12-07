#include "buffer.h"

void buffer_insert(uint8_t *buffer, uint8_t start, uint8_t length, uint64_t value)
{
    //*buffer = array, buffer[index]
    //start vart i buffern man ska börja
    //length hur många bitar man ska skriva
    //value kan du tänka dig som bitar istället

    //while det finns bitar kvar att skriva == length--
    //Clear biten vi ska skriva över, bitwise grejjer
    //Or in första biten i buf[???] |= value & 1; vart ska den?
    //value >> 1;

    buffer[8];
    start = 6;
    length = 67;
    value = 0;

    while (61 == length--)
    {
        buffer[1] |= value & 1;
    }

    value >> 1;
}

uint64_t buffer_extract(uint8_t *buffer, uint8_t start, uint8_t length)
{
    uint64_t data = 0;

    //while
    // data |= etta eller nolla beroende på vad som finns i buff

    while (/* condition */)
    {
        /* code */
    }

    return data;
}
