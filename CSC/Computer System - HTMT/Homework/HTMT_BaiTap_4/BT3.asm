;Ho va ten: Nguyen Thai Bao
; MSSV: 23120023
;Lop: 23CTT1

%include "io.inc"
extern getch

section .data
tb1 db "Nhap n: ",0
tb2 db "%d la so chinh phuong",10,0
tb3 db "%d khong la so chinh phuong",10,0
fmt db "%d",0

section .bss
n resd 1

section .text
global main

main:
;write your code here
;xuat tb1
push tb1
call printf
add esp,4

;nhap n
push n
push fmt
call scanf
add esp,8

;Goi ham kiem tra so chinh phuong
push dword [n]
call _KiemTraChinhPhuong
add esp,4

call getch

xor eax, eax
ret


;========== Ham ===========
;dau thu tuc
global _KiemTraChinhPhuong

_KiemTraChinhPhuong:
;backup ebp
push ebp
mov ebp, esp
;--> tham so (n): [ebp + 8]
;backup cac thanh ghi neu can
push ebx
push ecx
push edx

;Than thu tuc
mov ebx, [ebp + 8]  ; ebx = n
mov ecx, 0          ; i = 0

_KiemTraChinhPhuong.Lap:
mov eax, ecx
mul eax             ; eax = i * i
cmp eax, ebx
je _LaChinhPhuong   ; neu i*i == n, n la so chinh phuong
jg _KhongPhaiChinhPhuong

inc ecx             ; i++
jmp _KiemTraChinhPhuong.Lap

_KhongPhaiChinhPhuong:
push dword [ebp + 8]
push tb3
call printf
add esp,8
jmp _KiemTraChinhPhuong.KetThuc

_LaChinhPhuong:
push dword [ebp + 8]
push tb2
call printf
add esp,8

_KiemTraChinhPhuong.KetThuc:
;Cuoi thu tuc
;restore cac thanh ghi
pop edx
pop ecx
pop ebx
pop ebp
ret