	; prints from 2,147,483,647 to -2,147,483,648
	; it prints any signed 32 bit number, with the most significant bit being the sign bit

	; the number to be printed must be in r15 when this function is called


section .data

negative_sign: db "-"

new_line: db `\n`,0

space: db ' ',0

section .text

	; remove push and pops on lines 35 to 47
	; use a condition register to determine if the number is negative, then push "-" onto stack at last minute
	; stop messing around with the stack so much!
	; see if you can get printf to print all registers rather than just rax, but don't worry if not able
	; focus on multithreading with the binary coded decimal numbers

printf:

	mov qword rax, [rsp + 8] ; move the value that was pushed onto the stack into the rax reg for printing

	; dividend is in rax, this is what we will print

	xor r12, r12		; keep track of no. of digits to print
	
	mov rdi, 0xA

	test rax, rax		; determine if rax is negative

	jns put_digits_on_stack

	neg rax

	push rax		; save rax as it contains the number

	mov rdi, 0x1
	mov rax, 0x1
	mov rsi, negative_sign
	mov rdx, 0x1		; print 1 byte
	syscall

	pop rax
	
	xor rdx, rdx		; zero out rdx as the remainder is stored here (which we will print)
	mov rdi, 0xA		; 10


put_digits_on_stack:
	cmp rax, 0		; if the final digit is zero, it means we have printed the last digit. the only way to have 0 in rax, is if the number we just divided was less than 10, so we can start printing the numbers
	je print

	div rdi			; rax / rdi , quotient (the result of the division) goes in rax
	; rdx has the remainder

	add rdx, 0x30		; add 0x30 so it is converted to an ascii text value of the number

	dec rsp		        ; move rsp down 1 byte

	mov byte [rsp], dl	; move the remainder onto the stack, byte as dl is low byte of rdx. the remainder will be 9 at most which in binary is 1001, so the remainder will always fit in one byte

	xor rdx, rdx		; division is rdx:rax divided by rdi, so we must zero rdx after each divide, since that is where the remainder is stored

	inc r12			; increase r12 as we have moved a digit to the stack for printing

	jmp put_digits_on_stack

print:

	
	mov rdi, 0x1
	mov rax, 0x1
	mov rsi, rsp		; start at current mem address in rsp
	mov rdx, r12		; print from rsp to rsp + r12
	syscall

	; print space

	mov rdi, 0x1
	mov rax, 0x1
	mov rsi, space
	mov rdx, 0x1		; print 2 bytes
	syscall		

	add rsp, r12

exit:
	ret

check:
	mov r11, 0x2
	ret
