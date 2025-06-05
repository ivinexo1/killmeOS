#include "../include/vga.h"
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer = (uint16_t*)VGA_MEMORY;

uint8_t setTerminalColor(enum vga_color fontColor, enum vga_color backgroundColor){
  terminal_color = (backgroundColor << 4) | fontColor;
  return 0;
}


size_t strlen(const char* str) 
{
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}
void scroll(){
   size_t index;
  for (size_t y = 0; y < VGA_HEIGHT; y++) {
    for (size_t x = 0; x < VGA_WIDTH; x++) {
      index = (VGA_WIDTH*y) + x;
      if(y < VGA_HEIGHT){
        terminal_buffer[index] = terminal_buffer[index + VGA_WIDTH];
      } else {
        terminal_buffer[index] = 0;
      }
    }
  }
}
void printChar(unsigned char c){
  if(c == '\n'){
    terminal_column = 0;
    terminal_row++;
  }else{
    size_t index = (VGA_WIDTH*terminal_row) + terminal_column;
    terminal_buffer[index] = (terminal_color << 8) | c;
    terminal_column += 1;
  }
  if(terminal_row == VGA_HEIGHT ){
    scroll();
    terminal_row--;
  }
  return;
}

void initTerminal(){
  terminal_column = 0;
  terminal_row = 0;
  terminal_color = 0x0f;
  size_t index;
  for (int x = 0 ; x < VGA_HEIGHT; x++) {
    for (int y = 0; y < VGA_WIDTH; y++) {
/*      if(x % 2 == 1)
        printChar('a');
      else
        printChar('b');
*/
      printChar(0);      
    }
  }
/*  for (int x = 0; x < (VGA_WIDTH); x++) {
    for (int y = 0; y < VGA_HEIGHT; y++) {
      index = x + (VGA_WIDTH * y);
      terminal_buffer[index] = (terminal_color << 8) | 'a';
    }
  }*/
  terminal_column = 0;
  terminal_row = 0;
}

void printString(const char* msg){
  for (size_t i = 0; i < strlen(msg); i++) {
    printChar(msg[i]);
  }
}
