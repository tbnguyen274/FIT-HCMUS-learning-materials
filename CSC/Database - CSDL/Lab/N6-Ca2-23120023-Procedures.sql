/*
Phần 1: Ghi chú thông tin sinh viên
- MSSV: 23120023
- Họ tên: Nguyễn Thái Bảo
- Lớp: 23CTT1
- Nhóm: N2
- Ca: 2
- Email: 23120023@student.hcmus.edu.vn
*/

CREATE DATABASE QuanLyDatPhong;
GO
USE QuanLyDatPhong
GO

CREATE TABLE PHONG (
    MaPhong VARCHAR(10),
    TinhTrang NVARCHAR(4),
    LoaiPhong NVARCHAR(50),
    DonGia DECIMAL(10, 2)

	PRIMARY KEY(MaPhong)
)

CREATE TABLE KHACHHANG (
    MaKH VARCHAR(10),
    HoTen NVARCHAR(100),
    DiaChi NVARCHAR(200),
    DienThoai VARCHAR(20)

	PRIMARY KEY(MAKH)
)

CREATE TABLE DATPHONG (
    MaDP INT,
    MaKH VARCHAR(10),
    MaPhong VARCHAR(10),
    NgayDP DATE,
    NgayTra DATE,
    ThanhTien DECIMAL(10, 2)

	PRIMARY KEY (MaDP)
)

-- Tao rang buoc
ALTER TABLE PHONG
	ADD CONSTRAINT C_TINHTRANG
	CHECK (TINHTRANG IN (N'Rảnh', N'Bận'))

ALTER TABLE DATPHONG
	ADD CONSTRAINT FK_DP_KH
	FOREIGN KEY (MAKH)
	REFERENCES KHACHHANG(MAKH)

ALTER TABLE DATPHONG
	ADD CONSTRAINT FK_DP_P
	FOREIGN KEY (MAPHONG)
	REFERENCES PHONG(MAPHONG)

-- Nhap du lieu
INSERT INTO PHONG (MaPhong, TinhTrang, LoaiPhong, DonGia) VALUES
('P001', N'Rảnh', 'Standard', 500000),
('P002', N'Bận', 'Standard', 500000),
('P003', N'Rảnh', 'Deluxe', 800000),
('P004', N'Rảnh', 'Suite', 1200000),
('P005', N'Bận', 'Deluxe', 800000);

INSERT INTO KHACHHANG (MaKH, HoTen, DiaChi, DienThoai) VALUES
('KH001', N'Nguyễn Văn An', N'Hà Nội', '0912345678'),
('KH002', N'Trần Thị Bình', N'Hồ Chí Minh', '0923456789'),
('KH003', N'Lê Văn Cường', N'Đà Nẵng', '0934567890'),
('KH004', N'Phạm Thị Dung', N'Huế', '0945678901'),
('KH005', N'Hoàng Văn Em', N'Cần Thơ', '0956789012');

INSERT INTO DATPHONG (MaDP, MaKH, MaPhong, NgayDP, NgayTra, ThanhTien) VALUES
(1, 'KH001', 'P002', '2025-05-10', '2025-05-12', 1000000),
(2, 'KH002', 'P005', '2025-05-11', '2025-05-15', 3200000),
(3, 'KH003', 'P001', '2025-05-15', '2025-05-17', 2000000),
(4, 'KH004', 'P003', '2025-05-20', '2025-05-22', 3000000),
(5, 'KH005', 'P004', '2025-05-25', '2025-05-30', 4000000);

-- Ghi nhận thông tin đặt phòng của khách hành xuống CSDL
create procedure spDatPhong_23120023 @makh char(10), @maphong char(10), @ngaydat date
as
	-- Kiểm tra mã khách hàng hợp lệ
	if (not exists (select 1 from KHACHHANG where MaKH = @makh))
	begin
		print N'Mã khách hàng không tồn tại'
		return
	end

	-- Kiểm tra mã phòng hợp lệ
	if (not exists (select 1 from PHONG where MaPhong = @maphong))
	begin
		print N'Mã phòng không tồn tại'
		return
	end

	-- Kiểm tra tình trạng phòng
	if (exists(select 1 from PHONG where MaPhong = @maphong and TinhTrang != N'Rảnh'))
	begin
		print N'Phòng không rảnh, không thể đặt phòng'
		return
	end

	-- Phát sinh mã đặt phòng i = mã đặt phòng lớn nhất hiện tại + 1
	declare @i int
	select @i = max(madp) + 1
	from DATPHONG

	-- Các kiểm tra đã hợp lệ, ghi nhận thông tin
	insert into DATPHONG (MaDP, MaKH, MaPhong, NgayDP, NgayTra, ThanhTien)
	values (@i, @makh, @maphong, @ngaydat, NULL, NULL);
	print N'Đặt phòng thành công!'

	-- Sau khi đặt thành công thì cập nhật phòng bận
	update PHONG set TinhTrang = N'Bận' where MaPhong = @maphong

go
exec spDatPhong_23120023 'KH001', 'P001', '05/15/2025'
exec spDatPhong_23120023 'KH003', 'P003', '05/15/2025'
exec spDatPhong_23120023 'KH005', 'P004', '05/15/2025'