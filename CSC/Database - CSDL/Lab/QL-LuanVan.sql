create database DB_QuanLyLuanVan
go
use DB_QuanLyLuanVan
go

create table Khoa (
	MaKhoa char(5),
	TenKhoa nvarchar(30),
	GVTruongKhoa char(6),

	primary key (MaKhoa)
)

create table GiangVien (
	MaGV char(6),
	HoTen nvarchar(50),
	GioiTinh nchar(3),
	NgaySinh datetime,
	DiaChi nvarchar(50),
	ThuocKhoa char(5),

	primary key (MaGV)
)

create table SinhVien (
	MSSV char(7),
	HoTen nvarchar(50),
	GioiTinh nchar(3),
	NgaySinh datetime,
	DiaChi nvarchar(50),
	HocLop char(10),
	ThuocKhoa char(5),

	primary key (MSSV)
)

create table LuanVan (
	MaLV char(5),
	TenLV nvarchar(125),
	ThuocKhoa char(5),
	NamThucHien char(4),

	primary key (MaLV)
)

create table ThucHienLV (
	MaLV char(5),
	MaSVThucHien char(7),

	primary key (MaLV, MaSVThucHien)
)

create table BangDiem (
	MaLV char(5),
	MaSVThucHien char(7),
	MaGVDanhGia char(6),
	VaiTro nvarchar(20),
	Diem float,

	primary key (MaLV, MaSVThucHien, MaGVDanhGia)
)

alter table Khoa 
	add constraint fk_k_gv
	foreign key (gvtruongkhoa)
	references giangvien(magv)

alter table GiangVien 
	add constraint gk_gv_k
	foreign key (thuockhoa)
	references khoa(makhoa)

alter table SinhVien 
	add constraint fk_sv_k
	foreign key (thuockhoa)
	references khoa(makhoa)

alter table LuanVan 
	add constraint fk_lv_k
	foreign key (thuockhoa)
	references khoa(makhoa)

alter table ThucHienLV 
	add constraint fk_thlv_sv
	foreign key (masvthuchien)
	references sinhvien(mssv)

alter table ThucHienLV 
	add constraint fk_thlv_lv
	foreign key (malv)
	references luanvan(malv)

alter table BangDiem 
	add constraint fk_bd_gv
	foreign key (magvdanhgia)
	references giangvien(magv)

alter table BangDiem 
	add constraint fk_bd_thlv
	foreign key (malv, masvthuchien)
	references thuchienlv(malv, masvthuchien)

insert into khoa values ('CS', N'Khoa học máy tính', NULL)

INSERT INTO KHOA(MaKhoa,TenKhoa)
	VALUES ('CV', N'Thị giác máy tính'),
	('IS',N'Hệ thống thông tin'),
	('NC',N'Mạng máy tính'),
	('SE',N'Công nghệ phần mềm')
GO
INSERT INTO GiangVien VALUES
	('GV1001', N'Nguyễn Thùy Trâm', N'Nữ', '1970-06-29 00:00:00.000', N'16 CMT8 - TP HCM', 'IS'),
	('GV1002', N'Trần Trung Tín', N'Nam', '1980-09-17 00:00:00.000', N'22 Bạch Đằng - TP HCM', 'IS'),
	('GV1003', N'Vũ Nam Phong', N'Nam', '1978-05-04 00:00:00.000', N'556 XVNT - TP HCM', 'IS'),
	('GV1004', N'Lê Thị Ngọc Lan', N'Nữ', '1968-01-19 00:00:00.000', N'315 CMT8 - TP HCM', 'CS'),
	('GV1005', N'Phan Thị Lan Anh', N'Nữ', '1979-07-28 00:00:00.000', N'45 Pasteur - TP HCM', 'CS');
GO

INSERT INTO SinhVien VALUES
	('0512041', N'Nguyễn Nam', N'Nam', '1988-03-29 00:00:00.000', N'25 Lê Lợi - TP HCM', 'TH2004/01', 'IS'),
	('0512042', N'Trần Văn Duy', N'Nam', '1987-01-02 00:00:00.000', N'514 XVNT - TP HCM', 'TH2004/01', 'IS'),
	('0512043', N'Trần Diễm My', N'Nữ', '1988-01-20 00:00:00.000', N'227 CMT8 - TP HCM', 'TH2004/01', 'IS'),
	('0512044', N'Lê Văn Minh', N'Nam', '1988-10-01 00:00:00.000', N'78 Lê Lợi - TP HCM', 'TH2004/02', 'CS'),
	('0512045', N'Phạm Ngọc Thảo', N'Nữ', '1988-12-08 00:00:00.000', N'1 Bạch Đằng - TP HCM', 'TH2004/02', 'CS');
GO

UPDATE Khoa SET GVTruongKhoa = 'GV1004' WHERE MaKhoa= 'CS'
UPDATE Khoa SET GVTruongKhoa = 'GV1001' WHERE MaKhoa= 'IS'
GO

INSERT INTO LuanVan 
VALUES
	('0001', N'Bookstore Management Application', 'IS', 2009),
	('0002', N'E-learning Application', 'IS', 2009),
	('0003', N'Speed Processing Research', 'CS', 2009);
GO

INSERT INTO ThucHienLV 
VALUES
	('0001', '0512041'),
	('0001', '0512042'),
	('0002', '0512043'),
	('0003', '0512044'),
	('0003', '0512045');
GO


INSERT INTO BangDiem
VALUES
	('0001', '0512041', 'GV1001', N'Hướng dẫn', 8.5),
	('0001', '0512041', 'GV1002', N'Chủ tịch', 8.0),
	('0001', '0512041', 'GV1003', N'Phản biện', 8.0),
	('0001', '0512042', 'GV1001', N'Hướng dẫn', 8.5),
	('0001', '0512042', 'GV1002', N'Chủ tịch', 8.5),
	('0001', '0512042', 'GV1003', N'Phản biện', 9.0),
	('0002', '0512043', 'GV1001', N'Phản biện', 6.0),
	('0002', '0512043', 'GV1002', N'Hướng dẫn', 7.0),
	('0002', '0512043', 'GV1003', N'Chủ tịch', 7.5),
	('0003', '0512044', 'GV1001', N'Chủ tịch', 7.5),
	('0003', '0512044', 'GV1004', N'Hướng dẫn', 7.5),
	('0003', '0512044', 'GV1005', N'Phản biện', 7.5),
	('0003', '0512045', 'GV1001', N'Chủ tịch', 9.0),
	('0003', '0512045', 'GV1004', N'Hướng dẫn', 9.0),
	('0003', '0512045', 'GV1005', N'Phản biện', 8.5);
GO
