//Viet ham tinh tong 1 den n
.section .data
	tb1: .asciz "Nhap n: "
	tb2: .asciz "Tong 1 den %d la: %d\n"
	fmt: .asciz "%d"
.section .bss
	n: .space 8
.section .text
.global main
main:
	//Xuat tb1
	adrp x0,tb1
	add x0,x0,:lo12:tb1
	bl printf

	//nhap n
	adrp x0,fmt
	add x0,x0,:lo12:fmt
	adrp x1,n
	add x1,x1,:lo12:n
	bl scanf

	//Load n vao x19
	adrp x19,n
	add x19,x19,:lo12:n
	ldur x19,[x19]

	//Goi ham _TinhTong
	mov x0,x19
	bl _TinhTong

	//Lay ket qua tra ve
	mov x20,x0

	
	//xuat tb2
	adrp x0,tb2
	add x0,x0,:lo12:tb2
	mov x1,x19
	mov x2,x20
	bl printf

	//Ket thuc
	mov x0,#0
	mov x8,#93
	svc #0


// ======== Ham ========

// Dau thu tuc
_TinhTong:
	//backup x30 vao stack
	sub x28,x28,#8
	str x30,[x28]
	//backup cac thanh ghi khac
	sub x28,x28,#8
	str x19,[x28]
	sub x28,x28,#8
	str x20,[x28]
	sub x28,x28,#8
	str x21,[x28]

//Than thu tuc
	mov x19,x0 //mov n (x0) qua x19
	mov x20,#0 // s = 0
	mov x21,#1 // i = 1
_TinhTong.Loop:
	add x20,x20,x21 // s = s + i
	add x21,x21,#1 // i++
	//Neu i <= n thi Lap
	cmp x21,x19
	b.le _TinhTong.Loop

	//Luu ket qua tra ve
	mov x0,x20 
//Cuoi thu tuc
	//khoi phuc cac thanh ghi
	ldr x21,[x28]
	add x28,x28,#8
	ldr x20,[x28]
	add x28,x28,#8
	ldr x19,[x28]
	add x28,x28,#8
	ldr x30,[x28]
	add x28,x28,#8
	ret
