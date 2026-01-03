	; threads causing data from first thread to overwrite second
	; must use thread local storage with fs register

	; using fs register

	; try normal stack mem region
	; then try .tbss heap memory (might need to have .tbss passed into arch_prctl)
	; try approach seen here https://www.nasm.us/doc/nasm09.html#section-9.10.2
	; then try the clone argument where a struct contains a pointer to tls
	; fs syntax from https://maskray.me/blog/2021-02-14-all-about-thread-local-storage
	; other syntax from https://stackoverflow.com/questions/13350936/thread-local-storage-in-assembly

;; sys/syscall.h
%define SYS_write	1
%define SYS_mmap	9
%define SYS_clone	56
%define SYS_exit	60
%define SYS_pipe        22
%define SYS_read        0
%define SYS_close       3
%define SYS_arch_prctl  158	

; sys/pipes.h
%define O_CLOEXEC       02000000

; asm/prctl.h
%define ARCH_SET_FS	0x1002	

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

section .bss
	initial_stack resq 1

section .tbss
	num resb 1
;	val resb 1

section .data
	tid equ 5
	val equ 0

section .text
global _start

_start:
	mov qword [initial_stack], rsp

	mov rdi, ARCH_SET_FS
;	mov rsi, 0x20000
;	mov rsi, 0x7fffffff0000
	mov rsi, 0x401000
	mov rax, SYS_arch_prctl
	syscall

	; clone: rdi=flags, rsi=top of child stack
	
	mov rdi, THREAD_FLAGS
;	mov rsi, 0x7fffff550000
	mov rsi, 0x402000	
;	mov r9, 0x20000
;	mov r8, 0x7fffffffdcbc
	mov rax, SYS_clone
	syscall

parent:
	test rax, rax
	jz child

	mov byte [fs:val], 65

	xor rax, rax

;	wrfsbase rax

	mov al, byte [fs:val]
	
;	mov byte [fs:0], 5
;	mov byte [gs:0], 5
;	mov byte fs:0x20000, 5
;	mov dword fs:0x7fffffffdcbc, 5

;	mov rax, [rel tid wrt ..gottpoff]
;	mov rax, [wrt ..gottpoff]

	; print tls value

	mov rax, 1
	mov rdi, 1
;	mov rsi, 0x401000
;	lea rsi, [fs:val]
	rdfsbase rsi
	mov rdx, 1
	syscall
	
	
	jmp end
	
child:
	mov byte [fs:val], 66
	
	xor rax, rax

	mov al, byte [fs:val]
;	mov byte [fs:0], 6
;	mov byte [gs:0], 6
;	mov byte fs:0x20000, 6
;	mov dword fs:0x7fffffffdcbc, 6

	mov rax, 1
	mov rdi, 1
;	mov rsi, 0x401000
;	lea rsi, [fs:val]
	rdfsbase rsi
	mov rdx, 1
	syscall	
	
	jmp end

end:
	mov rax, 0x3c
	syscall
