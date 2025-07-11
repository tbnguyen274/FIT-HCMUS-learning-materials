/*
Phần 1: Ghi chú thông tin sinh viên
- MSSV: 23120023
- Họ tên: Nguyễn Thái Bảo
- Lớp: 23CTT1
- Nhóm: N2
- Ca: 2
- Email: 23120023@student.hcmus.edu.vn
*/

-- Lab G5 - Viết bằng truy vấn lồng

-- 1. Cho biết mức lương cao nhất của các giảng viên
select distinct gv.luong
from GIAOVIEN gv
where gv.luong >= ALL (select gv2.luong
						from giaovien gv2)

-- 2. Cho biết những giáo viên có lương lớn nhất
select gv.HOTEN
from GIAOVIEN gv
where gv.luong >= ALL (select gv2.luong
						from giaovien gv2) 

-- 3. Cho biết lương cao nhất trong bộ môn 'HTTT'
select distinct gv.luong
from GIAOVIEN gv
where gv.MABM = 'HTTT' and gv.luong >= ALL (select gv2.luong
											from giaovien gv2
											where gv2.MABM = 'HTTT')

-- 4. Cho biết tên giáo viên lớn tuổi nhất của bộ môn Hệ thống thông tin
select gv.HOTEN
from GIAOVIEN gv
where gv.MABM = (
	select bm.MABM
	from BOMON bm
	where bm.TENBM = N'Hệ thống thông tin'
)
and datediff(dd, gv.NGSINH, getdate()) = (
    select max(datediff(dd, gv2.NGSINH, getdate()))
    from GIAOVIEN gv2
    where gv2.MABM = gv.MABM
)

-- 5. Cho biết tên giáo viên nhỏ tuổi nhất khoa Công nghệ thông tin
select gv.HOTEN
from GIAOVIEN gv
where gv.MABM IN (
	select bm.MABM
	from BOMON bm
	where bm.MAKHOA = (
		select k.MAKHOA
		from KHOA k
		where k.TENKHOA = N'Công nghệ thông tin'
	)
)
and datediff(dd, gv.NGSINH, getdate()) = (
    select min(datediff(dd, gv2.NGSINH, getdate()))
    from GIAOVIEN gv2
    where gv2.MABM IN (
		select bm.MABM
		from BOMON bm
		where bm.MAKHOA = (
			select k.MAKHOA
			from KHOA k
			where k.TENKHOA = N'Công nghệ thông tin'
		)
	)
)

-- 6. Cho biết tên giáo viên và tên khoa của giáo viên có lương cao nhất
select gv.HOTEN, k.TENKHOA
from GIAOVIEN gv
join BOMON bm on gv.MABM = bm.MABM
join KHOA k on bm.MAKHOA = k.MAKHOA
where gv.luong = (
	select max(gv2.luong)
	from GIAOVIEN gv2
)

-- 7. Cho biết những giáo viên có lương lớn nhất trong bộ môn của họ
select gv.HOTEN
from GIAOVIEN gv
where gv.luong = (
	select max(gv2.luong)
	from GIAOVIEN gv2
	where gv2.MABM = gv.MABM
)

-- 8. Cho biết tên những đề tài mà giáo viên Nguyễn Hoài An chưa tham gia
select dt.TENDT
from DETAI dt
where dt.MADT not in (
	select tg.MADT
	from THAMGIADT tg
	where tg.MAGV = (
		select gv.MAGV
		from GIAOVIEN gv
		where gv.HOTEN = N'Nguyễn Hoài An'
	)
)

-- 9. Cho biết những đề tài mà giáo viên Nguyễn Hoài An chưa tham gia. Xuất ra tên đề tài, tên người chủ nhiệm đề tài.
select dt.TENDT, gv.HOTEN
from DETAI dt join GIAOVIEN gv on dt.GVCNDT = gv.MAGV
where dt.MADT not in (
	select tg.MADT
	from THAMGIADT tg
	where tg.MAGV = (
		select gv.MAGV
		from GIAOVIEN gv2
		where gv2.HOTEN = N'Nguyễn Hoài An'
	)
)

-- 10. Cho biết tên những giáo viên khoa Công nghệ thông tin mà chưa tham gia đề tài nào
select gv.HOTEN
from GIAOVIEN gv
join BOMON bm on gv.MABM = bm.MABM
where bm.MAKHOA = (
	select MAKHOA
	from KHOA
	where TENKHOA = N'Công nghệ thông tin'
)
and not exists (
	select 1
	from THAMGIADT tg
	where tg.MAGV = gv.MAGV
)

-- 11. Tìm những giáo viên không tham gia bất kỳ đề tài nào
select gv.HOTEN
from GIAOVIEN gv
where not exists (
	select 1
	from THAMGIADT tg
	where tg.MAGV = gv.MAGV
)

-- 12. Cho biết giáo viên có lương lớn hơn lương của giáo viên 'Nguyễn Hoài An'
select gv.HOTEN
from GIAOVIEN gv
where gv.luong > (
	select gv2.LUONG
	from GIAOVIEN gv2
	where gv2.HOTEN = N'Nguyễn Hoài An'
)

-- 13. Tìm những trưởng bộ môn tham gia tối thiểu 1 đề tài
select gv.HOTEN
from BOMON bm join GIAOVIEN gv on bm.TRUONGBM = gv.MAGV
where exists (
	select 1
	from THAMGIADT tg
	where tg.MAGV = bm.TRUONGBM
)

-- 14. Tìm giáo viên trùng tên và cùng giới tính với giáo viên khác trong cùng bộ môn
select gv.HOTEN
from GIAOVIEN gv
where exists (
	select 1
	from GIAOVIEN gv2
	where gv.MAGV != gv2.MAGV and gv.hoten = gv2.HOTEN and gv.PHAI = gv2.PHAI and gv.MABM = gv2.MABM
)

-- 15. Tìm những giáo viên có lương lớn hơn lương của ít nhất một giáo viên bộ môn 'Công nghệ phần mềm'
select gv.HOTEN
from GIAOVIEN gv
where gv.luong > any (
	select gv2.luong
	from GIAOVIEN gv2
	where gv2.MABM = (
		select bm.MABM
		from BOMON bm
		where bm.TENBM = N'Công nghệ phần mềm'
	)
)

-- 16. Tìm những giáo viên có lương lớn hơn lương của tất cả giáo viên thuộc bộ môn 'Hệ thống thông tin'
select gv.HOTEN
from GIAOVIEN gv
where gv.luong > all (
	select gv2.luong
	from GIAOVIEN gv2
	where gv2.MABM = (
		select bm.MABM
		from BOMON bm
		where bm.TENBM = N'Hệ thống thông tin'
	)
)
and exists (
	select 1
	from GIAOVIEN gv2
	where gv2.MABM = (
		select bm.MABM
		from BOMON bm
		where bm.TENBM = N'Hệ thống thông tin'
	)
)
