#include <stdint.h>
#include "../include/vga.h"
#include "../include/string.h"
//#include "../include/ports.h"
//#include "../include/idt.h"
//#include "../include/isr.h"
//#include "../include/keyboard.h"

void main() {
  for (int y = 0; y < 768; y++) {
    for (int x = 0; x < 1024; x++) {
      printPixel(x, y, 0, 0, 255);
    }
  }
  uint32_t index = 0;
  static char string[] = "HELLO WORLDHASFHJGDFHJ";
  for (int y = 0; y < 40; y += 40) {
    for (int x = 0; x < 40*strlen(string); x += 40) {
      if (string[index] != 32) {
        printChar(x, y, string[index]);
      }
      index++;
    }
  }
//  printChar(0, 0, 'A');
/*  isr_install();
  asm volatile("sti");
  enable_cursor(0, 15)k
  setTerminalColor(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
  initTerminal();
  init_keyboard();
  printString("killmeOS Shell\nCopyright (c) 2025 killmeOS dev under MIT License\nSHELL> ");
  //asm volatile("int $32");
*/
  return;

}
