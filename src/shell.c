#include "../include/vga.h"
#include "../include/ports.h"
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "../include/keyboard.h"

// ako certifikovany js dev je mi uplne jedno ze toto nebude asi dako optimalne ale idc :p

// 1 found, else 0
// i loop => checkuje kazdu starting poziciu v buffery
// j loop => checkuje kazdy char v slove
int buffer_contains_word(const int *buffer, int blength, const char *word) {
    int wlength = 0;
    while (word[wlength] != '\0') wlength++;
    for (int i = 0; i <= blength - wlength; i++) {
        int match = 1;
        for (int j = 0; j < wlength; j++) {
            if (buffer[i + j] != word[j]) { //ak sa character v keybufferi nerovna s characterom v slove == 0
                match = 0;
                break;
            }
        }
        if (match) return 1;
    }
    return 0;
}

void parse(int blength) {
    if (buffer_contains_word(keybuffer, blength, "help")) {
        printString("'help' cmd\n");
    }
    if (buffer_contains_word(keybuffer, blength, "shutdown")) {
        outw(0x604, 0x2000);
        printString("'shutdown' cmd\n");
    }
    if (buffer_contains_word(keybuffer, blength, "error")) {
      int x = 1/0;
    }
}
