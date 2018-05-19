all: kernel

deploy: kernel
	sudo cp out/kernel-001 /boot 

kernel: kc.o kasm.o
	ld -m elf_i386 -T link.ld -o out/kernel-001 out/kasm.o out/kc.o

kc.o:
	gcc -m32 -c kernel.c -o out/kc.o

kasm.o:
	nasm -f elf32 kernel.asm -o out/kasm.o

clean:
	rm -f out/*