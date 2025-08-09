#include <stdint.h>
#include "../include/vga.h"
#include "../include/string.h"
#include "../include/ports.h"
#include "../include/idt.h"
#include "../include/isr.h"
#include "../include/keyboard.h"
#include "../include/terminal.h"

void main() {
  for (int y = 0; y < 768; y++) {
    for (int x = 0; x < 1024; x++) {
      printPixel(x, y, 0x0000ff);
    }
  }
  uint8_t string[475];
  for (int i = 0; i < 472; i++) {
    string[i] = 'A';
  }
  string[473] = 0;
//  printString(string);
  isr_install();
  asm volatile("sti");
  init_keyboard();
//  asm volatile("int $32");
//  int x = 1/0;

//  asm volatile("cli");

  return;

}
