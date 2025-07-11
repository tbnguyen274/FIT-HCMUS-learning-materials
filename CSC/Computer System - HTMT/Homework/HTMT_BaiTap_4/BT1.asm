;Ho va ten: Nguyen Thai Bao
; MSSV: 23120023
;Lop: 23CTT1

%include "io.inc"
extern getch

section .data
tb1 db "Nhap n: ",0
tb2 db "%d la so nguyen to",10,0
tb3 db "%d khong la so nguyen to",10,0
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

;Goi ham kiem tra so nguyen to
push dword [n]
call _KiemTraNguyenTo
add esp,4

call getch

xor eax, eax
ret


;========== Ham ===========
;dau thu tuc
global _KiemTraNguyenTo

_KiemTraNguyenTo:
;backup ebp
push ebp
mov ebp, esp
;--> tham so (n): [ebp + 8]
;backup cac thanh ghi neu can
push ebx
push ecx
push edx

;Than thu tuc
mov eax, [ebp + 8]  ; n

cmp eax, 2
jl _KhongPhaiNguyenTo
je _LaNguyenTo

mov ecx, 2  ; i = 2

_KiemTraNguyenTo.Lap:
mov eax, [ebp + 8]  ; n
mov edx, 0
div ecx
cmp edx, 0  ; Kiem tra n % i == 0
je _KhongPhaiNguyenTo

inc ecx
; Kiem tra xem i*i > n chua
mov eax, ecx
mul ecx         ; eax = i*i
cmp eax, [ebp + 8]
jle _KiemTraNguyenTo.Lap

_LaNguyenTo:
push dword [ebp + 8]
push tb2
call printf
add esp,8
jmp _KiemTraNguyenTo.KetThuc

_KhongPhaiNguyenTo:
push dword [ebp + 8]
push tb3
call printf
add esp,8

_KiemTraNguyenTo.KetThuc:
;Cuoi thu tuc
;restore cac thanh ghi
pop edx
pop ecx
pop ebx
pop ebp
ret