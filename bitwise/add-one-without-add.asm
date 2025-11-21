; look up bitwise tricks for isolating a bit, flipping it etc.


section .text

global _start

_start:

	mov rax, 11111011b
	push rax		; save value of rax on stack
	mov cl, 0x2 		; bit index 2 (index starts at 0)

	call check_a_bit
	pop rax			; restore value of rax

	call flip_bit

	mov rax, 0x3c	
	syscall


flip_bit:

	; {cl} = bit index
	; flips that bit from one to zero in rax

	mov r12, 0x1

	shl r12, cl		; move that first bit in r12 to correct position

	xor rax, r12		; if that particular bit in rax is one, then it will be flipped to zero, if it is zero it will be flipped to one

	ret

	


check_a_bit:
	; {cl} = bit index
	; {rax} = number to check
	
	; <-rsi-> return value, which is 1 or 0, depending on the value of the bit

	mov r12, 0x1

	sar rax, cl		; bit index specified by cl, that bit in rax is now the 1st bit

	test rax, 0x1		; mask out everything except that bit
	; if zero flag set, that bit was zero, if not set, it was 1

	cmovnz rsi, r12

	ret
