bits 64
default rel

section .text

global pal_execute_invvpid_checked 
pal_execute_invvpid_checked :
    invvpid rdi, [rsi]
    jbe pal_execute_invvpid_checked_failure
    mov rax, 0x1
    ret

pal_execute_invvpid_checked_failure :
    mov rax, 0x0
    ret
