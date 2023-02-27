#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct Command {
    uint8_t commandHex;
    uint8_t args[16];
    uint8_t argCount;
} Command;

Command createCommand(uint8_t command, uint8_t args[16], uint8_t count) {
    Command c;
    c.commandHex = command;
    memcpy(c.args, args, 16);
    c.argCount = count;
    return c;
}

void printCommand(Command c) {
    printf("Command:\t%i\n", c.commandHex);
    for(int i = 0; i < c.argCount; i++) {
        printf("%i\n", c.args[i]);
    }
}

int main(void) {
    uint8_t a[] = {0x61, 0x03};
    Command c = createCommand(0x01, a, 3);
    printCommand(c);
    return 0;
}
