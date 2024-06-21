    .section .note.GNU-stack,""
    .global calculate
    .text
    
calculate:
    push %rbx
    push %r12
    push %r13
    push %r14

    # x is in %rdi
    mov %rdi, %rbx       # save x in %rbx (call preserved)

    # a = x + 3
    mov %rdi, %r12       # move x to %r12 (call preserved)
    add $3, %r12         # a = x + 3

    # b = f(x, a)
    mov %r12, %rsi       # second argument a in %rsi, %rdi remains same
    call f
    mov %rax, %r13       # save result in %r13 (call preserved)

    # c = f(b, x)
    mov %r13, %rdi       # first argument b in %rdi
    mov %rbx, %rsi       # second argument x in %rsi
    call f
    mov %rax, %r14       # save result in %r14 (call preserved)

    # d = f(x, c)
    mov %rbx, %rdi       # first argument x in %rdi
    mov %r14, %rsi       # second argument c in %rsi
    call f
    mov %rax, %r9       # save result in %r9 (non-preserved)

    # a + b + c + d
    add %r12, %r13       # a + b
    add %r14, %r13       # a + b + c
    add %r9, %r13       # a + b + c + d
    mov %r13, %rax       # return value in %rax

    # restore all preserved registers
    pop %r14
    pop %r13
    pop %r12
    pop %rbx
    ret