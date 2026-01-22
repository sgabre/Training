#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include <Dumb.h>

// Convert hex string to bytes
void hex_to_bytes(const char* hex, uint8_t* out, size_t* out_len)
{
    size_t len = strlen(hex);
    size_t j = 0;

    for (size_t i = 0; i < len; i += 2)
    {
        unsigned int val;
        if (sscanf(hex + i, "%2X", &val) != 1)
            break; // stop on invalid hex
        out[j++] = (uint8_t)val;
    }

    *out_len = j;
}

// Convert bytes to hex string
void bytes_to_hex(const uint8_t* bytes, size_t len, char* out, size_t out_size)
{
    size_t pos = 0;
    for (size_t i = 0; i < len && (pos + 2) < out_size; i++)
    {
        pos += snprintf(out + pos, out_size - pos, "%02X", bytes[i]);
    }
    out[pos] = '\0';
}

int main(int argc, char* argv[])
{
    if (argc != 5) 
    {
        printf("Usage:\n");
        printf("  %s -e <message> -k <key>\n", argv[0]);
        printf("  %s -d <hex_message> -k <key>\n", argv[0]);
        printf("  %s -s <message> -k <key>\n", argv[0]);
        printf("  %s -v <message> -k <key>\n", argv[0]);
        return 1;
    }

    const char* option = argv[1];
    const char* input = argv[2];
    const char* key_flag = argv[3];
    const char* key = argv[4];

    if (strcmp(key_flag, "-k") != 0) 
    {
        printf("Error: missing -k flag\n");
        return 1;
    }

    if (strcmp(option, "-e") == 0) 
    {
        printf("Original Message: %s\n", input);
        printf("Key: %s\n", key);

        uint8_t encrypted[256];
        Dumb_Encrypt(input, key, (char*)encrypted, sizeof(encrypted));

        char hex_output[512];
        bytes_to_hex(encrypted, strlen(input), hex_output, sizeof(hex_output));

        printf("Encrypted Message (hex): %s\n", hex_output);
    }
    else if (strcmp(option, "-d") == 0) 
    {
        printf("Encrypted Message (hex): %s\n", input);
        printf("Key: %s\n", key);

        uint8_t encrypted[256];
        size_t enc_len = 0;
        hex_to_bytes(input, encrypted, &enc_len);

        uint8_t decrypted[256];
        Dumb_Decrypt((char*)encrypted, key, (char*)decrypted, sizeof(decrypted));

        printf("Decrypted Message: ");
        for (size_t i = 0; i < enc_len; i++)
            printf("%c", decrypted[i]);
        printf("\n");
    }
    else if (strcmp(option, "-s") == 0) 
    {
        printf("Signature Computation\n");
        printf("Encrypted Message (hex): %s\n", input);
        printf("Key: %s\n", key);
        char signature[256];
        Dumb_Sign(input, key, signature, sizeof(signature));
        printf("Signature: %s\n", signature);
    }
    else if (strcmp(option, "-v") == 0) 
    {
        printf("Signature Verification\n");
        printf("Encrypted Message (hex): %s\n", input);
        printf("Key: %s\n", key);
        bool valid = Dumb_Verify(input, key);
        printf("Signature is %s\n", valid ? "Valid" : "Invalid");
    }
    else 
    {
        printf("Unknown option: %s\n", option);
        return 1;
    }

    return 0;
}
