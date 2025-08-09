#include "../include/terminal.h"
#include "../include/vga.h"
#include "../include/string.h"
#include "./font.c"
#include <stdint.h>

uint32_t current_X = 0;
uint32_t current_Y = 0;
uint8_t buffer[475];

void putChar(uint8_t letter){
  if (letter == ' ') {
    current_X++;
  }else if (letter == '\n') {
    current_Y++;
  }else {

    uint32_t letterindex = 0;
    if (letter >= 65 && letter <= 90) {
      letter -= 55;
    } else if (letter <= 57){
      letter -= 48;
    } else {
      letter -= 61;
    }
    for (int j = 0; j < 40; j++) {
      for (int i = 0; i < 40; i++) {
        if (font3_data[letter][letterindex]) {
          printPixel(current_X*40 + i, current_Y*40 + j, 0xffffff);
        } else {
          printPixel(current_X*40 + i, current_Y*40 + j, 0x0000ff);
        }
        letterindex++;
      }
    }
    current_X++;
  }
  return;
}

void printChar(uint8_t letter){
  buffer[current_X + current_Y*25] = letter;
  putChar(letter);
  if (current_X >= 25) {
    current_X = 0;
    current_Y++;
  }
  if (current_Y >= 20) {
    current_X = 0;
    current_Y = 0;
    for (int i = 0; i < 475; i++) {
      if (i < 456) {
        buffer[i] = buffer[i+25];
      } else {
        buffer[i] = 0;
      }
    }
    for (int i = 0; i < 474; i++) {
      putChar(buffer[i]);
    }
    current_X = 0;
    current_Y = 18;
  }
  return;
}

int printString(char *string){
  for (uint32_t n = 0; n < strlen(string); n++) {
    printChar(string[n]);
  }
  return 0;
}
