#include "../include/vga.h"

void main() {
  initTerminal();
  setTerminalColor(VGA_COLOR_BLACK, VGA_COLOR_WHITE);
  printString("Hello\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nWorld");
//  for (int i = 0xb8000; i < 0xc0000; i = i+2) {
//   *(char*)i = 'A';
//  }
  return;
}
