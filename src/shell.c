#include "../include/vga.h"
#include "../include/ports.h"
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "../include/keyboard.h"

int parsedShell() {
    int wlength = 0;
    char word[256];
    int words_count = 0;
    char *words[256];
    // find length of the word [until whitespace]
    while (keybuffer[wlength] == ' ' || keybuffer[wlength] == '\n' || keybuffer[wlength] == '\0' || keybuffer[wlength] == '\t') {
        wlength++;
    }
    // keybuffer => word
    for (int i = 0; i < wlength; i++) {
        word[i] = keybuffer[i];
    }
    word[wlength] = '\0';
    words[words_count] = word;
    words_count++;
    for (int i = 0; i < wlength; i++) {
        word[i] = '\0';
    }

    // now multiple words D:
    int j = 0;
    words_count = 0;
    while (keybuffer[j] != '\0') {
        // skip whitespace
        while (keybuffer[j] == ' ' || keybuffer[j] == '\n' || keybuffer[j] == '\t') j++;
        if (keybuffer[j] == '\0') break;
        words[words_count++] = &keybuffer[j];
        // move to end of word
        while (keybuffer[j] != ' ' && keybuffer[j] != '\n' && keybuffer[j] != '\t' && keybuffer[j] != '\0') j++;
        if (keybuffer[j] != '\0') {
            keybuffer[j] = '\0';
            j++;
        }
    }

    // printString(words[1]); <-- DEBUG
    cmd();
}

// robil som tuto blbost na mobile testovat to budem neskor

void cmd() {
    switch (words[0]) {
        case "sys":
            break;
        case "pacman": // <-- RENAME
            break;
        default:
            break;
   }
}