;Nhap xuat  mang 1 chieu
%include "io.inc"
extern getch
section .data
    tb1 db "Nhap n: ",0
    tb2 db "a[%d]: ",0
    tb3 db "Mang vua nhap la: ",0
    fmt1 db "%d",0
    fmt2 db "%d ",0

section .bss
    n resd 1
    arr resd 20
    
section .text
global main
main:
    ;write your code here
    ;xuat tb1
    push tb1
    call printf
    add esp,4
    
    ;Nhap n
    push n
    push fmt1
    call scanf
    add esp,8
    
    ;load dia chi arr vao ebx
    mov ebx, arr
    mov esi, 0 ; i = 0
Loop_in:
    ;xuat tb2
    push esi
    push tb2
    call printf
    add esp,8
    
    ;nhap a[i]
    push ebx
    push fmt1
    call scanf
    add esp,8
    
    ;Tang dia chi mang
    add ebx,4
    ;Tang i
    inc esi
    ;neu i < n thi lap
    cmp esi, [n]
    jl Loop_in
    
    ;xuat tb3
    push tb3
    call printf
    add esp,4
    
    ;Khoi tao vong lap
    mov ebx,arr
    mov esi,0
Loop_out:
    ;xuat a[i]
    push dword[ebx]
    push fmt2
    call printf
    add esp,8
    
    ;Tang dia chi mang
    add ebx,4
    ;Tang i
    inc esi
    ;Neu i < n thi Lap
    cmp esi, [n]
    jl Loop_out
    call getch
    xor eax, eax
    ret