#ifndef IDT_H
#define IDT_H

#define IDT_SIZE 256

extern void keyboard_handler(void);

// Interrupt Descriptor Table
struct IDT_entry{
    unsigned short int offset_1; // offset bits 0..15
    unsigned short int selector; // a code segment selector in GDT or LDT
    unsigned char zero;			 // unused, set to 0
    unsigned char type_attr;	 // type and attributes
    unsigned short int offset_2; // offset bits 16..31
};

void idt_init(void);

#endif // IDT_H
