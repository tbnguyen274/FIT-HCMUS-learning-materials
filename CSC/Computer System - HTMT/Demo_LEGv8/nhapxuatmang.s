//Nhap va xuat mang 1 chieu n so nguyen.
.section .data
	tb1: .asciz "Nhap n: "
	tb2: .asciz "a[%d]: "
	tb3: .asciz "Mang vua nhap la: "
	fmt1: .asciz "%d"
	fmt2: .asciz "%d "
.section .bss
	n: .space 8
	arr: .space 80
.section .text
.global main
main:
	//Xuat tb1
	adrp x0,tb1
	add x0,x0,:lo12:tb1
	bl printf

	//nhap n
	adrp x0,fmt1
	add x0,x0,:lo12:fmt1
	adrp x1,n
	add x1,x1,:lo12:n
	bl scanf

	//load n vao x19
	adrp x19,n
	add x19,x19,:lo12:n
	ldur x19,[x19]

	//load dia chi arr vao x20
	adrp x20,arr
	add x20,x20,:lo12:arr

	//Khoi tao vong lap
	mov x21,#0 // i = 0

Loop_in:
	//xuat tb2
	adrp x0,tb2
	add x0,x0,:lo12:tb2
	mov x1,x21
	bl printf

	//nhap a[i]
	adrp x0,fmt1
	add x0,x0,:lo12:fmt1
	mov x1,x20
	bl scanf

	//Tang dia chi mang de qua pt ke tiep
	add x20,x20,#8

	//Tang i
	add x21,x21,#1

	//Neu i < n thi Lap
	cmp x21,x19
	b.lt Loop_in

	//xuat tb3
	adrp x0,tb3
	add x0,x0,:lo12:tb3
	bl printf

	//xoa stdin
	mov x0,#0
	bl fflush

	//load dia chi arr vao x20
	adrp x20,arr
	add x20,x20,:lo12:arr

	//Khoi tao vong lap
	mov x21,#0 // i = 0

Loop_out:
	//Xuat a[i]
	adrp x0,fmt2
	add x0,x0,:lo12:fmt2
	ldur x1,[x20]
	bl printf

	//xoa stdin
	mov x0,#0
	bl fflush

	//Tang dia chi mang de qua pt ke tiep
	add x20,x20,#8

	//Tang i
	add x21,x21,#1

	//Neu i < n thi Lap
	cmp x21,x19
	b.lt Loop_out

	//Ket thuc
	mov x0,#0
	mov x8,#93
	svc #0

