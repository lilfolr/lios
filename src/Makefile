ROOT_DIR:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))
CC = gcc -m32 -fno-stack-protector -Wno-implicit-function-declaration -I$(ROOT_DIR)
SRCS = $(wildcard drivers/*/*.c)
PROGS = $(patsubst %.c,%,$(SRCS))
OBJS = $(SRCS:.c=.o)

.PHONY: clean all

all: kernel

deploy: kernel
	sudo cp out/kernel-001 /boot 

kernel: kc.o kasm.o $(PROGS)
	ld -m elf_i386 -T link.ld -o out/kernel-001 out/kasm.o out/kc.o $(addprefix out/,$(OBJS))

%: %.c
	$(CC) -c -o out/$@.o $<

kc.o:
	$(CC) -c kernel/kernel.c -o out/kc.o

kasm.o: setup_dir
	nasm -f elf32 kernel/kernel.asm -o out/kasm.o

setup_dir:
	mkdir -p out/drivers/io

clean:
	rm -rf out/*
