/*
Phần 1: Ghi chú thông tin sinh viên
- MSSV: 23120023
- Họ tên: Nguyễn Thái Bảo
- Email: 23120023@student.hcmus.edu.vn
- Ngày làm bài: 29/3/2025
*/

-- Phần 2: Tạo CSDL
create database DB_QLDA_23120023
go
use DB_QLDA_23120023
go

-- Phần 3: Tạo schema
create table NHANVIEN
(
	HoNV nvarchar(15),
	TenLot nvarchar(15),
	TenNV nvarchar(15),
	MaNV nvarchar(9),
	NgSinh date,
	DChi nvarchar(30),
	Phai nvarchar(3),
	Luong float,
	Ma_NQL nvarchar(9),
	PHG int

	primary key(MaNV)
)

create table PHONGBAN
(
	TenPHG nvarchar(15),
	MaPHG int,
	TrPHG nvarchar(9),
	Ng_NhanChuc date

	primary key(MaPHG)
)

create table DIADIEM_PHG
(
	MaPHG int,
	DiaDiem nvarchar(15)

	primary key(MaPHG, DiaDiem)
)

create table DEAN
(
	TenDA nvarchar(15),
	MaDA int,
	Ddiem_DA nvarchar(15),
	Phong int

	primary key (MaDa)
)

create table CONGVIEC
(
	MaDa int,
	STT int,
	Ten_Cong_Viec nvarchar(50)

	primary key (MaDa, STT)
)

create table PHANCONG
(
	Ma_NVien nvarchar(9),
	MaDA int,
	STT int,
	ThoiGian decimal(5, 1)

	primary key (Ma_NVien, MaDA, STT)
)

create table THANNHAN
(
	Ma_NVien nvarchar(9),
	TenTN nvarchar(15),
	Phai nvarchar(3),
	NgSinh date,
	QuanHe nvarchar(15)

	primary key (Ma_NVien, TenTN)
)

-- Tạo ràng buộc

-- NHANVIEN
alter table NHANVIEN
	add constraint FK_Nhanvien_NQL
	foreign key (Ma_NQL)
	references NHANVIEN(MaNV)

alter table NHANVIEN
	add constraint FK_Nhanvien_PHG
	foreign key (PHG)
	references PHONGBAN(MaPHG)

alter table NHANVIEN
	add constraint c_nv_phai
	check (Phai in ('Nam', N'Nữ'))

alter table NHANVIEN
	add constraint c_nv_ngsinh
	check (NgSinh < getdate())

-- PHONGBAN
alter table PHONGBAN
	add constraint FK_Phongban_Nhanvien
	foreign key (TrPHG)
	references NHANVIEN(MaNV)

alter table PHONGBAN
	add constraint c_pb_ngaynhanchuc
	check (Ng_NhanChuc < getdate())

-- DIADIEM_PHG
alter table DIADIEM_PHG
	add constraint FK_DiadiemPHG_Phongban
	foreign key (MaPHG)
	references PHONGBAN(MaPHG) 

-- DEAN
alter table DEAN
	add constraint FK_Dean_Phongban
	foreign key (Phong)
	references PHONGBAN(MaPHG) 

-- CONGVIEC
alter table CONGVIEC
	add constraint FK_Congviec_Dean
	foreign key (MaDA)
	references DEAN(MaDA)
	
-- PHANCONG
alter table PHANCONG
	add constraint FK_Phancong_Nhanvien
	foreign key (Ma_NVien)
	references NHANVIEN(MaNV) 

alter table PHANCONG
	add constraint FK_Phancong_Congviec
	foreign key (MaDA, STT)
	references CONGVIEC(MaDA, STT)

alter table PHANCONG
	add constraint c_pc_thoigian
	check (ThoiGian >= 0)

-- THANNHAN
alter table THANNHAN
	add constraint FK_Thannhan_Nhanvien
	foreign key (Ma_NVien)
	references NHANVIEN(MaNV)

alter table NHANVIEN
	add constraint c_tn_ngsinh
	check (NgSinh < getdate())

alter table NHANVIEN
	add constraint c_tn_phai
	check (Phai in ('Nam', N'Nữ'))
	

-- Phần 4: Nhập liệu
insert into NHANVIEN values (N'Đinh', N'Bá', N'Tiến', '009', '02/11/1960', N'119 Cổng Quỳnh, Tp HCM', 'Nam', 30000, NULL, NULL)
insert into NHANVIEN values (N'Nguyễn', N'Thanh', N'Tùng', '005', '08/20/1962', N'222 Nguyễn Văn Cừ, Tp HCM', 'Nam', 40000, NULL, NULL)
insert into NHANVIEN values (N'Bùi', N'Ngọc', N'Hằng', '007', '03/11/1954', N'332 Nguyễn Thái Học, Tp HCM', 'Nam', 25000, NULL, NULL)
insert into NHANVIEN values (N'Lê', N'Quỳnh', N'Như', '001', '02/01/1967', N'291 Hồ Văn Huê, Tp HCM', N'Nữ', 43000, NULL, NULL)
insert into NHANVIEN values (N'Nguyễn', N'Mạng', N'Hùng', '004', '03/14/1967', N'95 Bà Rịa, Vũng Tàu', 'Nam', 38000, NULL, NULL)
insert into NHANVIEN values (N'Trần', N'Thanh', N'Tâm', '003', '05/04/1957', N'34 Mai Thị Lự, Tp HCM', 'Nam', 25000, NULL, NULL)
insert into NHANVIEN values (N'Trần', N'Hồng', N'Quang', '008', '09/01/1967', N'80 Lê Hồng Phong, Tp HCM', 'Nam', 25000, NULL, NULL)
insert into NHANVIEN values (N'Phạm', N'Văn', N'Vinh', '006', '01/01/1965', N'45 Trưng Vương, Hà Nội', N'Nữ', 55000, NULL, NULL)

