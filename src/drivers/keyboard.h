#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include "../cpu/types.h"
#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64
#define IDT_SIZE 256
#define INTERRUPT_GATE 0x8e
#define KERNEL_CODE_SEGMENT_OFFSET 0x08

#define ENTER_KEY_CODE 0x1C

void kb_init(void);
void keyboard_handler_main(void);

#endif
