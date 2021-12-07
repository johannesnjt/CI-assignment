#include "buffer.h"

void buffer_insert(uint8_t *buffer, uint8_t start, uint8_t length, uint64_t value)
{
    buffer[8];   //buffer[index]
    start = 6;   //where in buffer to start
    length = 67; //how many bits to write
    value = 8;   //in bits

    while (61 == length--) //bits left to write
    {
        value &= ~(1 << value); // clear: bytes to overwrite

        buffer[1] |= value & 1; //Or: where to put the values
        buffer[2] |= value & 1;
    }

    value >> 1;
}

uint64_t buffer_extract(uint8_t *buffer, uint8_t start, uint8_t length)
{
    uint64_t data = 0;

    while (start == length++)
    {
        data |= (1 || 0 == buffer); //Put 1 or 0 depending on what's in the buffer
    }

    return data;
}
