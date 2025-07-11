%include "io.inc"
extern getch

section .data
    msg db "Binary representation: ", 0
    one db "1", 0
    zero db "0", 0
    fmt db "%d", 0

section .bss
    x resd 1

section .text
global main
main:
    ; Nhập x
    push msg
    call printf
    add esp, 4
    
    push x
    push fmt
    call scanf
    add esp, 8
    
    ; Gọi hàm xuất dãy bit
    push dword [x]
    call _XuatBit
    add esp, 4

    call getch
    xor eax, eax
    ret

global _XuatBit
_XuatBit:
    push ebp
    mov ebp, esp

    ; Lấy giá trị x từ stack
    mov eax, [ebp + 8]
    mov ecx, 32  ; Lặp đúng 32 lần
    
_Loop:
    test eax, 80000000h  ; Kiểm tra bit cao nhất
    jz _PrintZero        ; Nếu bit này là 0, in '0'
    
_PrintOne:
    push one
    call printf
    add esp, 4
    jmp _Continue

_PrintZero:
    push zero
    call printf
    add esp, 4

_Continue:
    rol eax, 1   ; Dịch vòng bit để tránh mất bit quan trọng
    dec ecx      ; Giảm bộ đếm
    jnz _Loop    ; Nếu chưa hết 32 lần, tiếp tục
