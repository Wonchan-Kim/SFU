    .section .note.GNU-stack,""
    .global strlen_utf8
    .global strlen_mine
    .text

strlen_mine:
    mov $0, %rcx
loop:
    cmpb $0, (%rdi)
    je return
    inc %rcx
    inc %rdi
    jmp loop

return:
    mov %rcx, %rax
    ret

strlen_utf8:
    mov $0, %rcx
    mov %rdi, %rsi
loop_:
    mov (%rsi), %al
    test %al, %al
    jz return_second
    
    and $0xC0, %al
    cmp $0x80, %al # if and operand 0xC0 yields 0x80, ignore
    je ignore

    inc %rcx # else increase rcx

ignore:
    inc %rsi
    jmp loop_

return_second:
    mov %rcx, %rax
    ret
