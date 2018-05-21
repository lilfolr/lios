#ifndef IDT_H
#define IDT_H

#include "types.h"

#define IDT_SIZE 256
#define KERNEL_CS 0x08

extern void keyboard_handler(void);

// Interrupt Descriptor Table
struct idt_gate_t{
    unsigned short int offset_low; // offset bits 0..15
    unsigned short int selector; // a code segment selector in GDT or LDT
    unsigned char zero;			 // unused, set to 0
    unsigned char type_attr;	 // type and attributes
    unsigned short int offset_high; // offset bits 16..31
};

struct idt_register_t{
    u16 limit;
    u32 base;
};
typedef struct idt_gate_t idt_gate_t;
typedef struct idt_register_t idt_register_t;

struct idt_gate_t idt[IDT_SIZE];
struct idt_register_t idt_reg;


void set_idt_gate(int n, u32 handler);
void set_idt(void);

#endif // IDT_H
