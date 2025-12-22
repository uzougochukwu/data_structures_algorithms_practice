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

%define STACK_SIZE	(4096 * 1024)

%include "../include/print_registers.asm"
	
	; we need to have a unique colour for each thread when it prints
	; use bitmasks to isolate which part of the number we want

section .data

	num25 dq 37

	

	hello_1 db  `Hello from \e[94;1mthread\e[0m!\n\0`
	hello_2 db  `Hello from \e[95;1mthread\e[0m!\n\0`
	
section .bss

	digit_print resb 1
	addr resq 1

section .text

_start:

	
	mov rdi, print_zeroth_nibble
	call thread_create

	mov rdi, print_first_nibble
	call thread_create

	jmp end


.num25: dq 37




print_zeroth_nibble:

	
	mov rax, 1000
	jmp end

	
.num25: dq 37

print_first_nibble:
	mov rax, 2000
	

end:
	mov rax, 0x3c 		;60
	syscall


thread_create:

	push rdi
	call stack_create
	lea rsi, [rax + STACK_SIZE - 8]
	pop qword [rsi]
	mov rdi, THREAD_FLAGS
	mov rax, SYS_clone
	syscall
	ret


stack_create:
	mov rdi, 0		; mmap will return a block of memory at a random address
	mov rsi, STACK_SIZE
	mov rdx, PROT_WRITE|PROT_READ
	mov r10, MAP_ANONYMOUS|MAP_PRIVATE|MAP_GROWSDOWN
	mov r8, -1
	mov r9, 0
	mov rax, SYS_mmap
	syscall
	ret
