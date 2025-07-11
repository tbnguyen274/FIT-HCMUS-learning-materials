;Ho va ten: Nguyen Thai Bao
; MSSV: 23120023
;Lop: 23CTT1

%include "io.inc"
extern getch

section .data
tb1 db "Nhap n: ",0
tb2 db "%d la so hoan thien",10,0
tb3 db "%d khong la so hoan thien",10,0
fmt db "%d",0

section .bss
n resd 1
sum resd 1

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

;Goi ham kiem tra so hoan thien
push dword [n]
call _KiemTraHoanThien
add esp,4

call getch

xor eax, eax
ret


;========== Ham ===========
;dau thu tuc
global _KiemTraHoanThien

_KiemTraHoanThien:
;backup ebp
push ebp
mov ebp, esp
;--> tham so (n): [ebp + 8]
;backup cac thanh ghi neu can
push ebx
push ecx
push edx

;Than thu tuc
mov dword [sum], 0  ; sum = 0
mov ecx, 1          ; i = 1
mov ebx, [ebp + 8]  ; ebx = n
cmp ebx, 1
jl _KhongPhaiHoanThien

_KiemTraHoanThien.Lap:
cmp ecx, ebx        ; so sanh i voi n
jge _KiemTraHoanThien.KetThuc_Lap

mov eax, ebx        ; eax = n
mov edx, 0
div ecx             ; eax = n / i, edx = n % i
cmp edx, 0          ; kiem tra n % i == 0
jne _KiemTraHoanThien.TiepTuc

add [sum], ecx      ; sum += i

_KiemTraHoanThien.TiepTuc:
inc ecx             ; i++
jmp _KiemTraHoanThien.Lap

_KiemTraHoanThien.KetThuc_Lap:
mov eax, [sum]      ; eax = sum
cmp eax, ebx
je _LaHoanThien     ; neu sum == n, la so hoan thien

_KhongPhaiHoanThien:
push dword [ebp + 8]
push tb3
call printf
add esp,8
jmp _KiemTraHoanThien.KetThuc

_LaHoanThien:
push dword [ebp + 8]
push tb2
call printf
add esp,8

_KiemTraHoanThien.KetThuc:
;Cuoi thu tuc
;restore cac thanh ghi
pop edx
pop ecx
pop ebx
pop ebp
ret