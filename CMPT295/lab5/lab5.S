    .section .note.GNU-stack,""
    .global fibonacci
    .global is_odd1
    .global is_odd2
    .global polynomial1
    .global polynomial2
    .global mul1
    .global mul2
    .text

fibonacci:
    push %rbx
    push %r12
    cmp $1, %rdi
    jle end
    mov %rdi, %rbx
    sub $1, %rbx
    #first recursion
    mov %rbx, %rdi
    call fibonacci
    mov %rax, %r12 #r12 stores the first part

    sub $1, %rbx
    mov %rbx, %rdi
    call fibonacci

    add %r12, %rax
    pop %r12
    pop %rbx
    ret

end:
    pop %r12
    pop %rbx
    mov %rdi, %rax
    ret

polynomial1:
    imul %rdi, %rsi
    imul %rdi, %rsi
    imul %rdi, %rsi
    imul %rdi, %rdx
    imul %rdi, %rdx
    imul %rdi, %rcx
    add %r8, %rsi
    add %rcx, %rsi
    add %rdx, %rsi
    mov %rsi, %rax
    ret

polynomial2:
    imul %rdi, %rsi # ax
    add %rsi, %rdx # ax + b
    imul %rdi, %rdx # x * (ax + b)
    add %rdx, %rcx 
    imul %rdi, %rcx
    add %rcx, %r8
    mov %r8, %rax
    ret

is_odd1:
    mov %rdi, %rax
    mov $2, %rcx 
    xor %rdx, %rdx
    div %rcx
    mov %rdx, %rax
    ret

is_odd2:
    and $1, %rdi
    mov %rdi, %rax
    ret

mul1:
    mov %rdi, %rax
    mov $65537, %rcx
    mul %rcx
    ret

mul2:
    mov %rdi, %rax
    shl $16, %rax
    add %rdi, %rax
    ret
