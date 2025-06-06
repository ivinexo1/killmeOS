#include "../include/vga.h"
#include "../include/idt.h"
#include "../include/isr.h"

void main() {
  isr_install();
  asm volatile("sti");
  enable_cursor(0, 15);
  setTerminalColor(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
  initTerminal();
//  update_cursor(0);
  printString("Hello\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nWorld");
//  int x = 1/0;
  asm volatile("cli");
  
  return;

}
