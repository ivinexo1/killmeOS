#include "../include/vga.h"
#include "../include/ports.h"
#include "../include/idt.h"
#include "../include/isr.h"
#include "../include/keyboard.h"

void main() {
  isr_install();
  asm volatile("sti");
  enable_cursor(0, 15);
  setTerminalColor(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
  initTerminal();
  init_keyboard();
  printString("killmeOS Shell\nCopyright (c) 2025 killmeOS dev under MIT License\nSHELL> ");
  //asm volatile("int $32");
  
  return;

}
