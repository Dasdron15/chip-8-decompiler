#include <stdio.h>
#include <stdint.h>

void decompile(const char* inputname, const char* outputname) {
    uint8_t buffer[2];
    FILE *input = fopen(inputname, "rb");
    FILE * output = fopen(outputname, "w");

    if (input == NULL || output == NULL) {
        printf("Error: File cannot be opened\n");
        return;
    }

    while (fread(buffer, 1, 2, input) != 0) {
        uint16_t opcode = (buffer[0] << 8) | buffer[1];
        fprintf(output, "0x%04X\n", opcode);
    }

    fclose(input);
    fclose(output);
}


int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: ./decomp <INPUT_FILE> <OUTPUT_FILE>\n");
        return 1;
    }
    decompile(argv[1], argv[2]);
    
    printf("File decompiled successfully!\n");
    return 0;
}
