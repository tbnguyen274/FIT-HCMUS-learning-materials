;Ho va ten: Nguyen Thai Bao
; MSSV: 23120023
;Lop: 23CTT1

%include "io.inc"
extern getch

section .data
tb1 db "Nhap n: ",0
tb2 db "%d la so doi xung",10,0
tb3 db "%d khong la so doi xung",10,0
fmt db "%d",0

section .bss
n resd 1
reverse resd 1

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

;Goi ham kiem tra so doi xung
push dword [n]
call _KiemTraDoiXung
add esp,4

call getch

xor eax, eax
ret


;========== Ham ===========
;dau thu tuc
global _KiemTraDoiXung

_KiemTraDoiXung:
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
mov dword [reverse], 0  ; reverse = 0
mov ecx, ebx        ; ecx = n

_KiemTraDoiXung.Lap:
cmp ecx, 0          ;
je _KiemTraDoiXung.KetThuc_Lap

mov eax, [reverse]
mov edx, 10
mul edx             ; eax = reverse * 10
mov [reverse], eax  ; reverse = reverse * 10

mov eax, ecx        ; eax = temp
mov edx, 0
mov ebx, 10
div ebx             ; eax = temp / 10, edx = temp % 10
mov ecx, eax        ; temp = temp / 10

add [reverse], edx  ; reverse = reverse + (temp % 10)
jmp _KiemTraDoiXung.Lap

_KiemTraDoiXung.KetThuc_Lap:
mov eax, [reverse]  ; eax = reverse
mov ebx, [ebp + 8]  ; ebx = n
cmp eax, ebx
je _LaDoiXung       ; neu reverse == n, n la so doi xung

_KhongPhaiDoiXung:
push dword [ebp + 8]
push tb3
call printf
add esp,8
jmp _KiemTraDoiXung.KetThuc

_LaDoiXung:
push dword [ebp + 8]
push tb2
call printf
add esp,8

_KiemTraDoiXung.KetThuc:
;Cuoi thu tuc
;restore cac thanh ghi
pop edx
pop ecx
pop ebx
pop ebp
ret