global _start

;; sys/syscall.h
%define SYS_write	1
%define SYS_mmap	9
%define SYS_clone	56
%define SYS_exit	60

;; unistd.h
%define STDIN		0
%define STDOUT		1
%define STDERR		2

;; sched.h
%define CLONE_VM	0x00000100
%define CLONE_FS	0x00000200
%define CLONE_FILES	0x00000400
%define CLONE_SIGHAND	0x00000800
%define CLONE_PARENT	0x00008000
%define CLONE_THREAD	0x00010000
%define CLONE_IO	0x80000000

;; sys/mman.h
%define MAP_GROWSDOWN	0x0100
%define MAP_ANONYMOUS	0x0020
%define MAP_PRIVATE	0x0002
%define PROT_READ	0x1
%define PROT_WRITE	0x2
%define PROT_EXEC	0x4

%define THREAD_FLAGS \
 CLONE_VM|CLONE_FS|CLONE_FILES|CLONE_SIGHAND|CLONE_PARENT|CLONE_THREAD|CLONE_IO

%include "../include/print_registers.asm"
	
	; we need to have a unique colour for each thread when it prints
	; use bitmasks to isolate which part of the number we want

section .data

	num25 dq 37

	

	hello_1 db  `Hello from \e[94;1mthread\e[0m!\n\0`
	hello_2 db  `Hello from \e[95;1mthread\e[0m!\n\0`
	
section .bss

	digit_print resb 1

section .text

_start:

	; first process
	; fork flags

	mov rax, 0x39
	syscall

	cmp rax, 0		; if rax is zero we are in the child process
	je first_nibble

	mov rax, qword [num25]

	mov r15, rax		; save value of rax in r15

	; isolate 0th nibble (4 bits) by bitwise and of rax with 1111

	and rax, 0b1111
	
;	call print_registers

	add rax, 0x30

	; print the first nibble

	mov byte [digit_print], al ; first 8 bits of rax


	mov rax, 0x1
	mov rdi, 0x1
	mov rsi, digit_print
	mov rdx, 0x1
	syscall

	jmp end



first_nibble:


	; second process

	; print second nibble

	mov rax, qword [num25]

	; isolate 1st nibble

	and rax, 0b11110000

	shr rax, 0x4 		; divide rax by 2 to power 4

	add rax, 0x30

	mov byte [digit_print], al

	mov rax, 0x1
	mov rdi, 0x1
	mov rsi, digit_print
	mov rdx, 0x1
	syscall
	

end:
	mov rax, 0x3c 		;60
	syscall
