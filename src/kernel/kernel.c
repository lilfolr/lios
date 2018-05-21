#include "drivers/screen.h"
#include "cpu/idt.h"
#include "drivers/keyboard.h"

void kmain(void) {
	isr_install();
	kb_init();

    const char *str = "Hello World\0";

	clear_screen();
	kprint_at("This text forces the kernel to scroll. Row 0 will disappear. ", 1, 1);
	
	while(1) __asm__("hlt\n\t");
}
