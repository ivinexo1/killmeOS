#include "../include/vga.h"

void main() {
  initTerminal();
  setTerminalColor(VGA_COLOR_BLACK, VGA_COLOR_WHITE);
  printString("Hello World");
  return;
}
