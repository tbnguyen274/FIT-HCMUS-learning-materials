.section .data
	tb1: .asciz "Nhap n: "
	tb2: .asciz "a[%d]: "
	tb3: .asciz "Mang vua nhap la: "
	tb4: .asciz "Cac so nguyen to trong mang: "
	tb5: .asciz "Gia tri lon nhat trong mang: %d\n"
	tb6: .asciz "Trung binh cong cua mang: %.2f\n"
	fmt1: .asciz "%d"
	fmt2: .asciz "%d "
	newline: .asciz "\n"

.section .bss
	n: .space 8
	arr: .space 160		// 20 * 8 --> toi da 20 phan tu

.section .text
.global main
main:
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

	// Xuat tb1
	adrp x0, tb1
	add x0, x0, :lo12:tb1
	bl printf

	// Nhap n
	adrp x0, fmt1
	add x0, x0, :lo12:fmt1
	adrp x1, n
	add x1, x1, :lo12:n
	bl scanf

	// Load n vao x19
	adrp x19, n
	add x19, x19, :lo12:n
	ldur x19, [x19]

	// Kiem tra so phan tu cua mang
	cmp x19, #20
	b.gt _Fin		// Neu n > 20, thoat chuong trinh

	// Load dia chi arr vao x20
	adrp x20, arr
	add x20, x20, :lo12:arr

	// Khoi tao vong lap nhap mang
	mov x21, #0

Loop_in:
	// Xuat tb2
	adrp x0, tb2
	add x0, x0, :lo12:tb2
	mov x1, x21
	bl printf

	// Nhap a[i]
	adrp x0, fmt1
	add x0, x0, :lo12:fmt1
	mov x1, x20
	bl scanf

	add x20, x20, #8	// Tang dia chi mang
	add x21, x21, #1	// Tang i

	// Neu i < n, lap lai
	cmp x21, x19
	b.lt Loop_in

	// Xuat tb3
	adrp x0, tb3
	add x0, x0, :lo12:tb3
	bl printf

	// Load dia chi arr vao x20 de xuat mang
	adrp x20, arr
	add x20, x20, :lo12:arr
	mov x21, #0		// i = 0

Loop_out:
	// Xuat a[i]
	adrp x0, fmt2
	add x0, x0, :lo12:fmt2
	ldur x1, [x20]
	bl printf

	add x20, x20, #8	// Tang dia chi mang
	add x21, x21, #1	// Tang i

	// Neu i < n, lap lai
	cmp x21, x19
	b.lt Loop_out

	// Xuat xuong dong
	adrp x0, newline
	add x0, x0, :lo12:newline
	bl printf

	// Liet ke so nguyen to

	// Xuat tb4
	adrp x0, tb4
	add x0, x0, :lo12:tb4
	bl printf

	// Load dia chi arr vao x20 de xuat mang
	adrp x20, arr
	add x20, x20, :lo12:arr
	mov x21, #0		// i = 0

_XuatSNT.Loop:
	ldur x0, [x20]
	bl _KTSoNguyenTo		// Kiem tra so nguyen to
	
	cmp x0, #1
	b.ne _Print.Skip		// Neu khong phai so nguyen to, bo qua

	// Xuat so nguyen to
	adrp x0, fmt2
	add x0, x0, :lo12:fmt2
	ldur x1, [x20]
	bl printf

_Print.Skip:
	add x20, x20, #8	// Tang dia chi mang
	add x21, x21, #1	// Tang i

	// Neu i < n, lap lai
	cmp x21, x19
	b.lt _XuatSNT.Loop

	// Xuat xuong dong
	adrp x0, newline
	add x0, x0, :lo12:newline
	bl printf

	// Tim gia tri lon nhat

	// Load dia chi arr vao x20 de xuat mang
	adrp x20, arr
	add x20, x20, :lo12:arr
	ldur x22, [x20]		// max = arr[0]
	mov x21, #1			// i = 1

_Max.Loop:
	add x20, x20, #8	// Tang dia chi mang

	ldur x0, [x20]
	cmp x0, x22
	ble _Max.Skip		// Neu a[i] <= max, bo qua

	mov x22, x0			// Cap nhat max

_Max.Skip:
	add x21, x21, #1	// Tang i

	// Neu i < n, lap lai
	cmp x21, x19
	blt _Max.Loop

	// Xuat gia tri lon nhat
	adrp x0, tb5
	add x0, x0, :lo12:tb5
	mov x1, x22
	bl printf

	// Tinh trung binh cong

	// Load dia chi arr vao x20 de tinh trung binh
	adrp x20, arr
	add x20, x20, :lo12:arr
	mov x21, #0		// i = 0
	mov x22, #0		// sum = 0

Loop_sum:
	ldur x0, [x20]
	add x22, x22, x0	// sum += a[i]
	add x20, x20, #8	// Tang dia chi mang
	add x21, x21, #1	// Tang i

	// Neu i < n, lap lai
	cmp x21, x19
	blt Loop_sum

	// Tinh trung binh mang, ket qua la so thuc
	scvtf d0, x22		// Chuyen sum sang floating-point co dau (co the am)
	ucvtf d1, x19		// Chuyen n sang floating-point khong dau
	fdiv d0, d0, d1		// d0 = sum / n --> trung binh mang

	// Xuat trung binh
	adrp x0, tb6
	add x0, x0, :lo12:tb6
	bl printf

	// Restore cac thanh ghi
	b _Restore_ThanhGhi

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
