/*
Phần 1: Ghi chú thông tin sinh viên
- MSSV: 23120023
- Họ tên: Nguyễn Thái Bảo
- Lớp: 23CTT1
- Nhóm: N2
- Ca: 2
- Email: 23120023@student.hcmus.edu.vn
*/

-- use DB_QLDeTai_23120023
-- go

-- 1. Xuất ra toàn bộ danh sách giáo viên
create procedure sp_23120023_1
as
	select * from GIAOVIEN
go
exec sp_23120023_1

-- 2. Tính số lượng đề tài mà một giáo viên đang thực hiện
create procedure sp_23120023_2 @magv char(3)
as
	select count(distinct tg.MADT) as SLDT
	from GIAOVIEN gv left join THAMGIADT tg on gv.MAGV = tg.MAGV
	where gv.MAGV = @magv
	group by gv.MAGV
go
exec sp_23120023_2 '001'

-- 3. In thông tin chi tiết của 1 GV (dùng print): Thông tin cá nhân, Số lượng đề tài tham gia, Số lượng thân nhân
create procedure sp_23120023_3 @magv char(3)
as
	declare @hoten nvarchar(50),
			@phai nvarchar(3),
			@ngsinh date,
			@diachi nvarchar(100),
			@sldt int,
			@sltn int;

	select @hoten = HOTEN, @phai = PHAI, @ngsinh = NGSINH, @diachi = DIACHI
	from GIAOVIEN
	where MAGV = @magv

	select @sldt = count(distinct MADT)
	from THAMGIADT
	where MAGV = @magv

	select @sltn = count(*)
	from NGUOITHAN
	where MAGV = @magv

	print N'Thông tin chi tiết giáo viên:'
	print N'Họ tên: ' + @hoten
	PRINT N'Phái: ' + @Phai;
    PRINT N'Ngày sinh: ' + CONVERT(NVARCHAR, @ngsinh, 103);
    PRINT N'Địa chỉ: ' + @DiaChi;
    PRINT N'Số lượng đề tài tham gia: ' + CAST(@sldt AS NVARCHAR);
    PRINT N'Số lượng thân nhân: ' + CAST(@sltn AS NVARCHAR);
go
exec sp_23120023_3 '001'

drop procedure sp_23120023_3

-- 4. KIỂM TRA XEM 1 GV CÓ TỒN TẠI HAY KHÔNG
create procedure sp_23120023_4 @magv char(3)
as
	if (exists(select 1 from GIAOVIEN where MAGV = @magv))
		print N'Giáo viên tồn tại'
	else
		print N'Không tồn tại giáo viên ' + @magv + '!'
go
exec sp_23120023_4 '001'

-- 5. Kiểm tra quy định của 1 giáo viên: chỉ được thực hiện các đề tài mà bộ môn của giáo viên đó làm chủ nhiệm
create procedure sp_23120023_5 @magv char(3)
as
	declare @count int

	select @count = count(*)
	from GIAOVIEN gv
	join THAMGIADT tg on gv.MAGV = tg.MAGV
	join DETAI dt on tg.MADT = dt.MADT
	join GIAOVIEN cndt on dt.GVCNDT = cndt.MAGV
	where gv.MAGV = @magv and gv.MABM != cndt.MABM

	if (@count > 0)
		PRINT N'Giáo viên vi phạm: tham gia đề tài không thuộc bộ môn.';
    else
        PRINT N'Giáo viên thực hiện đúng quy định.';

go
exec sp_23120023_5 '001'
exec sp_23120023_5 '002'
exec sp_23120023_5 '003'
exec sp_23120023_5 '004'
exec sp_23120023_5 '005'


/*
6. Thực hiện thêm 1 phân công cho giáo viên thực hiện 1 công việc của đề tài:
a. Kiểm tra thông tin đầu vào hợp lệ: giáo viên, công việc phải tồn tại, thời gian tham gia > 0
b. Kiểm tra quy định ở câu 5
*/
create procedure sp_23120023_6 @magv char(3), @madt char(3), @stt int, @thoigian int
as
	declare @checkGV int, @checkCV int

	select @checkGV = count(*)
	from GIAOVIEN
	where MAGV = @magv

	if (@checkGV = 0) 
	begin
		print N'Giáo viên không tồn tại.'
		return
	end

	select @checkCV = count(*)
	from CONGVIEC
	where MADT = @madt and SOTT = @stt

	if (@checkCV = 0)
	begin
		print N'Công việc không tồn tại.'
		return
	end

	if (@thoigian <= 0)
	begin
		print N'Thời gian tham gia <= 0.'
		return
	end

	insert into THAMGIADT(MAGV, MADT, STT) values (@magv, @madt, @stt)
	print N'Phân công thành công!'

go
exec sp_23120023_6 '001', '006', 1, 5

