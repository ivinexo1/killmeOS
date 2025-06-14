#include "../include/vga.h"
#include "../include/ports.h"
#include "../include/idt.h"
#include "../include/isr.h"
#include "../include/keyboard.h"

void main() {
  isr_install();
  printString("Hello\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nWorld");

  asm volatile("sti");
  enable_cursor(0, 15);
  setTerminalColor(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
  initTerminal();
  init_keyboard();
  //printString("killmeOS Shell v0.1");
  //asm volatile("int $32");

  
  return;

}