update NHANVIEN set Ma_NQL = '005' where MaNV = '009'
update NHANVIEN set Ma_NQL = '006' where MaNV = '005'
update NHANVIEN set Ma_NQL = '001' where MaNV = '007'
update NHANVIEN set Ma_NQL = '006' where MaNV = '001'
update NHANVIEN set Ma_NQL = '005' where MaNV = '004'
update NHANVIEN set Ma_NQL = '005' where MaNV = '003'
update NHANVIEN set Ma_NQL = '001' where MaNV = '008'

insert into PHONGBAN values (N'Nghiên cứu', 5 , '005', '05/22/1978')
insert into PHONGBAN values (N'Điều hành', 4 , '008', '01/01/1985')
insert into PHONGBAN values (N'Quản lý', 1 , '006', '06/19/1971')

update NHANVIEN set PHG = 5 where MaNV = '009'
update NHANVIEN set PHG = 5 where MaNV = '005'
update NHANVIEN set PHG = 4 where MaNV = '007'
update NHANVIEN set PHG = 4 where MaNV = '001'
update NHANVIEN set PHG = 5 where MaNV = '004'
update NHANVIEN set PHG = 5 where MaNV = '003'
update NHANVIEN set PHG = 4 where MaNV = '008'
update NHANVIEN set PHG = 1 where MaNV = '006'

insert into DIADIEM_PHG values (1, 'TP HCM')
insert into DIADIEM_PHG values (4, N'Hà Nội')
insert into DIADIEM_PHG values (5, N'Vũng Tàu')
insert into DIADIEM_PHG values (5, 'Nha Trang')
insert into DIADIEM_PHG values (5, 'TP HCM')

insert into DEAN values (N'Sản phẩm X', 1, N'Vũng Tàu', 5)
insert into DEAN values (N'Sản phẩm Y', 2, N'Nha Trang', 5)
insert into DEAN values (N'Sản phẩm Z', 3, N'TP HCM', 5)
insert into DEAN values (N'Tin học hóa', 10, N'Hà Nội', 4)
insert into DEAN values (N'Cáp quang', 20, N'TP HCM', 1)
insert into DEAN values (N'Đào tạo', 30, N'Hà Nội', 4)

insert into CONGVIEC values (1, 1, N'Thiết kế sản phẩm X')
insert into CONGVIEC values (1, 2, N'Thử nghiệm sản phẩm X')
insert into CONGVIEC values (2, 1, N'Sản xuất sản phẩm Y')
insert into CONGVIEC values (2, 2, N'Quảng cáo sản phẩm Y')
insert into CONGVIEC values (3, 1, N'Khuyến mãi sản phẩm Z')
insert into CONGVIEC values (10, 1, N'Tin học hóa nhân sự tiền lương')
insert into CONGVIEC values (10, 2, N'Tin học hóa phòng kinh doanh')
insert into CONGVIEC values (20, 1, N'Lắp đặt cáp quang khu B')
insert into CONGVIEC values (30, 1, N'Đào tạo nhân viên Marketing')
insert into CONGVIEC values (30, 2, N'Đào tạo chuyên viên thiết kế')

insert into PHANCONG values ('009', 1, 1, 32)
insert into PHANCONG values ('009', 2, 2, 8)
insert into PHANCONG values ('004', 3, 1, 40)
insert into PHANCONG values ('003', 1, 2, 20.0)
insert into PHANCONG values ('003', 2, 1, 20.0)
insert into PHANCONG values ('008', 10, 1, 35)
insert into PHANCONG values ('008', 30, 2, 5)
insert into PHANCONG values ('001', 30, 1, 20)
insert into PHANCONG values ('001', 20, 1, 15)
insert into PHANCONG values ('006', 20, 1, 30)
insert into PHANCONG values ('005', 3, 1, 10)
insert into PHANCONG values ('005', 10, 2, 10)
insert into PHANCONG values ('005', 20, 1, 10)
insert into PHANCONG values ('007', 30, 2, 30)
insert into PHANCONG values ('007', 10, 2, 10)

insert into THANNHAN values ('005', N'Trinh', N'Nữ', '04/05/1976', N'Con gái')
insert into THANNHAN values ('005', N'Khang', N'Nam', '10/25/1973', 'Con trai')
insert into THANNHAN values ('005', N'Phương', N'Nữ', '05/03/1948', N'Vợ chồng')
insert into THANNHAN values ('001', N'Minh', N'Nam', '02/29/1932', N'Vợ chồng')
insert into THANNHAN values ('009', N'Tiến', N'Nam', '01/01/1978', 'Con trai')
insert into THANNHAN values ('009', N'Châu', N'Nữ', '12/30/1978', N'Con gái')
insert into THANNHAN values ('009', N'Phương', N'Nữ', '05/05/1957', N'Vợ chồng')

-- Kiểm tra --
select * from NHANVIEN
select * from PHONGBAN
select * from DIADIEM_PHG
select * from DEAN
select * from CONGVIEC
select * from PHANCONG
select * from THANNHAN


