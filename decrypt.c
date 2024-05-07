#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
void xor_decrypt(const char* input_filename, const char* output_filename);

int main() {
    xor_decrypt("Java.dll", "DecJava.dll");
    return 0; }

void xor_decrypt(const char* input_filename, const char* output_filename) {
    FILE* input_file = fopen(input_filename, "rb");
    FILE* output_file = fopen(output_filename, "wb");
    if (input_file == NULL || output_file == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }

    // Read input file size
    fseek(input_file, 0, SEEK_END);
    long file_size = ftell(input_file);
    rewind(input_file);

    // Allocate buffer to hold file contents
    char* buffer = (char*)malloc(file_size);
    if (buffer == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }

    // Read entire file into buffer
    size_t bytes_read = fread(buffer, 1, file_size, input_file);
    if (bytes_read != file_size) {
        printf("Error reading file.\n");
        exit(1);
    }

    // Decryption
    // XOR each first byte with 0x81 and each second byte with 0x53
    char first, second;
    for (int i = 0; i < bytes_read; i += 2) {
        first=buffer[i];
        first ^= 0x81;
        buffer[i] = first;
        second = buffer[i+1];
        second ^= 0x53;
        buffer[i + 1] = second;
    }

    // Write decrypted buffer to DecJava.dll
    fwrite(buffer, 1, bytes_read, output_file);

    // Cleanup
    free(buffer);
    fclose(input_file);
    fclose(output_file);
}
