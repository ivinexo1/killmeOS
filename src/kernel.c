#include "../include/vga.h"
#include "../include/idt.h"
#include "../include/isr.h"

void main() {
  isr_install();
  initTerminal();
  setTerminalColor(VGA_COLOR_BLACK, VGA_COLOR_WHITE);
  printString("Hello\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nWorld");
/*  asm volatile("mov %eax, 5");
  asm volatile("mov %ebx, 0"); 
  asm volatile("div %ebx");*/
  asm volatile("sti");
  int x = 1/0;
  return;

}
