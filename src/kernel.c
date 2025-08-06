#include <stdint.h>
#include "../include/vga.h"
//#include "../include/ports.h"
//#include "../include/idt.h"
//#include "../include/isr.h"
//#include "../include/keyboard.h"

void main() {
  for (int y = 0; y < 768; y++) {
    for (int x = 0; x < 1024; x++) {
      printPixel(x, y, 0x0000ff);
    }
  }
//  *(uint32_t*)framebuffer = b[0];
  uint8_t letter = 'A';
  for (int y = 0; y < 760; y += 40) {
    for (int x = 0; x < 1000; x += 40) {
      printChar(x, y, letter);
      letter++;
      if (letter == 'Z') {
        letter = 'A';
      }
    }
  }
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
