;; sys/syscall.h
%define SYS_write	1
%define SYS_mmap	9
%define SYS_clone	56
%define SYS_exit	60
%define SYS_pipe        22
%define SYS_read        0
%define SYS_close       3

; sys/pipe
%define O_CLOEXEC 02000000
	
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

section .bss

	pipe_fd resb 8		; this is where the two file descriptors for the pipe will end up
	
	output resb 8

section .text

	msg db "hello",0xa
	len equ $-msg
	
global _start

_start:
	; pipe_fd[1] is write
	; pipe_fd[0] is read
	
	mov rdi, pipe_fd
	mov rsi, O_CLOEXEC
	mov rax, SYS_pipe
	syscall

	xor rdi, rdi
	
	mov edi, dword [pipe_fd+4]
	mov rsi, msg
	mov rdx, len
	mov rax, SYS_write
	syscall

	xor rdi, rdi
	; close write
	mov dil, byte [pipe_fd+4]
	mov rax, SYS_close
	syscall
	
	xor rdi, rdi

	mov edi, dword [pipe_fd]
	mov rsi, output
	mov rdx, 8
	mov rax, SYS_read
	syscall

	; close read
	xor rdi, rdi
	mov dil, byte [pipe_fd]
	mov rax, SYS_close
	syscall
	
end:
	mov rax, 0x3c
	syscall
