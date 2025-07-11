.section .data
    tb1: .asciz "Nhap n: "
    tb2: .asciz "n = %d\n"
    tb3: .asciz "n la so nguyen to\n"
    tb4: .asciz "n khong la so nguyen to\n"
    fmt: .asciz "%d"

.section .bss
    n: .space 8

.section .text
.global main
main:
    // Xuat tb1
    adrp x0, tb1
    add x0, x0, :lo12:tb1
    bl printf

    // Nhap n
    adrp x0, fmt
    add x0, x0, :lo12:fmt
    adrp x1, n
    add x1, x1, :lo12:n
    bl scanf

    // Load n vao x19
    adrp x19, n
    add x19, x19, :lo12:n
    ldur x19, [x19]

    // Xuat gia tri n
    adrp x0, tb2
    add x0, x0, :lo12:tb2
    mov x1, x19
    bl printf

    // Goi ham kiem tra so nguyen to
    mov x0, x19
    bl _KTSoNguyenTo

    // Neu x0 = 1, la so nguyen to
    cmp x0, #1
    beq _InSNT

    // Neu x0 = 0, khong phai so nguyen to
    // Xuat tb4
    adrp x0, tb4
    add x0, x0, :lo12:tb4
    bl printf

    // Ket thuc chuong trinh
    b _Fin

_InSNT:
    // Xuat tb3
    adrp x0, tb3
    add x0, x0, :lo12:tb3
    bl printf

_Fin:
    mov x0, #0
    mov x8, #93
    svc #0

// ======== Ham kiem tra so nguyen to ========
_KTSoNguyenTo:
    // Backup x30
    sub sp, sp, #8
    str x30, [sp]
    // Backup cac thanh ghi khac
    sub sp, sp, #8
    str x19, [sp]
    sub sp, sp, #8
    str x20, [sp]
    sub sp, sp, #8
    str x21, [sp]

    mov x19, x0  // n
    cmp x19, #2
    blt _IsNotPrime  // Neu n < 2, khong phai so nguyen to

    mov x20, #2  // i = 2
    mov x21, x19 // temp = n

_SNT.Loop:
    mul x0, x20, x20  // i * i
    cmp x0, x21
    b.gt _IsPrime  // Neu i*i > n, ket thuc vong lap

    udiv x0, x21, x20  // temp / i
    mul x1, x0, x20    // x1 = (temp / i) * i
    sub x1, x21, x1    // x1 = temp - x1  <==> (temp % i)

    cmp x1, #0
    beq _IsNotPrime  // Neu n chia het cho i, khong phai so nguyen to
    
    add x20, x20, #1  // i++
    b _SNT.Loop

_IsPrime:
    mov x0, #1
    b _Restore_ThanhGhi

_IsNotPrime:
    mov x0, #0
    b _Restore_ThanhGhi

_Restore_ThanhGhi:
    // Restore cac thanh ghi
    ldr x21, [sp]
    add sp, sp, #8
    ldr x20, [sp]
    add sp, sp, #8
    ldr x19, [sp]
    add sp, sp, #8
    // Restore x30
    ldr x30, [sp]
    add sp, sp, #8

    // Quay ve
    ret
