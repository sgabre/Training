// Dumber.c
#include "Dumber.h"

#include <string.h>
#include <stdio.h>

void Dumber_XOR_Buffer(const uint8_t* input, size_t len, const char* key, uint8_t* output)
{
    size_t key_len = strlen(key);
    for (size_t i = 0; i < len; i++)
        output[i] = input[i] ^ key[i % key_len];
}

void Dumber_HexEncode(const uint8_t* input, size_t len, char* output, size_t buf_size)
{
    size_t max_len = buf_size / 2 < len ? buf_size / 2 : len;
    for (size_t i = 0; i < max_len; i++)
        sprintf(output + i * 2, "%02X", input[i]);
}

uint8_t Dumber_Checksum_Compute(const uint8_t* message, size_t len, const char* key)
{
    uint8_t checksum = 0;
    size_t key_len = strlen(key);
    for (size_t i = 0; i < len; i++)
        checksum ^= message[i];
    for (size_t i = 0; i < key_len; i++)
        checksum ^= key[i];
    return checksum;
}

bool Dumber_Checksum_Verify(const uint8_t* message, size_t len, const char* key)
{
    if (len < 1) return false;
    uint8_t expected = Dumber_Checksum_Compute(message, len-1, key);
    return message[len-1] == expected;
}
