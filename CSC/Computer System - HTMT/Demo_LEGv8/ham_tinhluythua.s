.section .data
    tb1: .asciz "Nhap x: "       
    tb2: .asciz "Nhap n: "       
    tb3: .asciz "Ket qua x^n = " 
    fmt1: .asciz "%d"            
    fmt2: .asciz "%d\n"          

.section .bss
    x: .space 8   
    n: .space 8   
    result: .space 8 

.section .text
.global main

main:
    // Nhập x
    adrp x0, tb1
    add x0, x0, :lo12:tb1
    bl printf

    adrp x0, fmt1
    add x0, x0, :lo12:fmt1
    adrp x1, x
    add x1, x1, :lo12:x
    bl scanf

    // Nhập n
    adrp x0, tb2
    add x0, x0, :lo12:tb2
    bl printf

    adrp x0, fmt1
    add x0, x0, :lo12:fmt1
    adrp x1, n
    add x1, x1, :lo12:n
    bl scanf

    // Load x và n vào thanh ghi
    adrp x19, x
    add x19, x19, :lo12:x
    ldur x19, [x19]  // x19 = x

    adrp x20, n
    add x20, x20, :lo12:n
    ldur x20, [x20]  // x20 = n

    // Kiểm tra nếu n == 0 thì kết quả = 1
    cmp x20, #0
    b.ne _TinhLuyThua
    mov x21, #1
    b _LuuKetQua

_TinhLuyThua:
    mov x21, #1      
Loop:
    mul x21, x21, x19  // result *= x
    sub x20, x20, #1   // n -= 1
    cmp x20, #0
    b.gt Loop

_LuuKetQua:
    
    adrp x22, result
    add x22, x22, :lo12:result
    stur x21, [x22]

    // Xuất kết quả
    adrp x0, tb3
    add x0, x0, :lo12:tb3
    bl printf

    adrp x0, fmt2
    add x0, x0, :lo12:fmt2
    mov x1, x21
    bl printf

    // Kết thúc chương trình
    mov x0, #0
    mov x8, #93
    svc #0
