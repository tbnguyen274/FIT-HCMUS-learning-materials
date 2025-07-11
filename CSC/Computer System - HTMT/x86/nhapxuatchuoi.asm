%include "io.inc"
extern gets
extern getch

section .data
    tb1 db "Nhap ho ten: ", 0
    tb2 db "Nhap nam sinh: ", 0
    tb3 db "Xin chao %s, tuoi: %d", 0
    fmt db "%d", 0

section .bss
    hoten resb 30
    ns resd 1
    tuoi resd 1
    
section .text
global main
main:
    ; Xuất tb1
    push tb1
    call printf
    add esp, 4  ; Xóa stack
    
    ; Nhập họ tên
    push hoten
    call gets
    add esp, 4
    
    ; Xuất tb2
    push tb2
    call printf
    add esp, 4  ; Xóa stack
    
    ; Nhập năm sinh (Sửa lỗi scanf)
    push ns
    push fmt
    call scanf
    add esp, 8
    
    ; Tính tuổi
    mov eax, 2025
    sub eax, [ns]  
    ; Lưu tuổi vào bộ nhớ
    mov [tuoi], eax
    
    ; Xuất tb3 (Sửa lỗi thứ tự tham số printf)
    push dword [tuoi]
    push hoten
    push tb3
    call printf
    add esp, 12  ; Xóa stack
    
    ; Chờ người dùng nhấn phím
    call getch
    
    xor eax, eax
    ret
