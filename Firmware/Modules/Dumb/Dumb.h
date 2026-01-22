#ifndef DUMB_H
#define DUMB_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

// Encrypt message with key
void Dumb_Encrypt(const char* message, const char* key, char* output, size_t buf_size);

// Decrypt message with key (XOR symmetric)
void Dumb_Decrypt(const char* message, const char* key, char* output, size_t buf_size);

// Sign message by appending key
void Dumb_Sign(const char* message, const char* key, char* output, size_t buf_size);

// Verify if message ends with key
bool Dumb_Verify(const char* message, const char* key);

#endif // DUMB_H
