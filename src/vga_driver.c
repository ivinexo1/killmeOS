#include "../include/vga.h"
#include "../include/ports.h"
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


void enable_cursor(uint8_t cursor_start, uint8_t cursor_end)
{
	outb(0x3D4, 0x0A);
	outb(0x3D5, (inb(0x3D5) & 0xC0) | cursor_start);

	outb(0x3D4, 0x0B);
	outb(0x3D5, (inb(0x3D5) & 0xE0) | cursor_end);
  return;
}

void disable_cursor()
{
	outb(0x3D4, 0x0A);
	outb(0x3D5, 0x20);
  return;
}

void update_cursor(uint16_t pos)
{

	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint8_t) (pos & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
  return;
}

uint16_t get_offset(int x, int y) {
  uint16_t pos = y * VGA_WIDTH + x;
  return pos;
}

uint16_t get_cursor_position(void)
{
    uint16_t pos = 0;
    outb(0x3D4, 0x0F);
    pos |= inb(0x3D5);
    outb(0x3D4, 0x0E);
    pos |= ((uint16_t)inb(0x3D5)) << 8;
    return pos;
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
    uint16_t linepos = get_cursor_position() % VGA_WIDTH;
    update_cursor(get_cursor_position() + VGA_WIDTH - linepos);
  }else if (c == '\r') {
    if (terminal_column == 0) {
      terminal_column = VGA_WIDTH;
      terminal_row--;
    }
    size_t index = (VGA_WIDTH*terminal_row) + terminal_column - 1;
    terminal_buffer[index] = (terminal_color << 8) | 0;
    terminal_column--;

    update_cursor(get_cursor_position() - 1);
  }else{
    size_t index = (VGA_WIDTH*terminal_row) + terminal_column;
    terminal_buffer[index] = (terminal_color << 8) | c;
    terminal_column += 1;
    update_cursor(get_cursor_position() + 1);
  }
  if(terminal_column == VGA_WIDTH){
    terminal_column = 0;
    terminal_row++;
  }
  if(terminal_row == VGA_HEIGHT ){
    scroll();
    terminal_row--;
    update_cursor(get_cursor_position() - VGA_WIDTH);
  }
  return;
}

void initTerminal(){
  terminal_column = 0;
  terminal_row = 0;
  size_t index;
  for (int x = 0 ; x < VGA_WIDTH; x++) {
    for (int y = 0; y < VGA_HEIGHT; y++) {
      index = (VGA_WIDTH*y) + x;
      terminal_buffer[index] = (terminal_color << 8) | 0;
    }
  }
  terminal_column = 0;
  terminal_row = 0;
  update_cursor(0);
}

void printString(const char* msg){
  for (size_t i = 0; i < strlen(msg); i++) {
    printChar(msg[i]);
  }
}
void shellPrompt() {
  printString("<killmeOS> ~ ");
  get_cursor_position() + 14;
  return;
}
