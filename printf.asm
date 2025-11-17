section .data

global _start

section .text

_start:

	xor rdx, rdx		; zero out rdx as the remainder is stored here (which we will print)
	xor r12, r12		; keep track of no. of digits to print

	mov rax, 0xA00		; dividend goes in rax, this is what we will print
	mov rdi, 0xA


put_digits_on_stack:
	cmp rax, 0		; if the final digit is zero, it means we have printed the last digit. the only way to have 0 in rax, is if the number we just divided was less than 10, so we can start printing the numbers
	je print

	div rdi			; rax / rdi , quotient (the result of the division) goes in rax
	; rdx has the remainder

	add rdx, 0x30		; add 0x30 so it is converted to an ascii text value of the number

	sub rsp, 0x4		; move rsp down 4 bytes, as 32 bit int

	mov dword [rsp], edx	; dword as 32 bit

	xor rdx, rdx		; division is rdx:rax divided by rdi, so we must zero rdx after each divide, since that is where the remainder is stored

	inc r12			; increase r12 as we have moved a digit to the stack for printing

	jmp put_digits_on_stack


print:

	cmp r12, 0x0
	je exit

	mov rdi, 0x1
	mov rax, 0x1
	mov rsi, rsp
	mov rdx, 0x1
	syscall

	add rsp, 0x4
	dec r12
	jmp print

exit:
	
	mov rdi, 0x1
	mov rax, 0x3c
	syscall
