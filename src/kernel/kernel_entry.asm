;;kernel.asm
bits 32                     ;tell NASM to make code for a 32bit processor
section .text
        align 4             ; dd= double word
        dd 0x1BADB002       ; magic
        dd 0x00             ; flags
        dd - (0x1BADB002 + 0x00) ; checksum

global start
global keyboard_handler
global read_port
global write_port
global load_idt

extern kmain                ; function in kernel.c. extern -> its declared elsewhere
extern keyboard_handler_main

load_idt:
	mov edx, [esp + 4]
	lidt [edx]
	sti 				;turn on interrupts
	ret

keyboard_handler:                 
	call    keyboard_handler_main
	iretd

start:
	cli                     ; disable interrupts [clear interupts]
	mov esp, stack_space    ; set stack pointer
	call kmain
	hlt
    
section .bss
resb 8192                   ; reserve 8KB for stack
stack_space:
