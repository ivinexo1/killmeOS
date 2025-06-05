#include "../include/vga.h"
#include <stdint.h>
#include <stddef.h>


size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer = (uint16_t*)VGA_MEMORY;

uint8_t setTerminalColor(enum vga_color fontColor, enum vga_color backgroundColor){
  terminal_color = (backgroundColor << 4) | fontColor;
  return 0;
}

void printChar(unsigned char c){
  const uint8_t index = VGA_WIDTH*terminal_row + terminal_column;
  terminal_buffer[index] = (terminal_color << 8) | c;
  terminal_column++;
}

void initTerminal(){
  terminal_column = 0;
  terminal_row = 0;
  terminal_color = 0x0f;
  for ( ; terminal_row < VGA_HEIGHT; terminal_row++) {
    for (; terminal_column < VGA_WIDTH; terminal_column++) {
      printChar(0);
    }
  }
  terminal_column = 0;
  terminal_row = 0;
}




void printString(const char*);


