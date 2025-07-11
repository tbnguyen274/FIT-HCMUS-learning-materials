.section .data
    tb1: .asciz "Nhap n: "
    tb2: .asciz "n = %d\n"
    tb3: .asciz "Dinh dang nhi phan: "
    fmt: .asciz "%d"
    newline: .asciz "\n"

.section .bss
    n: .space 8
    bin_str: .space 65 

.section .text
.global main
main:
    // Xuất tb1
    adrp x0, tb1
    add x0, x0, :lo12:tb1
    bl printf

    // Nhập n
    adrp x0, fmt
    add x0, x0, :lo12:fmt
    adrp x1, n
    add x1, x1, :lo12:n
    bl scanf

    // Load n vào x19
    adrp x19, n
    add x19, x19, :lo12:n
    ldur x19, [x19]

    // Xuất giá trị n
    adrp x0, tb2
    add x0, x0, :lo12:tb2
    mov x1, x19
    bl printf

    // Xuất thông báo "Dinh dang nhi phan:"
    adrp x0, tb3
    add x0, x0, :lo12:tb3
    bl printf

    // Gọi hàm chuyển đổi và in dãy bit
    mov x0, x19
    bl _InDayBit

    // Kết thúc chương trình
    mov x0, #0
    mov x8, #93
    svc #0

// ======== Hàm chuyển đổi và in dãy bit ========

_InDayBit:
    mov x19, x0        
    cmp x19, #0
    b.ge _Positive      
    neg x19, x19       

_Positive:
    adrp x20, bin_str
    add x20, x20, :lo12:bin_str
    add x20, x20, #64  
    mov w21, #0      

_BitLoop:
    cmp x19, #0
    beq _PrintBits
    sub x20, x20, #1   
    and x22, x19, #1   
    add x22, x22, #'0' 
    strb w22, [x20]
    lsr x19, x19, #1  
    add w21, w21, #1  
    b _BitLoop

_PrintBits:
    cmp w21, #0
    bne _PrintBits_Continue
    sub x20, x20, #1
    mov w22, '0'
    strb w22, [x20]

_PrintBits_Continue:
    mov x0, x20
    bl printf

    // Xuất xuống dòng
    adrp x0, newline
    add x0, x0, :lo12:newline
    bl printf

    ret
