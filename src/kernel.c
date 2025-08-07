#include <stdint.h>
#include "../include/vga.h"
#include "../include/string.h"
#include "../include/ports.h"
#include "../include/idt.h"
#include "../include/isr.h"
//#include "../include/keyboard.h"

void main() {
  for (int y = 0; y < 768; y++) {
    for (int x = 0; x < 1024; x++) {
      printPixel(x, y, 0, 0, 255);
    }
  }
  uint32_t index = 0;
  static char string[] = "HELLO WORLD HOW ARE YOU 012345679";
  printString(string);
  isr_install();
  asm volatile("sti");
/*  setTerminalColor(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
  initTerminal();
  init_keyboard();
  printString("killmeOS Shell\nCopyright (c) 2025 killmeOS dev under MIT License\nSHELL> ");
*/
//  asm volatile("int $32");
//  int x = 1/0;

//  asm volatile("cli");

  return;

}
