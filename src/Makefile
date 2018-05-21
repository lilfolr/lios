ROOT_DIR:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))
CC = gcc 
CFLAGS = -g -m32 -fno-stack-protector -Wno-implicit-function-declaration -I$(ROOT_DIR)
SRCS = $(wildcard kernel/*.c drivers/*.c cpu/*.c)
HEADERS = $(wildcard kernel/*.h drivers/*.h cpu/*.h)
PROGS = $(patsubst %.c,%,$(SRCS))
OBJS = ${SRCS:.c=.o}

.PHONY: clean all

all: kernel

deploy: kernel
	sudo cp _out/kernel-001 /boot 

kernel: $(OBJS) _out/kernel/kernel.o
	ld -m elf_i386 -T link.ld -o $(addprefix _out/,$(OBJS)) _out/cpu/interrupt.o

%.o: %.c $(HEADERS) setup_dir
	$(CC) $(CFLAGS) -c -o _out/$@ $<

%.o: %.asm setup_dir
	nasm $< -f elf -o _out/$@

setup_dir:
	mkdir -p _out/drivers/ && \
	mkdir -p _out/cpu/ && \
	mkdir -p _out/kernel/

clean:
	rm -rf _out/*
