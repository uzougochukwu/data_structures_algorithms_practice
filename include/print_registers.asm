
%include "../include/printf.asm"

section .data
	registers dq "rax:rdi:rsi:rbx:rcx:rdx:rbp:rsp:r8r:r9r:r10:r11:r12:r13:r14:r15:"
	print_line db `\n`
	
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

rcx_print:

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

	push rcx
	
	mov rsi, registers

	add rsi, 16

	call write_reg_to_screen

	
	; restore the reg to print in this section

	pop rcx

	mov rax, rcx		; move rcx into rax for printing

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


rdx_print:

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

	push rdx
	
	mov rsi, registers

	add rsi, 20

	call write_reg_to_screen

	
	; restore the reg to print in this section

	pop rdx

	mov rax, rdx		; move rdx into rax for printing

;	xor rdx, rdx

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

rbp_print:

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

	push rbp
	
	mov rsi, registers

	add rsi, 24

	call write_reg_to_screen

	
	; restore the reg to print in this section

	pop rbp

	mov rax, rbp		; move rbp into rax for printing

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

rsp_print:

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

	push rsp
	
	mov rsi, registers

	add rsi, 28

	call write_reg_to_screen

	
	; restore the reg to print in this section

	pop rsp

	mov rax, rsp		; move rsp into rax for printing

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

r8_print:

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

	push r8
	
	mov rsi, registers

	add rsi, 32

	call write_reg_to_screen

	
	; restore the reg to print in this section

	pop r8

	mov rax, r8		; move r8 into rax for printing

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


r9_print:

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

	push r9
	
	mov rsi, registers

	add rsi, 36

	call write_reg_to_screen

	
	; restore the reg to print in this section

	pop r9

	mov rax, r9		; move r9 into rax for printing

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


r10_print:

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

	push r10
	
	mov rsi, registers

	add rsi, 40

	call write_reg_to_screen

	
	; restore the reg to print in this section

	pop r10

	mov rax, r10		; move r10 into rax for printing

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


r11_print:

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

	push r11
	
	mov rsi, registers

	add rsi, 44

	call write_reg_to_screen

	
	; restore the reg to print in this section

	pop r11

	mov rax, r11		; move r11 into rax for printing

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

r12_print:

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

	push r12
	
	mov rsi, registers

	add rsi, 48

	call write_reg_to_screen

	
	; restore the reg to print in this section

	pop r12

	mov rax, r12		; move r12 into rax for printing

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

r13_print:

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

	push r13
	
	mov rsi, registers

	add rsi, 52

	call write_reg_to_screen

	
	; restore the reg to print in this section

	pop r13

	mov rax, r13		; move r13 into rax for printing

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


r14_print:

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

	push r14
	
	mov rsi, registers

	add rsi, 56

	call write_reg_to_screen

	
	; restore the reg to print in this section

	pop r14

	mov rax, r14		; move r14 into rax for printing

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


r15_print:

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

	push r15
	
	mov rsi, registers

	add rsi, 60

	call write_reg_to_screen

	
	; restore the reg to print in this section

	pop r15

	mov rax, r15		; move r14 into rax for printing

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
	mov rdx, 0x2
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

