// Dumber.h
#ifndef DUMBER_H
#define DUMBER_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

void Dumber_XOR_Buffer(const uint8_t* input, size_t len, const char* key, uint8_t* output);
void Dumber_HexEncode(const uint8_t* input, size_t len, char* output, size_t buf_size);
bool Dumber_Checksum_Verify(const uint8_t* message, size_t len, const char* key);
uint8_t Dumber_Checksum_Compute(const uint8_t* message, size_t len, const char* key);

#endif // DUMBER_H