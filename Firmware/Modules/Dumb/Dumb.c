#include "Dumb.h"
#include <stdint.h>
#include <string.h>

// -------------------- XOR Encryption --------------------
void Dumb_Encrypt(const char* message, const char* key, char* output, size_t buf_size)
{
    if (!message || !key || !output) return;

    size_t msg_len = strlen(message);
    size_t key_len = strlen(key);
    if (key_len == 0) return;

    if (msg_len >= buf_size) msg_len = buf_size - 1;

    for (size_t i = 0; i < msg_len; i++) {
        output[i] = (char)((uint8_t)message[i] ^ (uint8_t)key[i % key_len]);
    }
    output[msg_len] = '\0';
}

void Dumb_Decrypt(const char* message, const char* key, char* output, size_t buf_size)
{
    // XOR symmetric
    Dumb_Encrypt(message, key, output, buf_size);
}

// -------------------- Signing --------------------
void Dumb_Sign(const char* message, const char* key, char* output, size_t buf_size)
{
    if (!message || !key || !output) return;

    size_t msg_len = strlen(message);
    size_t key_len = strlen(key);

    if (msg_len >= buf_size) msg_len = buf_size - 1;

    // Copy message
    memcpy(output, message, msg_len);

    // Copy key (truncate if needed)
    size_t max_key_len = buf_size - msg_len - 1;
    if (key_len > max_key_len) key_len = max_key_len;
    memcpy(output + msg_len, key, key_len);

    output[msg_len + key_len] = '\0';
}

// -------------------- Verification --------------------
bool Dumb_Verify(const char* message, const char* key)
{
    if (!message || !key) return false;

    size_t msg_len = strlen(message);
    size_t key_len = strlen(key);

    if (msg_len < key_len) return false;

    return (memcmp(message + msg_len - key_len, key, key_len) == 0);
}
