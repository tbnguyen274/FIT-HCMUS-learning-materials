%include "io.inc"
extern getch

section .data
tb_menu db "MENU:",10
        db "1. Nhap mang",10
        db "2. Xuat mang",10
        db "3. Liet ke so nguyen to",10
        db "4. Tim gia tri lon nhat",10
        db "5. Tinh trung binh mang",10
        db "6. Thoat",10
        db "Chon chuc nang: ",0
tb_nhap db "Nhap so phan tu: ",0
tb_nhap_pt db "a[%d] = ",0
tb_xuat db "Mang da nhap: ",0
tb_nguyen_to db "Cac so nguyen to trong mang: ",0
tb_max db "Gia tri lon nhat trong mang: %d",10,0
tb_trung_binh db "Trung binh mang: %d",10,0
tb_chua_nhap db "Ban chua nhap mang!",10,0
tb_khong_co_nt db "Khong co so nguyen to trong mang!",10,0
fmt_d db "%d",0
fmt_d_space db "%d ",0
fmt_newline db 10,0

section .bss
n resd 1           ; So phan tu cua mang
arr resd 100       ; Mang toi da 100 phan tu
choice resd 1      ; Lua chon menu
is_input resd 1    ; Kiem tra da nhap mang chua (0: chua, 1: roi)
sum resd 1         ; Tong cac phan tu mang
has_primes resd 1  ; Kiem tra co so nguyen to khong

section .text
global main

main:
    ; Khoi tao bien is_input = 0 (chua nhap)
    mov dword [is_input], 0
    
main_loop:
    ; Hien thi menu
    push tb_menu
    call printf
    add esp, 4
    
    ; Nhap lua chon
    push choice
    push fmt_d
    call scanf
    add esp, 8
    
    ; Xu ly lua chon
    mov eax, [choice]
    
    cmp eax, 1
    je _NhapMang
    
    cmp eax, 2
    je _XuatMang
    
    cmp eax, 3
    je _LietKeNguyenTo
    
    cmp eax, 4
    je _TimMax
    
    cmp eax, 5
    je _TinhTrungBinh
    
    cmp eax, 6
    je _Thoat
    
    jmp main_loop
    
_NhapMang:
    call _NhapMangFunc
    jmp main_loop
    
_XuatMang:
    ; Kiem tra da nhap mang chua
    cmp dword [is_input], 0
    je _ChuaNhap
    
    call _XuatMangFunc
    jmp main_loop
    
_LietKeNguyenTo:
    ; Kiem tra da nhap mang chua
    cmp dword [is_input], 0
    je _ChuaNhap
    
    call _LietKeNguyenToFunc
    jmp main_loop
    
_TimMax:
    ; Kiem tra da nhap mang chua
    cmp dword [is_input], 0
    je _ChuaNhap
    
    call _TimMaxFunc
    jmp main_loop
    
_TinhTrungBinh:
    ; Kiem tra da nhap mang chua
    cmp dword [is_input], 0
    je _ChuaNhap
    
    call _TinhTrungBinhFunc
    jmp main_loop
    
_ChuaNhap:
    push tb_chua_nhap
    call printf
    add esp, 4
    jmp main_loop
    
_Thoat:
    call getch
    xor eax, eax
    ret

;========== Ham Nhap Mang ===========
global _NhapMangFunc
_NhapMangFunc:
    push ebp
    mov ebp, esp
    push ecx
    push ebx
    
    ; Nhap n
    push tb_nhap
    call printf
    add esp, 4
    
    push n
    push fmt_d
    call scanf
    add esp, 8
    
    ; Nhap tung phan tu
    xor ecx, ecx    ; i = 0
    
_NhapMangFunc.Lap:
    cmp ecx, [n]
    jge _NhapMangFunc.KetThuc
    
    ; Hien thi a[i] =
    push ecx
    push tb_nhap_pt
    call printf
    add esp, 8
    
    ; Tinh dia chi arr[i]
    mov ebx, ecx
    shl ebx, 2      ; ebx = i * 4 (moi phan tu 4 bytes)
    add ebx, arr    ; ebx = &arr[i]
    
    ; Nhap arr[i]
    push ebx
    push fmt_d
    call scanf
    add esp, 8
    
    inc ecx
    jmp _NhapMangFunc.Lap
    
_NhapMangFunc.KetThuc:
    ; Danh dau da nhap mang
    mov dword [is_input], 1
    
    pop ebx
    pop ecx
    pop ebp
    ret

;========== Ham Xuat Mang ===========
global _XuatMangFunc
_XuatMangFunc:
    push ebp
    mov ebp, esp
    push ecx
    push ebx
    
    ; Xuat thong bao
    push tb_xuat
    call printf
    add esp, 4
    
    ; Xuat tung phan tu
    xor ecx, ecx    ; i = 0
    
_XuatMangFunc.Lap:
    cmp ecx, [n]
    jge _XuatMangFunc.KetThuc
    
    ; Tinh dia chi arr[i]
    mov ebx, ecx
    shl ebx, 2      ; ebx = i * 4
    
    ; Xuat arr[i]
    push dword [arr + ebx]
    push fmt_d_space
    call printf
    add esp, 8
    
    inc ecx
    jmp _XuatMangFunc.Lap
    
_XuatMangFunc.KetThuc:
    ; Xuong dong
    push fmt_newline
    call printf
    add esp, 4
    
    pop ebx
    pop ecx
    pop ebp
    ret

