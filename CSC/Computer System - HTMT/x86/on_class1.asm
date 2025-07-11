%include "io.inc"
extern getch

section .data
    tb1 db "Nhap n: ",0
    tb2 db "n la so nguyen to",10,0
    tb3 db "n khong la so nguyen to",10,0
    tb4 db "n la so doi xung",10,0
    tb5 db "n khong la so doi xung",10,0
    tb6 db "n la so hoan thien",10,0
    tb7 db "n khong la so hoan thien",10,0
    fmt db "%d",0

section .bss
    n resd 1
    temp resd 1
    sum resd 1
    reverse resd 1
    divisor_sum resd 1

section .text
global main

main:
    ;Xuat tb1
    push tb1
    call printf
    add esp,4
    
    ;Nhap n
    push n
    push fmt
    call scanf
    add esp,8
    
    call check_prime
    call check_palindrome
    call check_perfect
    
    call getch
    xor eax, eax
    ret

check_prime:
    mov eax, [n]
    cmp eax, 2
    jl not_prime
    
    mov ecx, 2
prime_loop:
    mov edx, 0
    div ecx
    cmp edx, 0
    je not_prime
    inc ecx
    cmp ecx, eax
    jl prime_loop
    
    push tb2
    call printf
    add esp,4
    ret
not_prime:
    push tb3
    call printf
    add esp,4
    ret

check_palindrome:
    mov eax, [n]
    mov [temp], eax
    mov ebx, 0
palindrome_loop:
    cmp eax, 0
    je palindrome_check
    mov edx, 0
    mov ecx, 10
    div ecx
    imul ebx, ebx, 10
    add ebx, edx
    jmp palindrome_loop
palindrome_check:
    cmp ebx, [temp]
    je is_palindrome
    push tb5
    call printf
    add esp,4
    ret
is_palindrome:
    push tb4
    call printf
    add esp,4
    ret

check_perfect:
    mov eax, [n]
    mov ecx, 1
    mov [divisor_sum], ecx
perfect_loop:
    cmp ecx, eax
    jge perfect_check
    mov edx, 0
    div ecx
    cmp edx, 0
    jne not_divisor
    add [divisor_sum], ecx
not_divisor:
    inc ecx
    jmp perfect_loop
perfect_check:
    mov eax, [divisor_sum]
    cmp eax, [n]
    je is_perfect
    push tb7
    call printf
    add esp,4
    ret
is_perfect:
    push tb6
    call printf
    add esp,4
    ret
