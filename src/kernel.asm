;;kernel.asm
bits 32                     ;tell NASM to make code for a 32bit processor
section .text
        align 4             ; dd= double word
        dd 0x1BADB002       ; magic
        dd 0x00             ; flags
        dd (0x1BADB002 + 0x00) ; checksum

global start
extern kmain                ; function in kernel.c. extern -> its declared elsewhere

start:
    cli                     ; disable interrupts [clear interupts]
    mov esp, stack_space    ; set stack pointer
    call kmain
    hlt                     ; halt
    
section .bss
resb 8192                   ; reserve 8KB for stack
stack_space:
