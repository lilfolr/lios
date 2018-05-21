
#include "idt.h"

struct IDT_entry IDT[IDT_SIZE];

void idt_init(void) {
    unsigned long keyboard_addr;
    unsigned long idt_addr;
    unsigned long idt_ptr[2];

	/* populate IDT entry of keyboard's interrupt */
    keyboard_addr = (unsigned long)keyboard_handler;
    IDT[0x21].offset_1 = keyboard_addr & 0xffff;
    IDT[0x21].offset_2 = (keyboard_addr & 0xffff0000) >> 16;
    IDT[0x21].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
    IDT[0x21].zero = 0;
    IDT[0x21].type_attr = 0x8e; /* INTERRUPT_GATE */

    /*        Ports
	*            PIC1	PIC2
	* Command    0x20	0xA0
	* Data	     0x21	0xA1
	*/

	/* ICW1 - begin initialization */
	write_port(0x20 , 0x11);
	write_port(0xA0 , 0x11);

    /* ICW2 - remap offset address of IDT */
	/*
	* In x86 protected mode, we have to remap the PICs beyond 0x20 because
	* Intel have designated the first 32 interrupts as "reserved" for cpu exceptions
	*/

    write_port(0x21 , 0x20);
	write_port(0xA1 , 0x28);

	/* ICW3 - setup cascading */
	write_port(0x21 , 0x00);  
	write_port(0xA1 , 0x00);  

	/* ICW4 - environment info */
	write_port(0x21 , 0x01);
	write_port(0xA1 , 0x01);
	/* Initialization finished */

	/* mask interrupts */
	write_port(0x21 , 0xff);
	write_port(0xA1 , 0xff);

	/* fill the IDT descriptor */
	idt_addr = (unsigned long)IDT ;
	idt_ptr[0] = (sizeof (struct IDT_entry) * IDT_SIZE) + ((idt_addr & 0xffff) << 16);
	idt_ptr[1] = idt_addr >> 16 ;

	load_idt(idt_ptr);
}
