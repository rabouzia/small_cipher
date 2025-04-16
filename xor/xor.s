BITS 64

section .data
strr db "Hello World", 0
xorr db "xor", 0
fmt db "%s", 10, 0


section .text
global main
;extern strlen
extern printf


main:
    push rbp
    mov rbp, rsp

    sub rsp, 8
    mov rax, qword [rel strr]
    mov rbx, qword [rel xorr]
    xor rax, rbx
    mov [rel strr], rax

    mov rdi, [rel fmt]
    mov rsi, [rel strr]
    xor rax, rax
    call printf
    add rsp, 8 



    mov rsp, rbp
    pop rbp
    ret