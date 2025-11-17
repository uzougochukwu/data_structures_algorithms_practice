	; only prints up to 2559
	; if you try to print 2560, when you divide by 10 the quotient is 256, which exceeds the maximum space of al, which is the register that stores the quotient
	; need way to detect it if the first digit is 0
	; 
	
section .bss
	number resb 1
	

section .data

global _start

section .text

_start:
	xor rax, rax
	xor rdx, rdx


	mov ax, 0xAA

	; rsp contains roughly 0x7fffffffff, rbp contains 0

	mov rbp, rsp		; stack pointer and base pointer should point to same memory location

	; push 10 on stack to tell function when to end, 10 means '\n'
	; might not need this as rcx keeps track of the length being pushed

	mov byte [rsp], 0xA			; everytime we push a value onto the stack, the stack pointer is decremented. the value we pushed occupies the lowest portion of the stack
	; eventually, the most significant digit in the number will occupy the very lowest portion of the stack, we then use the write syscall

	mov r12, 0x0

	mov sil, 0xA		; rax will be divided by rdi

OnStackLoop:
	xor rbx, rbx

	div sil		; remainder goes in ah and quotient goes in al

	; this is a 16 bit dividend in ax being divided by an 8 bit divisor in sil, so the quotient goes in al and the remainder goes in ah

	; check that quotient is not zero, because if it is that means we are on the final digit of the number (the least significant)
	cmp al, 0x0
	je last_digit

	add ah, 0x30		; to convert the remainder into its ascii equivalent

	mov bh, ah		; can't push an 8 bit value onto the stack so must mov it into bh (the high 8 bits of the first 16 bits of rbx) first
	shr rbx, 8
	sub rsp, 4
	mov byte [rsp], bl

	sub ah, 0x30		; back to normal
	

	inc r12

	; ah still contains remainder, which will confound our next division
	; use bitmask to remove the value in ah but preserve value in al
	and ax, 255

	jmp OnStackLoop


last_digit:
	add ah, 0x30
	
	mov bh, ah
	shr rbx, 8

	sub rsp, 4
	mov byte [rsp], bl	
	inc r12

	; r12 contains the number of digits in the number as a whole

ActualPrint:
	
	;	mov eax, dword [rsp]

	cmp r12, 0 		; if we have printed the last digit, then exit
	je exit
	
	mov rax, 0x1
	mov rdi, 0x1
	mov rdx, 0x1
	mov rsi, rsp
	syscall

	add rsp, 4

	dec r12

	jmp ActualPrint
	


exit:
	
	mov rdi, 0x1
	mov rax, 0x3c
	syscall
