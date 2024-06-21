    .section .note.GNU-stack,""
    .global abs_value 
    .global power2 
    .global hailstone_length
    .text

abs_value:
    pushq %rdi
    cmpq $0, %rdi       # Compare argument with 0
    jge  positive       # Jump if greater than or equal to 0
    negq %rdi           # Negate the argument if it's negative
    mov %rdi, %rax
    popq %rdi
    ret                  # Return
positive:
    popq %rax
    ret                 # Return the argument unchanged if it's positive
    
power2:
    pushq %rbx
    movq %rdi, %rbx         # Move input n to counter register
    movq $1, %rax           # Initialize result to 1 

loop:
    pushq %rax
    mov %rax, %rdi              # Save result on the stack
    call print_uint64      # Call print_uint64 to print result
    popq %rax               # Restore result from the stack
    cmpq $0, %rbx           # Check if counter is zero
    je loop_end             # If zero, end loop

    

    shlq $1, %rax           # Double the result by left shifting
    decq %rbx               # Decrement the counter
    jmp loop          # Jump to loop start

loop_end:
    popq %rbx
    ret                      # Return

hailstone_length:
    push %r12
    push %rbx
    mov %rdi, %r12
    mov $0, %rbx

loop_start:
    cmp $1, %r12
    je end_hs
    add $1, %rbx
    test $1, %r12
    jnz odd_case
    shr $1, %r12
    jmp loop_start

odd_case:
    imul $3, %r12
    add $1, %r12
    jmp loop_start

end_hs:
    mov %rbx, %rax
    pop %rbx
    pop %r12
    ret
