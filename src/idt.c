#include <stdint.h>
#include "../include/idt.h"

// interrupt descriptor table
// IDT ~ 256 gates each 8 bytes

idt_gate_t idt[IDT_ENTRIES];

void set_idt_gate(int n, uint32_t handler) {
    idt[n].low_offset = low_16(handler);
    idt[n].selector = 0x08;
    idt[n].always0 = 0;
    idt[n].flags = 0x8E;
    idt[n].high_offset = high_16(handler);
}