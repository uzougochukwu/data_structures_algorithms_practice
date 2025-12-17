	; division of any number from 9223372036854775807 to -9223372036854775808
	; it prints any signed 64 bit number, with the most significant bit being the sign bit


section .data

negative_sign: db "-"

section .text

printf:
	; rsp + 8 -> rdi value
	; rsp -> return address
	
	mov rbp, rsp
	add rsp, 8
	
	pop rax 	; dividend goes in rax, this is what we will print
	xor rdx, rdx		; zero out rdx as the remainder is stored here (which we will print)
	xor r12, r12		; keep track of no. of digits to print

	
	mov rdi, 0xA

	test rax, rax		; determine if rax is negative

	jns put_digits_on_stack

	neg rax

	push rdi		; save rdi as it must be 10 for the division
	push rax		; save rax as it contains the number
	push rdx

	mov rdi, 0x1
	mov rax, 0x1
	mov rsi, negative_sign
	mov rdx, 0x1		; print 1 byte
	syscall

	pop rdx
	pop rax
	pop rdi			; restore rdi



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

exit:
	mov rsp, rbp
	
ret


check:
	mov r11, 0x2
	ret