-- 7. Thực hiện xóa một giáo viên theo mã. Nếu giáo viên có thông tin liên quan (có thân nhân, có làm đề tài, ...) thì báo lỗi
create procedure sp_23120023_7 @magv char(3)
as
	declare @checkGV int, @hasThanNhan int, @hasDT int

	select @checkGV = count(*)
	from GIAOVIEN
	where MAGV = @magv

	if (@checkGV = 0) 
	begin
		print N'Giáo viên không tồn tại.'
		return
	end

	select @hasThanNhan = count(*)
	from NGUOITHAN
	where MAGV = @magv

	if (@hasThanNhan = 0) 
	begin
		print N'Giáo viên có thân nhân - không thể xóa.'
		return
	end

	select @hasDT = count(*)
	from THAMGIADT
	where MAGV = @magv

	if (@hasDT = 0) 
	begin
		print N'Giáo viên có làm đề tài - không thể xóa.'
		return
	end

	delete from GIAOVIEN where MAGV = @magv
	print N'Giáo viên ' + @magv + N' đã được xóa thành công!'

go
exec sp_23120023_7 '009'

/*
8. In ra danh sách GV của một bộ môn nào đó cùng với SLĐT mà GV tham gia, số thân nhân, số GV mà GV đó quản lý nếu có, ...
*/
create procedure sp_23120023_8 @mabm nvarchar(4)
as
	select gv.MAGV, gv.HOTEN, count(distinct tg.MADT) as SoLuongDeTai,
	count(nt.ten) as SoLuongThanNhan, count(gv1.magv) as SoGVQuanLy
	from GIAOVIEN gv
	left join THAMGIADT tg on gv.MAGV = tg.MAGV
	left join NGUOITHAN nt on gv.MAGV = nt.MAGV
	left join GIAOVIEN gv1 on gv1.GVQLCM = gv.MAGV
	where gv.MABM = @mabm
	group by gv.MAGV, gv.HOTEN
go
exec sp_23120023_8 'HPT'

-- 9. Kiểm tra quy định 2 GV a, b: Nếu a là trưởng bộ môn c của b thì lương a phải cao hơn lương b (a, b: mã gv)
create procedure sp_23120023_9 @a char(3), @b char(3)
as
	declare @c nvarchar(4), @luongA decimal(5,1), @luongB decimal(5,1)

	select @luongA = LUONG
	from GIAOVIEN
	where MAGV = @a

	select @c = bm.TRUONGBM, @luongB = gv.LUONG
	from GIAOVIEN gv
	join BOMON bm on gv.MABM = bm.MABM
	where gv.MAGV = @b

	if (@c = NULL)
	begin
		print N'b không có trưởng bộ môn'
		return
	end
	else if (@c = @a)
	begin
		print N'a là trưởng bộ môn của b'
		if (@luongA > @luongB)
			begin
				print N'Thỏa quy định'
				return
			end
		else
			begin
				print N'Lương a không cao hơn lương b'
				return
			end
	end
	else
	begin
		print N'a không là trưởng bộ môn của b'
	end
go
exec sp_23120023_9 '002', '003'
	


-- 10. Thêm 1 GV: Kiểm tra các quy định: Không trùng tên, tuổi > 18, lương > 0
create procedure sp_23120023_10 @magv char(3), @hoten nvarchar(50), @ngsinh date, @luong decimal(5,1)
as
	if (exists(select 1 from GIAOVIEN where MAGV = @magv))
	begin
		print N'Giáo viên tồn tại'
		return
	end

	if (exists(select 1 from GIAOVIEN where @hoten = HOTEN))
	begin
		print N'Tên bị trùng'
		return
	end

	if (year(getdate()) - year(@ngsinh) <= 18)
	begin
		print N'Tuổi không lớn hơn 18'
		return
	end

	if (@luong <= 0)
	begin
		print N'Lương không lớn hơn 0'
		return
	end

	insert into GIAOVIEN(MAGV, HOTEN, NGSINH, LUONG) values (@magv, @hoten, @ngsinh, @luong)
	print N'Thêm giáo viên thành công!'

go
exec sp_23120023_10 '011', N'Nguyễn Thái Bảo', '04/27/2005', 1000

/*
11. Mã GV được xác định tự động theo quy tắc: Nếu đã có GV 001, 002, 003 thì mã GV của GV mới sẽ là 004.
Nếu đã có giáo viên 001, 002, 005 thì mã GV mới là 003.
*/

create procedure sp_23120023_11
as
	declare @i int = 1, @magv_new char(3)

	while exists (
		select 1
		from GIAOVIEN
		where MAGV = right('000' + cast(@i as varchar), 3)
	)
	begin
		set @i = @i + 1
	end

	set @magv_new = right('000' + cast(@i as varchar), 3)
	print N'Mã giáo viên mới: ' + @magv_new

go
exec sp_23120023_11

