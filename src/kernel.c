#include "../include/vga.h"
#include "../include/idt.h"
#include "../include/isr.h"

void main() {
  isr_install();
  asm volatile("sti");
  enable_cursor(0, 15);
  setTerminalColor(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
  initTerminal();
  printString("Hello\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nWorld");
  asm volatile("int $0x1f");
  asm volatile("cli");
  
  return;

}
