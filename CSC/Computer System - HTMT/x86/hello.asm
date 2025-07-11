;Xuat chuoi hello world ra man hinh
%include "io.inc"
extern getch
section .data
    tb db "Hello world", 0
section .text
global main
main:
    ;write your code here
    ; xuat tb
    ;printf(tb)
    push tb
    call printf
    add esp, 4 ;xoa stack
    
    call getch
    
    xor eax, eax
    ret