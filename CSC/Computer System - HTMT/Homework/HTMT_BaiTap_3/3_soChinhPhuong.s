.section .data
    tb1: .asciz "Nhap n: "
    tb2: .asciz "n = %d\n"
    tb3: .asciz "n la so chinh phuong\n"
    tb4: .asciz "n khong la so chinh phuong\n"
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

    // Goi ham kiem tra so chinh phuong
    mov x0, x19
    bl _KTSoChinhPhuong

    // Neu x0 = 1, xuat tb3
    cmp x0, #1
    beq _InSoChinhPhuong

    // Neu x0 = 0, xuat tb4
    adrp x0, tb4
    add x0, x0, :lo12:tb4
    bl printf

    b _Fin

_InSoChinhPhuong:
    // Xuat tb3
    adrp x0, tb3
    add x0, x0, :lo12:tb3
    bl printf
    b _Fin   // Thoat chuong trinh

_Fin:
    mov x0, #0
    mov x8, #93
    svc #0

// ======== Ham kiem tra so chinh phuong ========

_KTSoChinhPhuong:
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
    mov x20, #0  // i = 0

_KTSoChinhPhuong.Loop:
    mul x21, x20, x20  // i * i

    cmp x21, x19
    beq _IsSquare   // i * i == n --> la so chinh phuong
    b.gt _IsNotSquare // i * i > n --> khong phai so chinh phuong

    add x20, x20, #1  // i++
    b _KTSoChinhPhuong.Loop

_IsSquare:
    mov x0, #1
    b _Restore_ThanhGhi

_IsNotSquare:
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
