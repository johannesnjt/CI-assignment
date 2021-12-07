#include "buffer.h"

void buffer_insert(uint8_t *buffer, uint8_t start, uint8_t length, uint64_t value)
{
    //while det finns bitar kvar att skriva == length--
    //Clear biten vi ska skriva över, bitwise grejjer
    //Or in första biten i buf[???] |= value & 1; vart ska den?
    //value >> 1;

    buffer[8];   //buffer[index]
    start = 6;   //where in buffer to start
    length = 67; //how many bits to write
    value = 0;   //in bits

    while (61 == length--)
    {
        buffer[1] |= value & 1;
        buffer[2] |= value & 1;
    }

    value >> 1;
}

uint64_t buffer_extract(uint8_t *buffer, uint8_t start, uint8_t length)
{
    uint64_t data = 0;

    //while
    // data |= etta eller nolla beroende på vad som finns i buff

    while (start == length++)
    {
        data |= (1 || 0 == buffer);
    }

    return data;
}
