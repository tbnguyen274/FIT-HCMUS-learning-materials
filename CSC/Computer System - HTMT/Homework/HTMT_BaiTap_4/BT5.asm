;Ho va ten: Nguyen Thai Bao
; MSSV: 23120023
;Lop: 23CTT1

%include "io.inc"
extern getch

section .data
tb1 db "Nhap so phan tu: ",0
tb2 db "a[%d] = ",0
tb3 db "Mang da nhap: ",0
tb4 db "Cac so nguyen to trong mang: ",0
tb5 db "Gia tri lon nhat trong mang: %d",10,0
tb6 db "Trung binh mang: %d",10,0
tb7 db "Khong co so nguyen to trong mang.",10,0
fmt_d1 db "%d",0
fmt_d2 db "%d ",0
newline db 10,0

section .bss
n resd 1           ; So phan tu mang
arr resd 100       ; Mang toi da 100 phan tu
sum resd 1         ; Tong mang
has_primes resd 1  ; Kiem tra co so nguyen to khong

section .text
global main

main:
    ; 1. Nhap mang 1 chieu n phan tu so nguyen
    call _NhapMang
    
    ; 2. Xuat mang
    call _XuatMang
    
    ; 3. Liet ke cac so nguyen to
    call _LietKeNguyenTo
    
    ; 4. Tim gia tri lon nhat trong mang
    call _TimMax
    
    ; 5. Tinh trung binh mang
    call _TinhTrungBinh
    
    ; Ket thuc chuong trinh
    call getch
    xor eax, eax
    ret

;========== Ham Nhap Mang ===========
_NhapMang:
    push ebp
    mov ebp, esp
    
    ; Nhap n
    push tb1
    call printf
    add esp, 4
    
    push n
    push fmt_d1
    call scanf
    add esp, 8
    
    ; Nhap tung phan tu
    mov ebx, arr    ; Luu dia chi mang vào ebx
    xor esi, esi    ; i = 0
    
_NhapMang.Loop:
    cmp esi, [n]
    jge _NhapMang.End
    
    ; Hien thi a[i] =
    push esi
    push tb2
    call printf
    add esp, 8
    
    ; Nhap arr[i]
    push ebx
    push fmt_d1
    call scanf
    add esp, 8
    
    ; Tang dia chi mang
    add ebx, 4
    
    ; Tang i
    inc esi
    jmp _NhapMang.Loop
    
_NhapMang.End:
    ; Xuong dong
    push newline
    call printf
    add esp, 4
    
    pop ebp
    ret

;========== Ham Xuat Mang ===========
_XuatMang:
    push ebp
    mov ebp, esp
    
    ; Xuat thong bao
    push tb3
    call printf
    add esp, 4
    
    ; Xuat tung phan tu
    mov ebx, arr    ; Luu dia chi mang vào ebx
    xor esi, esi    ; i = 0
    
_XuatMang.Loop:
    cmp esi, [n]
    jge _XuatMang.End
    
    ; Xuat arr[i]
    push dword [ebx]
    push fmt_d2
    call printf
    add esp, 8
    
    ; Tang dia chi mang
    add ebx, 4
    
    ; Tang i
    inc esi
    jmp _XuatMang.Loop
    
_XuatMang.End:
    ; Xuong dong
    push newline
    call printf
    add esp, 4
    
    pop ebp
    ret

;========== Ham Kiem Tra So Nguyen To ===========
_KiemTraNguyenTo:
    ; Backup ebp
    push ebp
    mov ebp, esp
    ; --> tham so (n): [ebp + 8]
    ; Backup cac thanh ghi neu can
    push ebx
    push ecx
    push edx

    ; Than thu tuc
    mov eax, [ebp + 8]  ; n
    cmp eax, 2
    jl _KhongPhaiNguyenTo
    je _LaNguyenTo

    mov ecx, 2  ; i = 2
    
_KiemTraNguyenTo.Loop:
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
    jle _KiemTraNguyenTo.Loop

_LaNguyenTo:
    mov eax, 1  ; Return 1 (la so nguyen to)
    jmp _KiemTraNguyenTo.End

