GLOBAL divide_by_cero
GLOBAL overflow
GLOBAL invalid_opcode

divide_by_cero:
	push rbp
	mov rbp, rsp

	mov ax, 10
	mov bl, 0
	div bl

    	mov rsp, rbp
	pop rbp
	ret


invalid_opcode:
	push rbp
	mov rbp, rsp

	UD2

    	mov rsp, rbp
	pop rbp
	ret


