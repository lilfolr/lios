#include "drivers/io/screen.h"
#include "drivers/io/idt.h"
#include "drivers/io/keyboard.h"

void kmain(void) {
	idt_init();
	kb_init();

    const char *str = "Hello World\0";

	clear_screen();
	kprint(str);
	
	while(1) __asm__("hlt\n\t");
}
