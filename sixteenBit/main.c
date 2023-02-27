#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    if(argc > 1) {
        uint16_t input = atoi(argv[1]);
        printf("First 8 bits = %i\nNext 8 bits = %i\n", input >> 8, input & 0xFF);
    } else {
        printf("Usage %s: [16-bit Integer]\n", argv[0]);
    }
    return 0;
}
