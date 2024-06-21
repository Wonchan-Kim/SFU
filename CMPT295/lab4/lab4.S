    .section .note.GNU-stack,""
    .global largest_power_unsigned 
    .global overflowing_subtract
    .global dumb
    .global is_prime
    .text

is_prime:
    push %r12
    push %r13
    mov %rdi, %r12 #mov n to r12
    cmp $1, %r12 #if r12 is eqaul to 1, it is not prime
    je end 
    cmp $2, %r12 #if r12 is eqaul to 2, it is prime
    je exception
    mov $2, %r13 # r13 stores the number to be divided

division:
    cmp %r13, %r12 #if counter == num, it is not prime
    je prime
    mov $0, %rdx #divide start remainder in rdx, 
    mov %r12, %rax 
    div %r13 
    cmp $0, %rdx #if remainder is 0, not a prime
    je end
    add $1, %r13 #increase r13 by one and loop
    jmp division
    
prime: 
    mov $1, %rax #return 1 if prime
    pop %r13
    pop %r12
    ret
exception:
    pop %r13
    pop %r12
    mov $1, %rax
    ret

end:
    pop %r13
    pop %r12
    mov $0, %rax
    ret

largest_power_unsigned:
    mov %rdi, %rax  # rax will store the current power of x
    mov %rdi, %rcx  # rcx will be used to multiply rax
    mov %rax, %rbx  # rbx will store the last valid power of x
    
loop:
    mul %rcx         # rdx:rax = rax * rcx (64-bit multiplication)
    testq %rdx, %rdx  # check if there was an overflow
    jnz done         
    movq %rax, %rbx   # update the value
    jmp loop
    
done:
    movq %rbx, %rax 
    ret

overflowing_subtract:
    sub %rsi, %rdi
    jo end_os
    mov %rdi, %rax
    ret
end_os:
    mov $0, %rax
    ret

dumb:
    test %rdi, %rdi
    je rsiadd1
    test %rsi, %rsi
    je retrdi
    push %r9
    push %r8
    mov %rdi, %r8
    mov %rsi, %r9
    add %r8, %r8
    add %r9, %r8
    sub $1, %rsi
    sub $1, %rdi
    call dumb

    add %rax, %r8
    mov %r8, %rax
    pop %r8
    pop %r9
    ret

rsiadd1:
    add $1, %rsi
    mov %rsi, %rax
    ret

retrdi:
    mov %rdi, %rax
    ret
