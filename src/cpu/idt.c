
#include "idt.h"

struct idt_gate_t IDT[IDT_SIZE];

void set_idt_gate(int n, u32 handler) {
    idt[n].offset_low = low_16(handler);
    idt[n].selector = KERNEL_CS;
    idt[n].zero = 0;
    idt[n].type_attr = 0x8E; 
    idt[n].offset_high = high_16(handler);
}

void set_idt() {
    idt_reg.base = (u32) &idt;
    idt_reg.limit = IDT_SIZE * sizeof(idt_gate_t) - 1;
    /* Don't make the mistake of loading &idt -- always load &idt_reg */
    __asm__ __volatile__("lidtl (%0)" : : "r" (&idt_reg));
};
