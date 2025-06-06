#include "../include/vga.h"
#include "../include/idt.h"
#include "../include/isr.h"

void isr_install() {
  set_idt_gate(0, (uint32_t) isr0);
  
  load_idt();
}

char *exeption_msg[] = {
  "Division by 0"
};

void isr_handler(registers_t *r){
  setTerminalColor(VGA_COLOR_WHITE, VGA_COLOR_BLUE);
  initTerminal();
  printString(exeption_msg[r->int_no]);
  asm volatile("hlt");
}
