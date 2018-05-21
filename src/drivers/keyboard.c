#include "keyboard.h"
#include "keyboard_map.h"
#include "screen.h"
#include "ports.h"
#include "../cpu/isr.h"

void keyboard_handler_main(void)
{
	unsigned char status;
	char keycode;

	/* write EOI */
	write_port(0x20, 0x20);

	status = read_port(KEYBOARD_STATUS_PORT);
	/* Lowest bit of status will be set if buffer is not empty */
	if (status & 0x01) {
		keycode = port_byte_in(KEYBOARD_DATA_PORT);
		char* letter;
		letter = get_letter(keycode);
		kprint(letter);
		kprint("\n");
	}
}

void kb_init() {
   register_interrupt_handler(IRQ1, keyboard_handler_main); 
}
