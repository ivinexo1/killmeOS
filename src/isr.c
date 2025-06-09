#include "../include/vga.h"
#include "../include/idt.h"
#include "../include/isr.h"

void isr_install() {
  set_idt_gate(0, (uint32_t) isr0);
  // ... asi tu treba definovat aj tie ostatne isr [myslim]  

  // defautsky je prvych 8 IRQ mapped na prvych 8 gates
  // takze kvoli tomu aby tam neboli issues vraj musime
  // remappnut PIC alebo daco :V

  // main PIC ~ 0x20 command ~ 0x21 data
  // sec. PIC ~ 0xA0 command ~ 0xA1 data

  // initialization commands [ICW] : https://www.thesatya.com/8259.html

  // main PIC
  set_idt_gate(32, (uint32_t)irq0);
  set_idt_gate(33, (uint32_t)irq1);
  set_idt_gate(34, (uint32_t)irq2);
  set_idt_gate(35, (uint32_t)irq3);
  set_idt_gate(36, (uint32_t)irq4);
  set_idt_gate(37, (uint32_t)irq5);
  set_idt_gate(38, (uint32_t)irq6);
  set_idt_gate(39, (uint32_t)irq7);

  // secondary PIC
  set_idt_gate(40, (uint32_t)irq8);
  set_idt_gate(41, (uint32_t)irq9);
  set_idt_gate(42, (uint32_t)irq10);
  set_idt_gate(43, (uint32_t)irq11);
  set_idt_gate(44, (uint32_t)irq12);
  set_idt_gate(45, (uint32_t)irq13);
  set_idt_gate(46, (uint32_t)irq14);
  set_idt_gate(47, (uint32_t)irq15);

  // ICW1
  port_byte_out(0x20, 0x11);
  port_byte_out(0xA0, 0x11);
  // ICW2
  port_byte_out(0x21, 0x20);
  port_byte_out(0xA1, 0x28);
  // ICW3
  port_byte_out(0x21, 0x04);
  port_byte_out(0xA1, 0x02);
  // ICW4
  port_byte_out(0x21, 0x01);
  port_byte_out(0xA1, 0x01);
  // OCW1
  port_byte_out(0x21, 0x0);
  port_byte_out(0xA1, 0x0);
  
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
