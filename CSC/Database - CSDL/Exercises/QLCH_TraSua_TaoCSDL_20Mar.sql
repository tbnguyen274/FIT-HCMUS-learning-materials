/*Các loại ràng buộc thuộc về bảng dữ liệu:
- Khoá: PRIMARY KEY(A1, A2, ...)
        UNIQUE(A1, A2, ...)
        FOREIGN KEY(X, Y) REFERENCES TAB
- Miền giá trị của 1 cột: NOT NULL
                          DEFAULT VAL
                          CHECK(EXPRESSION)
*/

/* Khai báo Ràng Buộc Toàn Vẹn
 - Đặt tên cho ràng buộc [CONSTRAINT TEN_CONSTRAINT] KHAI_BAO_RBTV 
 - Cú pháp khai báo:
    A) In-line declaration: Khai báo cùng khai báo thuộc tính 
    - Ràng buộc đặt trên 1 thuộc tính duy nhất
    - Dùng cho các loại: PK, UNIQUE, NOT NULL, DEFAULT, CHECK
    Create table tabName (
        columnA KDL PRIMARY KEY,
        columnB KDL NOT NULL UNIQUE CHECK (EXPRESSION) ...,
        columnC KDL DEFAULT Value CHECK(EXPRESION) ...
    )

    B) In-table declaration: Khai báo sau khi khai báo thuộc tính trong lệnh create table
    - Ràng buộc đặt trên nhiều thuộc tính của 1 bảng hoặc nhiều bảng (FK)
    - Dùng cho các loại: PK, UNIQUE, CHECK, FK (Lưu ý thứ tự tạo bảng)
    Create table tabName (
        columnA KDL,
        columnB KDL NOT NULL,
        columnC KDL DEFAULT VAL,
        columnD KDL,
        [constraint PK_tabName] PRIMARY KEY(columnA, columnC),
        [constraint UQ_tabName_colC_colD] UNIQUE(columnC, columnD),
        [constraint CK_tabName_colB] CHECK(columnB < columnA),
        [constraint FK_tabName] FOREIGN KEY (colA, colB) REFERENCES TabName2
    )
    C) Khai báo sau khi tạo bảng (ràng buộc trên nhiều bảng)
    - Dùng cho PK, UNIQUE, DEFAULT, CHECK, FK
    - Cho NULL/NOT NULL sử dụng Enable/Disable
    create table tabName ( ... )
    ALTER TABLE ADD [constraint Ten_RBTV] KHAI_BAO_RBTV

 - Vị trí có thể có cho các loại RBTV
    + In-line: NOT NULL, DEFAULT
              CHECK, PRIMARY KEY, UNIQUE (1 thuộc tính)
    + In-table: CHECK, PRIMARY KEY, UNIQUE, FOREIGN KEY
    + After table creation: CHECK, PRIMARY KEY, UNIQUE, FOREIGN KEY, DEFAULT (Alter table)
                            NULL/NOT NULL (Alter table XXX Alter colum AAA Data-type null/not null)
*/

CREATE DATABASE QLCH_TraSua;
GO

USE QLCH_TraSua;
GO

/*
    ĐỊNH NGHĨA CỚ SỞ DỮ LIỆU
*/

-- Tạo bảng LOAI_MON
CREATE TABLE LOAI_MON (
    MaLoai CHAR(1) PRIMARY KEY,
    TenLoai NVARCHAR(50) NOT NULL UNIQUE
);

-- Tạo bảng KHACH_HANG
CREATE TABLE KHACH_HANG (
    MaKH CHAR(4) PRIMARY KEY,
    TenKH NVARCHAR(100) NOT NULL,
    SDT VARCHAR(10) NOT NULL UNIQUE CHECK (SDT LIKE '0[0-9]%')
);

-- Tạo bảng NHAN_VIEN
CREATE TABLE NHAN_VIEN (
    MaNV CHAR(5) PRIMARY KEY,
    TenNV NVARCHAR(100) NOT NULL,
    GioiTinh NVARCHAR(3) CHECK (GioiTinh IN (N'Nam', N'Nữ')),
    SDT VARCHAR(10) NOT NULL UNIQUE CHECK (SDT LIKE '0[0-9]%'),
    DiaChi NVARCHAR(255),
    NguoiQL CHAR(5) NULL,
    CONSTRAINT FK_NhanVien_QL FOREIGN KEY (NguoiQL) REFERENCES NHAN_VIEN(MaNV)
);

-- Tạo bảng HOA_DON
CREATE TABLE HOA_DON (
    MaHD CHAR(5) PRIMARY KEY,
    MaKH CHAR(4) NOT NULL,
    MaNV CHAR(5) NOT NULL,
    ThoiGian DATE NOT NULL DEFAULT GETDATE(),
    TongTien DECIMAL(10,2) CHECK (TongTien >= 0),
    CONSTRAINT FK_HoaDon_KhachHang FOREIGN KEY (MaKH) REFERENCES KHACH_HANG(MaKH),
    CONSTRAINT FK_HoaDon_NhanVien FOREIGN KEY (MaNV) REFERENCES NHAN_VIEN(MaNV)
);

-- Tạo bảng CT_HD
CREATE TABLE CT_HD (
    MaHD CHAR(5),
    STT INT,
    MaMon CHAR(3) NOT NULL,
    SoLuong INT CHECK (SoLuong > 0),
    ThanhTien DECIMAL(10,2) CHECK (ThanhTien >= 0),
    PRIMARY KEY (MaHD, STT),
    CONSTRAINT FK_CT_HD_HoaDon FOREIGN KEY (MaHD) REFERENCES HOA_DON(MaHD)
);

