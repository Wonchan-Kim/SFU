    .section .note.GNU-stack, ""
    .global is_prime
    .global dumb
    .global overflowing_subtract
    .global largest_power_unsigned
    .text

is_prime:
    
    mov %rdi, %rax
    mov $2, %r12
while:
    push %rax
    cmp %r12, %rax
    #rax <=r12 
    je end_prime
    mov $0, %rdx
    div %r12
    test %rdx, %rdx
    pop %rax
    je retzero
    add $1, %r12
    jmp while
end_prime:
    pop %rax
    mov $1, %rax
    ret
retzero:
    mov $0, %rax
    ret

largest_power_unsigned:
    mov %rdi, %r8
    mov %rdi, %r9
    
lploop:
    mov %r9, %rax
    mov $0, %rdx  
    mul %r8
    test %rdx, %rdx
    jne endlp
    mov %rax, %r9
    jmp lploop
endlp:
    mov %r9, %rax
    ret

overflowing_subtract:
    sub %rsi, %rdi
    jo ret_zero
    mov %rdi, %rax
    ret
ret_zero:
    mov $0, %rax
    ret

dumb:
    test %rdi, %rdi
    je bplusone                # 첫 번째 비교 후 bplusone으로 점프
    test %rsi, %rsi
    je retrdi                  # 두 번째 비교 후 retrdi로 점프

    push %r8                   # 레지스터 %r8, %rdi, %rsi 저장
    push %rdi
    push %rsi

    mov %rdi, %r8              # %r8에 %rdi 값을 저장
    add %rdi, %r8              # %r8 += %rdi
    add %rsi, %r8              # %r8 += %rsi
    sub $1, %rdi               # %rdi -= 1
    sub $1, %rsi               # %rsi -= 1

    call dumb                  # 재귀 호출

    add %rax, %r8              # %r8 += %rax
    mov %r8, %rax              # %rax에 %r8 값을 저장

    pop %rsi                   # 저장한 %rsi, %rdi, %r8 복원
    pop %rdi
    pop %r8
    ret                        # 반환

bplusone:
    add $1, %rsi               # %rsi += 1
    mov %rsi, %rax             # %rax에 %rsi 값을 저장
    ret                        # 반환

retrdi:
    mov %rdi, %rax             # %rdi 값을 %rax에 저장
    ret                        # 반환
