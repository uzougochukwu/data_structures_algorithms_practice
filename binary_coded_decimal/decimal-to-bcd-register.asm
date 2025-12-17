	; example 25 decimal
	; 25 decimal becomes 0010 0101 in bcd
	; two approaches, one for storing the bcd number in a register, the other for storing it in memory (same method for heap and stack)

	; store it in a register
	; let x be the decimal number
	; we repeatedly divide x by 10
	; don't forget to clear rdx after each division
	; remainder of x/10 is the digit we wish to move into the register
	; but we need to scale up the remainder of x/10 by its position
	; first we move it into nibble 0, then 1, 2 etc.
	; if the number of loop iterations is i
	; then after each x/10, we multiply that remainder by 2 to the power of (4 multiplied by i)
	; so that on the 0th iteration its x/10 remainder multiplied by 2 to the power of 0
	; then 2 to the power of 4
	; then 2 to the power of 8
	; and so on until the result of x/10 is 0
	; after each x/10, the remainder is being multiplied by its scaling factor and added to the register we have designated to contain the bcd number

	; store it in memory
	; decide how much memory is needed - this is crucial to interpet the bcd number
	; let x be the decimal number
	; memlength = ceiling ( log_10(x) )
	; with memlength as an integer number of bytes
	; the number will be stored with the least sig digit at low memory
	; start mem index at memlength - 1
	; decrement mem index with each loop
	; on each loop iteration do x/10
	; don't forget to clear rdx after each division
	; then remainder of x/10 multiplied by 2 to the power of 4
	; add those two results together
	; then move them into the byte at mem index
	; continue until result of x/10 is 0

	; max number to display is 9223372036854775807

%include "../include/printf.asm"

	; printf can only be used once due to incorrectly saving and restoring registers
	; number to print in rax
	


section .data
	p4_series dq 1, 16, 256, 65536 ; scaling factor is 8 because it is 8 bytes in a quadword
section .text
	
global _start	

_start:

entry:
	; decimal number stored in r11
	; binary coded decimal number stored in rsi

	xor rsi, rsi

	mov rax, 25

	mov r11, 25

	mov rdi, 0xa
	
	div rdi 		; rax / rdi = result in rax and rem in rdx

	; remainder stored in rdx

	add rsi, rdx		; rsi will contain final bcd number

	; first number is in rsi

	; must clear rdx otherwise div instruction becomes different

	; rsi contains 5 - as it should

	xor rdx, rdx

	div rdi			; rax / rdi = result in rax and rem in rdx

	mov rax, rdx		; need to multiply rem by power of 4 factor (rem is 2 now)

	

	; 2 is in rax as it should be
	
	mul qword [p4_series+ 1*8]

	; 2 * 16 should be 32
	; 32 is in rax

	add rsi, rax

	; rsi should now have 37

	mov rax, rsi  		; it does!
	call printf

end:	
	mov rax, 0x3c
	syscall