_KhongPhaiNguyenTo:
    mov eax, 0  ; Return 0 (khong la so nguyen to)

_KiemTraNguyenTo.End:
    ; Cuoi thu tuc
    ; Restore cac thanh ghi
    pop edx
    pop ecx
    pop ebx
    pop ebp
    ret

;========== Ham Liet Ke So Nguyen To ===========
_LietKeNguyenTo:
    push ebp
    mov ebp, esp
    
    ; Xuat thong bao
    push tb4
    call printf
    add esp, 4
    
    ; Danh dau chua co so nguyen to nao
    mov dword [has_primes], 0
    
    ; Duyet mang
    mov ebx, arr    ; ; Kiem tra xem i*i > n chua
    xor esi, esi    ; i = 0
    
_LietKeNguyenTo.Loop:
    cmp esi, [n]
    jge _LietKeNguyenTo.End
    
    ; Kiem tra arr[i] co phai so nguyen to khong
    push dword [ebx]
    call _KiemTraNguyenTo
    add esp, 4
    
    ; Neu la so nguyen to (eax = 1) thi xuat ra
    cmp eax, 1
    jne _LietKeNguyenTo.Continue
    
    ; Xuat arr[i] neu la so nguyen to
    push dword [ebx]
    push fmt_d2
    call printf
    add esp, 8
    
    ; Danh dau co so nguyen to
    mov dword [has_primes], 1
    
_LietKeNguyenTo.Continue:
    ; Tang dia chi mang
    add ebx, 4
    
    ; Tang i
    inc esi
    jmp _LietKeNguyenTo.Loop
    
_LietKeNguyenTo.End:
    ; Kiem tra co so nguyen to nao khong
    cmp dword [has_primes], 0
    jne _LietKeNguyenTo.HasPrimes
    
    ; Neu khong co so nguyen to nao
    push tb7
    call printf
    add esp, 4
    jmp _LietKeNguyenTo.EndPrint
    
_LietKeNguyenTo.HasPrimes:
    ; Xuong dong
    push newline
    call printf
    add esp, 4
    
_LietKeNguyenTo.EndPrint:
    pop ebp
    ret

;========== Ham Tim Max ===========
_TimMax:
    push ebp
    mov ebp, esp
    
    ; Khoi tao max = phan tu dau tien
    mov ebx, arr
    mov ecx, dword [ebx]  ; max = arr[0]
    
    ; Duyet mang bat dau tu phan tu thu 1
    mov esi, 1      ; i = 1
    add ebx, 4      ; Dia chi arr[1]
    
_TimMax.Loop:
    cmp esi, [n]
    jge _TimMax.End
    
    ; So sanh arr[i] voi max
    cmp dword [ebx], ecx
    jle _TimMax.Continue
    
    mov ecx, dword [ebx]        ; Neu arr[i] > max thi cap nhat max

    
_TimMax.Continue:
    ; Tang dia chi mang
    add ebx, 4
    
    ; Tang i
    inc esi
    jmp _TimMax.Loop
    
_TimMax.End:
    ; Xuat gia tri max
    push ecx
    push tb5
    call printf
    add esp, 8
    
    pop ebp
    ret

;========== Ham Tinh Trung Binh Mang ===========
_TinhTrungBinh:
    push ebp
    mov ebp, esp
    
    ; Khoi tao sum = 0
    mov dword [sum], 0
    
    ; Duyet mang
    mov ebx, arr    ; Luu dia chi mang vào ebx
    xor esi, esi    ; i = 0
    
_TinhTrungBinh.Loop:
    cmp esi, [n]
    jge _TinhTrungBinh.End
    
    ; Cong arr[i] vao sum
    mov eax, dword [ebx]
    add [sum], eax
    
    ; Tang dia chi mang
    add ebx, 4
    
    ; Tang i
    inc esi
    jmp _TinhTrungBinh.Loop
    
_TinhTrungBinh.End:
    ; Tinh trung binh = sum / n
    mov eax, [sum]
    mov edx, 0
    div dword [n]   ; eax = sum / n
    
    ; Xuat gia tri trung binh
    push eax
    push tb6
    call printf
    add esp, 8
    
    pop ebp
    ret