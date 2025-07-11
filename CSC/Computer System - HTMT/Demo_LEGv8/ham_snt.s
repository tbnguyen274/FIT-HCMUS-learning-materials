.section .data
    tb1: .asciz "Nhap n: "         
    tb2: .asciz "n la so nguyen to.\n"  
    tb3: .asciz "n khong phai so nguyen to.\n"  
    fmt1: .asciz "%d"              

.section .bss
    n: .space 8   

.section .text
.global main

main:
    // Nhập n
    adrp x0, tb1
    add x0, x0, :lo12:tb1
    bl printf

    adrp x0, fmt1
    add x0, x0, :lo12:fmt1
    adrp x1, n
    add x1, x1, :lo12:n
    bl scanf

    // Load n vào x19
    adrp x19, n
    add x19, x19, :lo12:n
    ldur x19, [x19]  // x19 = n

    // Nếu n < 2, không phải số nguyên tố
    cmp x19, #2
    b.lt _KhongLaSNT

    // i = 2
    mov x20, #2  

_Loop:
    // Nếu i * i > n thì dừng, là số nguyên tố
    mul x21, x20, x20  // x21 = i * i
    cmp x21, x19
    b.gt _LaSNT

    // Nếu n % i == 0, không phải số nguyên tố
    udiv x22, x19, x20 
    msub x23, x22, x20, x19 
    cbz x23, _KhongLaSNT 

    // Tăng i
    add x20, x20, #1
    b _Loop

_LaSNT:
    adrp x0, tb2
    add x0, x0, :lo12:tb2
    bl printf
    b Exit

_KhongLaSNT:
    adrp x0, tb3
    add x0, x0, :lo12:tb3
    bl printf
    
Exit:
    mov x0, #0
    mov x8, #93
    svc #0
