#include <stdio.h>
#include <stdint.h>

void decompile(const char* filename) {
    uint8_t buffer[2];
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Error: File cannot be opened\n");
        return;
    }

    while (fread(buffer, 1, 2, file) != 0) {
        uint16_t opcode = (buffer[0] << 8) | buffer[1];
        printf("0x%04X\n", opcode);
    }

    fclose(file);
}


int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: ./decomp <INPUT FILE> <OUTPUT FILE>\n");
        return 1;
    }

    decompile(argv[1]);

    return 0;
}