-- Tạo bảng DS_MON
CREATE TABLE DS_MON (
    MaMon CHAR(3) PRIMARY KEY,
    TenMon NVARCHAR(100) NOT NULL,
    Gia DECIMAL(10,2) CHECK (Gia > 0),
    Loai CHAR(1) NOT NULL,
);

-- Minh hoạ khai báo RBTV sau khi tạo bảng
ALTER TABLE DS_MON 
ADD CONSTRAINT FK_DS_MON_Loai FOREIGN KEY (Loai) REFERENCES LOAI_MON(MaLoai)

ALTER TABLE CT_HD
ADD CONSTRAINT FK_CTHD_DSMON FOREIGN KEY (MaMon) REFERENCES DS_MON(MaMon)

/*
   NHẬP LIỆU

   Lưu ý thứ tự nhập liệu: Khoá chính phải tồn tại trước khoá ngoại 
   - Tồn tại tham chiếu khoá ngoại: Nhập bảng được tham chiếu (bảng cha) sau đó nhập bảng tham chiếu (chứa khoá ngoại)
   - Tham chiếu phản thân: Nhập khoá chính trước, thuộc tính khoá ngoại để NULL. Sau đó, quay lại nhập khoá ngoại
   - Khoá vòng: 
        1. Nhập một bảng trước nhưng chưa điền giá trị khóa vòng (các thuộc tính khoá ngoại) (NULL).
        2. Nhập bảng còn lại đầy đủ dữ liệu.
        3. Cập nhật lại khóa vòng của bảng đầu tiên.
*/
-- Nhập liệu LOAI_MON
INSERT INTO LOAI_MON (MaLoai, TenLoai) VALUES
('A', N'Cà phê'),
('B', N'Trà'),
('C', N'Tráng miệng');

-- Nhập liệu DS_MON sau khi  DS_MON đã có dữ liệu
INSERT INTO DS_MON (MaMon, TenMon, Gia, Loai) VALUES
('M01', N'Cà phê đen', 20000, 'A'),
('M02', N'Cà phê sữa', 25000, 'A'),
('M03', N'Trà đào cam sả', 35000, 'B'),
('M04', N'Matcha Latte', 45000, 'B'),
('M05', N'Bánh Donut', 25000, 'C'),
('M06', N'Bánh Flan', 20000, 'C'),
('M07', N'Trà tắc xí muội', 30000, 'B');

-- Nhập liệu KHACH_HANG
INSERT INTO KHACH_HANG (MaKH, TenKH, SDT) VALUES
('KH01', N'Trần Văn Quyết', '0909123123'),
('KH02', N'Nguyễn Lan Anh', '0909234234'),
('KH03', N'Phạm Mạnh Văn', '0909345345'),
('KH04', N'Đoàn Hà Nhi', '0909456456'),
('KH05', N'Trần Văn A', '0909888888');

-- Nhập liệu NHAN_VIEN có khoá phản thân SELF-REFERENCING FK 
-- Step 1: Nhập Dữ Liệu NHAN_VIEN (Bỏ Trống NguoiQL)
INSERT INTO NHAN_VIEN (MaNV, TenNV, GioiTinh, SDT, DiaChi) VALUES
('NV001', N'Trần Ánh Quỳnh', N'Nữ', '0908456456', N'Hồng Bàng, Quận 5'),
('NV002', N'Nguyễn Đông Bắc', N'Nam', '0908234234', N'Trường Chinh, Tân Bình'),
('NV003', N'Trần Văn Chí', N'Nam', '0908678678', N'Cao Thắng, Quận 5'),
('NV004', N'Phạm Thuỳ Chi', N'Nữ', '0908123123', N'Nguyễn Văn Cừ, Quận 5'),
('NV005', N'Nguyễn Ánh Chi', N'Nữ', '0908789789', N'Nguyễn Thị Thập, Quận 7');

-- Step 2: Cập Nhật NguoiQL Sau Khi Nhân Viên Đã Tồn Tại
UPDATE NHAN_VIEN SET NguoiQL = 'NV002' WHERE MaNV = 'NV001';
UPDATE NHAN_VIEN SET NguoiQL = 'NV004' WHERE MaNV = 'NV002';
UPDATE NHAN_VIEN SET NguoiQL = 'NV004' WHERE MaNV = 'NV003';
UPDATE NHAN_VIEN SET NguoiQL = 'NV002' WHERE MaNV = 'NV005';

-- Nhập liệu HOA_DON khi KHACH_HANG và NHAN_VIEN đã có dữ liệu
INSERT INTO HOA_DON (MaHD, MaKH, MaNV, ThoiGian, TongTien) VALUES
('HD01', 'KH01', 'NV005', '2022-01-09', 115000),
('HD02', 'KH03', 'NV003', '2022-01-17', 325000),
('HD03', 'KH04', 'NV002', '2022-01-25', 185000),
('HD40', 'KH02', 'NV001', '2022-02-20', 60000);

-- Nhập liệu CT_HD
INSERT INTO CT_HD (MaHD, STT, MaMon, SoLuong, ThanhTien) VALUES
('HD01', 1, 'M01', 2, 40000),
('HD01', 2, 'M05', 3, 75000),
('HD02', 1, 'M02', 3, 75000),
('HD02', 2, 'M04', 4, 180000),
('HD02', 3, 'M03', 2, 70000),
('HD03', 1, 'M04', 1, 45000),
('HD03', 2, 'M02', 2, 50000),
('HD03', 3, 'M01', 1, 20000),
('HD03', 4, 'M03', 2, 70000),
('HD40', 1, 'M07', 2, 60000);