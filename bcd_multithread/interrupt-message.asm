	; coming soon - look at Future-Instructions.pdf in the /extra-info/intel-manuals folder
	; use lscpu | grep uintr to see if your computer supports it


section .text
global _start

_start:

	int 1

	mov rax, 0x3c
	syscall
