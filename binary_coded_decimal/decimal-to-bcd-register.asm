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


%include "../include/print_registers.asm"

	

	; for printf number must be in rax


section .data
	; 2^0, 2^4, 2^8, 2^12, 2^16 ...
	p4_series dq 1, 16, 256, 4096, 65536 
	
section .text
	
global _start	

_start:

	; convert decimal 25 into binary coded decimal
	; 25 is in bcd 0010 0101
	; 0000 0000 0000 0000 ...

	; decimal number to be stored in r11 to begin with and rax for calculations
	; the binary coded decimal number to be stored in rsi

	; end condition - if value in rax is zero after a division - means we have created final remainder (which is the digit)
	; rcx will be i

	; 42 in bcd
	; 0100 0010

	; 7 7 5
	; 0111 0111 0101

	; 1001
	; 0001 0000 0000 0001

	; 12376
	; 0001 0010 0011 0111 0110

	; 1237
	; 0001 0010 0011 0111
	
	mov r11, 12376
	mov rax, 12376
	mov rcx, 0
	mov rdi, 10
	xor rsi, rsi
	
	; need register to store whether or not this is the last digit
	mov r15, 0		; if r15 is 1, we are on last digit and can exit

	mov r13, 1

	; if rax was 10 -> 10/10 = 1 r 0 -> 1/10 = 0 r 1

decimal_to_bcd:

	mov rax, r11		; move result of previous div into rax

	div rdi
	call print_registers
	test rax, rax		; rax is the result of the div instruction, if it is zero that means we are on the last digit, but we still need to go through the rest of the loop (for the last time)
	cmovz r15, r13		; if the result of test rax, rax sets the zero flag, we want to move 1 into r15, to show we are on the last digit

	; the result in rax is being overwritten, may need to save it elsewhere

	mov r11, rax		; store this result for next iteration

	mov rax, rdx		; move remainder into rax for scaling

	xor rdx, rdx		; zero out rdx to not confound next division

	mul qword [p4_series + rcx*8] ; multiplied remainder by the scaling

	add rsi, rax

	inc rcx

	test r15, r15		; see if r15 is 1, if it is zero loop again
	jz decimal_to_bcd


	call print_registers


print_result:
;	mov rax, rsi
;	call printf

end:	
	mov rax, 0x3c
	syscall
