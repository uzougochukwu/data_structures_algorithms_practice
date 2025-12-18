
%include "../include/printf.asm"

section .data
	registers dq "rax:rdi:rsi:rbx:rcx:"
	print_line db "\n"
	
section .text

print_registers:

	; will need to save all registers at start

	push rax
	push rbx
	push rcx
	push rdx
	push rsi
	push rdi
	push rbp
	push rsp
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15
	
	; will need to save and restore all registers before each print in this function

;	mov rax, 6894
;	mov rdi, 127382
;	mov rsi, 385732
rax_print:

	; save all regs

	push rax
	push rbx
	push rcx
	push rdx
	push rsi
	push rdi
	push rbp
	push rsp
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15

	; save the reg to print in this section
	
	push rax
	
	mov rsi, registers
	
	call write_reg_to_screen

	; restore the reg to print in this section
	pop rax

	xor rdx, rdx

	; rax already contains value 
	
	mov qword [rsp],rax
	call printf

	; restore all regs

	pop r15
	pop r14
	pop r13
	pop r12
	pop r11
	pop r10
	pop r9
	pop r8
	pop rsp
	pop rbp
	pop rdi
	pop rsi
	pop rdx
	pop rcx
	pop rbx
	pop rax
	
rdi_print:

	; save all regs
	push rax
	push rbx
	push rcx
	push rdx
	push rsi
	push rdi
	push rbp
	push rsp
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15

	; save the reg to print in this section

	push rdi

	mov rsi, registers

	add rsi, 4
	
	call write_reg_to_screen

	; restore the reg to print in this section

	pop rdi

	mov rax, rdi		; move rdi into rax for printing

	xor rdx, rdx

	mov qword [rsp],rax
	call printf

	; restore all regs

	pop r15
	pop r14
	pop r13
	pop r12
	pop r11
	pop r10
	pop r9
	pop r8
	pop rsp
	pop rbp
	pop rdi
	pop rsi
	pop rdx
	pop rcx
	pop rbx
	pop rax

rsi_print:

	; save all regs
	push rax
	push rbx
	push rcx
	push rdx
	push rsi
	push rdi
	push rbp
	push rsp
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15

	; save the reg to print in this section

	push rsi
	
	mov rsi, registers

	add rsi, 8

	call write_reg_to_screen

	
	; restore the reg to print in this section

	pop rsi

	mov rax, rsi		; move rsi into rax for printing

	xor rdx, rdx

	mov qword [rsp],rax
	call printf

	; restore all regs
	pop r15
	pop r14
	pop r13
	pop r12
	pop r11
	pop r10
	pop r9
	pop r8
	pop rsp
	pop rbp
	pop rdi
	pop rsi
	pop rdx
	pop rcx
	pop rbx
	pop rax

rbx_print:

	; save all regs
	push rax
	push rbx
	push rcx
	push rdx
	push rsi
	push rdi
	push rbp
	push rsp
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15

	; save the reg to print in this section

	push rbx
	
	mov rsi, registers

	add rsi, 12

	call write_reg_to_screen

	
	; restore the reg to print in this section

	pop rbx

	mov rax, rbx		; move rbx into rax for printing

	xor rdx, rdx

	mov qword [rsp],rax
	call printf

	; restore all regs
	pop r15
	pop r14
	pop r13
	pop r12
	pop r11
	pop r10
	pop r9
	pop r8
	pop rsp
	pop rbp
	pop rdi
	pop rsi
	pop rdx
	pop rcx
	pop rbx
	pop rax

end_pr:

	; print new_line
	mov rax, 0x1
	mov rdi, 0x1
	mov rsi, print_line
	mov rdx, 0x1
	syscall

	
	; must restore all values after printing new_line

	pop r15
	pop r14
	pop r13
	pop r12
	pop r11
	pop r10
	pop r9
	pop r8
	pop rsp
	pop rbp
	pop rdi
	pop rsi
	pop rdx
	pop rcx
	pop rbx
	pop rax
ret

write_reg_to_screen:
	mov rax, 0x1
	mov rdi, 0x1

	mov rdx, 4
	syscall
	ret