;========== Ham Kiem Tra So Nguyen To ===========
global _KiemTraNguyenTo
_KiemTraNguyenTo:
    push ebp
    mov ebp, esp
    push ebx
    push ecx
    
    ; Tham so thu nhat (n): [ebp + 8]
    mov eax, [ebp + 8]  ; eax = n
    
    ; Neu n < 2 thi khong phai nguyen to
    cmp eax, 2
    jl _KhongPhaiNguyenTo
    
    ; Neu n = 2 thi la nguyen to
    je _LaNguyenTo
    
    ; Neu n > 2
    mov ecx, 2      ; i = 2
    
_KiemTraNguyenTo.Lap:
    mov eax, [ebp + 8]  ; eax = n
    cmp ecx, eax        ; So sanh i voi n
    jge _LaNguyenTo     ; Neu i >= n, la so nguyen to
    
    mov edx, 0          ; clear edx cho phep chia
    div ecx             ; eax = n / i, edx = n % i
    
    cmp edx, 0          ; Kiem tra n % i == 0
    je _KhongPhaiNguyenTo   ; Neu n chia het cho i, khong phai nguyen to
    
    inc ecx             ; i++
    jmp _KiemTraNguyenTo.Lap
    
_KhongPhaiNguyenTo:
    mov eax, 0      ; return 0 (khong phai nguyen to)
    jmp _KiemTraNguyenTo.KetThuc
    
_LaNguyenTo:
    mov eax, 1      ; return 1 (la nguyen to)
    
_KiemTraNguyenTo.KetThuc:
    pop ecx
    pop ebx
    pop ebp
    ret

;========== Ham Liet Ke So Nguyen To ===========
global _LietKeNguyenToFunc
_LietKeNguyenToFunc:
    push ebp
    mov ebp, esp
    push ecx
    push ebx
    
    ; Xuat thong bao
    push tb_nguyen_to
    call printf
    add esp, 4
    
    ; Danh dau chua co so nguyen to nao
    mov dword [has_primes], 0
    
    ; Duyet mang
    xor ecx, ecx    ; i = 0
    
_LietKeNguyenToFunc.Lap:
    cmp ecx, [n]
    jge _LietKeNguyenToFunc.KetThuc
    
    ; Tinh dia chi arr[i]
    mov ebx, ecx
    shl ebx, 2      ; ebx = i * 4
    
    ; Kiem tra arr[i] co phai so nguyen to khong
    push dword [arr + ebx]
    call _KiemTraNguyenTo
    add esp, 4
    
    ; Neu la so nguyen to (eax = 1) thi xuat ra
    cmp eax, 1
    jne _LietKeNguyenToFunc.TiepTuc
    
    ; Xuat arr[i] neu la so nguyen to
    push dword [arr + ebx]
    push fmt_d_space
    call printf
    add esp, 8
    
    ; Danh dau co so nguyen to
    mov dword [has_primes], 1
    
_LietKeNguyenToFunc.TiepTuc:
    inc ecx
    jmp _LietKeNguyenToFunc.Lap
    
_LietKeNguyenToFunc.KetThuc:
    ; Kiem tra co so nguyen to nao khong
    cmp dword [has_primes], 0
    jne _LietKeNguyenToFunc.End
    
    ; Neu khong co so nguyen to nao
    push tb_khong_co_nt
    call printf
    add esp, 4
    jmp _LietKeNguyenToFunc.EndPrint
    
_LietKeNguyenToFunc.End:
    ; Xuong dong
    push fmt_newline
    call printf
    add esp, 4
    
_LietKeNguyenToFunc.EndPrint:
    pop ebx
    pop ecx
    pop ebp
    ret

;========== Ham Tim Max ===========
global _TimMaxFunc
_TimMaxFunc:
    push ebp
    mov ebp, esp
    push ecx
    push ebx
    
    ; Khoi tao max = phan tu dau tien
    mov ebx, dword [arr]
    
    ; Duyet mang bat dau tu phan tu thu 1
    mov ecx, 1      ; i = 1
    
_TimMaxFunc.Lap:
    cmp ecx, [n]
    jge _TimMaxFunc.KetThuc
    
    ; Tinh dia chi arr[i]
    mov eax, ecx
    shl eax, 2      ; eax = i * 4
    
    ; So sanh arr[i] voi max
    cmp dword [arr + eax], ebx
    jle _TimMaxFunc.TiepTuc
    
    ; Neu arr[i] > max thi cap nhat max
    mov ebx, dword [arr + eax]
    
_TimMaxFunc.TiepTuc:
    inc ecx
    jmp _TimMaxFunc.Lap
    
_TimMaxFunc.KetThuc:
    ; Xuat gia tri max
    push ebx
    push tb_max
    call printf
    add esp, 8
    
    pop ebx
    pop ecx
    pop ebp
    ret

;========== Ham Tinh Trung Binh Mang ===========
global _TinhTrungBinhFunc
_TinhTrungBinhFunc:
    push ebp
    mov ebp, esp
    push ecx
    push ebx
    
    ; Khoi tao sum = 0
    mov dword [sum], 0
    
    ; Duyet mang
    xor ecx, ecx    ; i = 0
    
_TinhTrungBinhFunc.Lap:
    cmp ecx, [n]
    jge _TinhTrungBinhFunc.KetThuc
    
    ; Tinh dia chi arr[i]
    mov ebx, ecx
    shl ebx, 2      ; ebx = i * 4
    
    ; Cong arr[i] vao sum
    mov eax, dword [arr + ebx]
    add [sum], eax
    
    inc ecx
    jmp _TinhTrungBinhFunc.Lap
    
_TinhTrungBinhFunc.KetThuc:
    ; Tinh trung binh = sum / n
    mov eax, [sum]
    mov edx, 0      ; clear edx cho phep chia
    div dword [n]   ; eax = sum / n
    
    ; Xuat gia tri trung binh
    push eax
    push tb_trung_binh
    call printf
    add esp, 8
    
    pop ebx
    pop ecx
    pop ebp
    ret