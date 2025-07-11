.section .data
    tb1: .asciz "Nhap n: "
    tb2: .asciz "n = %d\n"
    tb3: .asciz "n la so hoan thien\n"
    tb4: .asciz "n khong la so hoan thien\n"
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

    // Goi ham kiem tra so hoan thien
    mov x0, x19
    bl _KTSoHoanThien

    // Neu x0 = 1, xuat tb3
    cmp x0, #1
    beq _InSoHoanThien

    // Neu x0 = 0, xuat tb4
    adrp x0, tb4
    add x0, x0, :lo12:tb4
    bl printf

    b _Fin

_InSoHoanThien:
    //xuat tb3
    adrp x0, tb3
    add x0, x0, :lo12:tb3
    bl printf

_Fin:
    mov x0, #0
    mov x8, #93
    svc #0

// ======== Ham kiem tra so hoan thien ========

_KTSoHoanThien:
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

    cmp x19, #0
    b.le _IsNotPerfect // Neu n <= 0, khong phai so hoan thien

    mov x20, #1  // i = 1
    mov x21, #0  // sum = 0

_Loop:
    cmp x20, x19
    b.ge _Check // Neu i >= n, ket thuc vong lap

    udiv x0, x19, x20  // n / i
    mul x1, x0, x20  // x1 = n / i * i
    sub x1, x19, x1  // x1 = n - n / i * i <==> (n % i)

    cmp x1, #0
    bne _Next   // Neu n % i != 0, chuyen sang vong lap tiep theo

    add x21, x21, x20  // sum += i


_Next:
    add x20, x20, #1  // i++
    b _Loop

_Check:
    cmp x21, x19
    beq _IsPerfect
    mov x0, #0
    b _Restore_ThanhGhi

_IsPerfect:
    mov x0, #1
    b _Restore_ThanhGhi

_IsNotPerfect:
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
