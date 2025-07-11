/*
Phần 1: Ghi chú thông tin sinh viên
- MSSV: 23120023
- Họ tên: Nguyễn Thái Bảo
- Lớp: 23CTT1
- Nhóm: N2
- Ca: 2
- Email: 23120023@student.hcmus.edu.vn
*/

/*
	H5 - Phép chia
	Viết bằng 3 - 4 cách cho cùng 1 câu truy vấn
*/

use DB_QLDeTai_23120023
go

-- 1. Cho biết tên giáo viên nào mà tham gia đề tài đủ tất cả các chủ đề

-- except
select gv.HOTEN
from GIAOVIEN gv
where not exists (
	(
		select cd.MACD
		from CHUDE cd
	)
	except
	(
		select dt.MACD
		from DETAI dt join THAMGIADT tg on dt.MADT = tg.MADT
		where tg.MAGV = gv.MAGV
	)
)

-- not exists
select gv.HOTEN
from GIAOVIEN gv
where not exists (
	select 1
	from CHUDE cd
	where not exists (
		select 1
		from DETAI dt join THAMGIADT tg on dt.MADT = tg.MADT
		where gv.MAGV = tg.MAGV and cd.MACD = dt.MACD
	)
)

-- count
select gv.HOTEN
from GIAOVIEN gv
join THAMGIADT tg on gv.MAGV = tg.MAGV
join DETAI dt on tg.MADT = dt.MADT
group by gv.MAGV, gv.HOTEN
having count(distinct dt.macd) = (
	select count(*)
	from CHUDE
)

-- 2. Cho biết tên đề tài nào mà được tất cả các giáo viên của bộ môn HTTT tham gia
select dt.TENDT
from DETAI dt
where not exists (
	select gv.MAGV
	from GIAOVIEN gv
	where gv.MABM = 'HTTT'

	except

	select gv2.MAGV
	from GIAOVIEN gv2 join THAMGIADT tg on gv2.MAGV = tg.MAGV
	where gv2.MABM = 'HTTT' and dt.MADT = tg.MADT
)

-- C2:
select dt.TENDT
from DETAI dt
where not exists (
	select 1
	from GIAOVIEN gv
	where gv.MABM = 'HTTT' 
	and not exists (
		select 1
		from THAMGIADT tg
		where tg.MADT = dt.MADT and tg.MAGV = gv.MAGV
	)
)

-- C3:
select dt.TENDT
from DETAI dt join THAMGIADT tg on dt.MADT = tg.MADT
			  join GIAOVIEN gv on tg.MAGV = gv.MAGV
where gv.MABM = 'HTTT'
group by tg.MADT, dt.TENDT
having count(distinct tg.MAGV) = (
	select count(*)
	from GIAOVIEN gv2
	where gv2.MABM = 'HTTT'
)

-- 3. Cho biết tên đề tài có tất cả giảng viên bộ môn 'Hệ thống thông tin' tham gia
-- C1
select dt.TENDT
from DETAI dt
where not exists (
	select gv.MAGV
	from GIAOVIEN gv join BOMON bm on gv.MABM = bm.MABM
	where bm.TENBM = N'Hệ thống thông tin'

	except

	select tg.MAGV
	from THAMGIADT tg
	where tg.MAGV in (
		select gv2.MAGV
		from GIAOVIEN gv2 join BOMON bm2 on gv2.MABM = bm2.MABM
		where bm2.TENBM = N'Hệ thống thông tin'
	)
	and tg.MADT = dt.MADT
)

-- C2:
select dt.TENDT
from DETAI dt
where not exists (
	select 1
	from GIAOVIEN gv join BOMON bm on gv.MABM = bm.MABM
	where bm.TENBM = N'Hệ thống thông tin'
	and not exists (
		select 1
		from THAMGIADT tg
		where tg.magv = gv.MAGV and tg.MADT = dt.MADT
	)
)

-- C3:
select dt.TENDT
from DETAI dt
join THAMGIADT tg on dt.MADT = tg.MADT
join GIAOVIEN gv on tg.MAGV = gv.MAGV
join BOMON bm on gv.MABM = bm.MABM
where bm.TENBM = N'Hệ thống thông tin'
group by dt.MADT, dt.TENDT
having count (distinct tg.MAGV) = (
	select count(*)
	from GIAOVIEN gv2 join BOMON bm2 on gv2.MABM = bm2.MABM
	where bm2.TENBM = N'Hệ thống thông tin'
)


-- 4. Cho biết giáo viên nào đã tham gia tất cả các đề tài có mã chủ đề là QLGD
-- C1:
select gv.HOTEN
from GIAOVIEN gv
where not exists (
	select dt.MADT
	from DETAI dt
	where dt.MACD = 'QLGD'

	except

	select tg.MADT
	from THAMGIADT tg
	where tg.MAGV = gv.MAGV
	and tg.MADT in (
		select dt2.MADT
		from DETAI dt2
		where dt2.MACD = 'QLGD'
	)
)

-- C2:
select gv.HOTEN
from GIAOVIEN gv
where not exists (
	select 1
	from DETAI dt
	where dt.MACD = 'QLGD'
	and not exists (
		select 1
		from THAMGIADT tg
		where tg.MADT = dt.MADT and tg.MAGV = gv.MAGV
	)
)

-- C3:
select gv.HOTEN
from GIAOVIEN gv
join THAMGIADT tg on gv.MAGV = tg.MAGV
join DETAI dt on tg.MADT = dt.MADT
where dt.MACD = 'QLGD'
group by gv.MAGV, gv.HOTEN
having count(distinct dt.madt) = (
	select count(*)
	from DETAI dt2
	where dt2.MACD = 'QLGD'
)

-- 5. Cho biết tên giáo viên nào tham gia tất cả các đề tài mà giáo viên Trần Trà Hương đã tham gia
-- C1:
select gv.HOTEN
from GIAOVIEN gv
where gv.HOTEN != N'Trần Trà Hương'
and not exists (
	select distinct tg.MADT
	from THAMGIADT tg join GIAOVIEN gv2 on tg.MAGV = gv2.MAGV
	where gv2.HOTEN = N'Trần Trà Hương'

	except

	select tg2.MADT
	from THAMGIADT tg2
	where tg2.MAGV = gv.MAGV
)

-- C2:
select gv.HOTEN
from GIAOVIEN gv
where gv.HOTEN != N'Trần Trà Hương'
and not exists (
	select 1
	from THAMGIADT tg join GIAOVIEN gv2 on tg.MAGV = gv2.MAGV
	where gv2.HOTEN = N'Trần Trà Hương'
	and not exists (
		select 1
		from THAMGIADT tg2
		where tg2.madt = tg.MADT and tg2.MAGV = gv.MAGV
	)
)

-- C3:
select gv.HOTEN
from GIAOVIEN gv
join THAMGIADT tg on gv.MAGV = tg.MAGV
where gv.HOTEN != N'Trần Trà Hương'
and tg.MADT in (
	select tg2.MADT
	from THAMGIADT tg2 join GIAOVIEN gv2 on tg2.MAGV = gv2.MAGV
	where gv2.HOTEN = N'Trần Trà Hương'
)
group by gv.MAGV, gv.HOTEN
having count(distinct tg.MADT) = (
	select distinct tg3.MADT
	from THAMGIADT tg3 join GIAOVIEN gv3 on tg3.MAGV = gv3.MAGV
	where gv3.HOTEN = N'Trần Trà Hương'
)

-- 6. Cho biết tên đề tài nào mà được tất cả các giáo viên của bộ môn Hóa Hữu Cơ tham gia
-- C1:
select dt.TENDT
from DETAI dt
where not exists (
	select gv.MAGV
	from GIAOVIEN gv join BOMON bm on gv.MABM = bm.MABM
	where bm.TENBM = N'Hóa hữu cơ'

	except

	select tg.MAGV
	from THAMGIADT tg
	where tg.MADT = dt.MADT
)

-- C2:
select dt.TENDT
from DETAI dt
where not exists (
	select 1
	from GIAOVIEN gv join BOMON bm on gv.MABM = bm.MABM
	where bm.TENBM = N'Hóa hữu cơ'
	and not exists (
		select 1
		from THAMGIADT tg
		where tg.MAGV = gv.MAGV and tg.MADT = dt.MADT
	)
)

-- C3:
select dt.TENDT
from DETAI dt
join THAMGIADT tg on dt.MADT = tg.MADT
join GIAOVIEN gv on tg.MAGV = gv.MAGV
join BOMON bm on gv.MABM = bm.MABM
where bm.TENBM = N'Hóa hữu cơ'
group by dt.MADT, dt.TENDT
having count(distinct gv.magv) = (
	select count(gv2.magv)
	from GIAOVIEN gv2 join BOMON bm2 on gv2.MABM = bm2.MABM
	where bm2.TENBM = N'Hóa hữu cơ'
)

-- 7. Cho biết tên giáo viên nào mà tham gia tất cả các công việc của đề tài 006
-- C1:
select gv.HOTEN
from GIAOVIEN gv
where not exists (
	select cv. MADT, cv.SOTT
	from CONGVIEC cv
	where cv.MADT = '006'

	except

	select tg.MADT, tg.STT
	from THAMGIADT tg
	where tg.MAGV = gv.MAGV
)

-- C2:
select gv.HOTEN
from GIAOVIEN gv
where not exists (
	select 1
	from CONGVIEC cv
	where cv.MADT = '006'
	and not exists (
		select 1
		from THAMGIADT tg
		where tg.MADT = cv.MADT and tg.STT = cv.SOTT and tg.MAGV = gv.MAGV
	)
)

-- C3:
select gv.HOTEN
from GIAOVIEN gv
join THAMGIADT tg on gv.MAGV = tg.MAGV
where tg.MADT = '006'
group by gv.MAGV, gv.HOTEN
having count (distinct tg.STT) = (
	select count(cv.sott)
	from CONGVIEC cv
	where cv.MADT = '006'
)

-- 8. Cho biết giáo viên nào đã tham gia tất cả các đề tài của chủ đề Ứng dụng công nghệ
-- C1:
select gv.HOTEN
from GIAOVIEN gv
where not exists (
	select dt.MADT
	from DETAI dt join CHUDE cd on dt.MACD = cd.MACD
	where cd.TENCD = N'Ứng dụng công nghệ'

	except

	select tg.MADT
	from THAMGIADT tg
	where tg.MAGV = gv.MAGV
)

-- C2:
select gv.HOTEN
from GIAOVIEN gv
where not exists (
	select 1
	from DETAI dt join CHUDE cd on dt.MACD = cd.MACD
	where cd.TENCD = N'Ứng dụng công nghệ'
	and not exists (
		select 1
		from THAMGIADT tg
		where tg.MADT = dt.MADT and tg.MAGV = gv.MAGV
	)
)

-- C3:
select gv.HOTEN
from GIAOVIEN gv
join THAMGIADT tg on gv.MAGV = tg.MAGV
join DETAI dt on tg.MADT = dt.MADT
join CHUDE cd on dt.MACD = cd.MACD
where cd.TENCD = N'Ứng dụng công nghệ'
group by gv.MAGV, gv.HOTEN
having count (distinct dt.madt) = (
	select count(dt2.madt)
	from DETAI dt2 join CHUDE cd2 on dt2.MACD = cd2.MACD
	where cd2.TENCD = N'Ứng dụng công nghệ'
)

-- 9. Cho biết tên giáo viên nào đã tham gia tất cả các đề tài do Trần Trà Hương làm chủ nhiệm
-- C1:
select gv.HOTEN
from GIAOVIEN gv
where not exists (
	select dt.MADT
	from DETAI dt join GIAOVIEN gv2 on dt.GVCNDT = gv2.MAGV
	where gv2.HOTEN = N'Trần Trà Hương'

	except

	select tg.MADT
	from THAMGIADT tg
	where tg.MAGV = gv.MAGV
)

-- C2:
select gv.HOTEN
from GIAOVIEN gv
where not exists (
	select 1
	from DETAI dt join GIAOVIEN gv2 on dt.GVCNDT = gv2.MAGV
	where gv2.HOTEN = N'Trần Trà Hương'
	and not exists (
		select 1
		from THAMGIADT tg
		where tg.MADT = dt.MADT and tg.MAGV = gv.MAGV
	)
)

-- C3:
select gv.HOTEN
from GIAOVIEN gv
join THAMGIADT tg on gv.MAGV = tg.MAGV
where tg.MADT in (
	select dt.MADT
	from DETAI dt join GIAOVIEN gv2 on dt.GVCNDT = gv2.MAGV
	where gv2.HOTEN = N'Trần Trà Hương'
)
group by gv.MAGV, gv.HOTEN
having count (distinct tg.madt) = (
	select count(dt.madt)
	from DETAI dt join GIAOVIEN gv2 on dt.GVCNDT = gv2.MAGV
	where gv2.HOTEN = N'Trần Trà Hương' 
)

-- 10. Cho biết tên đề tài nào mà được tất cả các giáo viên của khoa CNTT tham gia
-- C1:
select dt.TENDT
from DETAI dt
where not exists (
	select gv.MAGV
	from GIAOVIEN gv join BOMON bm on gv.MABM = bm.MABM
	where bm.MAKHOA = 'CNTT'

	except

	select tg.MAGV
	from THAMGIADT tg
	where tg.MADT = dt.MADT
)

-- C2:
select dt.TENDT
from DETAI dt
where not exists (
	select 1
	from GIAOVIEN gv join BOMON bm on gv.MABM = bm.MABM
	where bm.MAKHOA = 'CNTT'
	and not exists (
		select 1
		from THAMGIADT tg
		where tg.MAGV = gv.MAGV and tg.MADT = dt.MADT
	)
)

-- C3:
select dt.TENDT
from DETAI dt
join THAMGIADT tg on dt.MADT = tg.MADT
join GIAOVIEN gv on gv.MAGV = tg.MAGV
join BOMON bm on gv.MABM = bm.MABM
where bm.MAKHOA = 'CNTT'
group by dt.MADT, dt.TENDT
having count (distinct gv.magv) = (
	select count(gv2.magv)
	from GIAOVIEN gv2 join BOMON bm2 on gv2.MABM = bm2.MABM
	where bm2.MAKHOA = 'CNTT'
)

-- 11. Cho biết tên giáo viên nào mà tham gia tất cả các công việc của đề tài Nghiên cứu tế bào gốc
-- C1:
select gv.HOTEN
from GIAOVIEN gv
where not exists (
	select cv.MADT, cv.SOTT
	from CONGVIEC cv join DETAI dt on cv.MADT = dt.MADT
	where dt.TENDT = N'Nghiên cứu tế bào gốc'

	except

	select tg.MADT, tg.STT
	from THAMGIADT tg
	where tg.MAGV = gv.MAGV
)

-- C2:
select gv.HOTEN
from GIAOVIEN gv
where not exists (
	select 1
	from CONGVIEC cv join DETAI dt on cv.MADT = dt.MADT
	where dt.TENDT = N'Nghiên cứu tế bào gốc'
	and not exists (
		select 1
		from THAMGIADT tg
		where tg.MADT = cv.MADT and tg.STT = cv.SOTT and tg.MAGV = gv.MAGV
	)
)

-- C3:
select gv.HOTEN
from GIAOVIEN gv
join THAMGIADT tg on gv.MAGV = tg.MAGV
join DETAI dt on tg.MADT = dt.MADT
where dt.TENDT = N'Nghiên cứu tế bào gốc'
group by gv.MAGV, gv.HOTEN
having count (distinct tg.STT) = (
	select count (cv.sott)
	from CONGVIEC cv join DETAI dt2 on cv.MADT = dt2.MADT
	where dt2.TENDT = N'Nghiên cứu tế bào gốc'
)

-- 12. Tìm tên các giáo viên được phân công làm tất cả các đề tài có kinh phí trên 100 triệu
-- C1:
select gv.HOTEN
from GIAOVIEN gv
where not exists (select dt.MADT 
				  from DETAI dt
				  where dt.KINHPHI > 100
				  
				  except
				  
				  select tg.MADT
				  from THAMGIADT tg
				  where tg.MAGV = gv.MAGV)

-- C2:
select gv.HOTEN
from GIAOVIEN gv
where not exists (
	select 1
	from DETAI dt
	where dt.KINHPHI > 100
	and not exists (
		select 1
		from THAMGIADT tg
		where tg.MADT = dt.MADT and tg.MAGV = gv.MAGV
	)
)

-- C3:
select gv.HOTEN
from GIAOVIEN gv
join THAMGIADT tg on gv.MAGV = tg.MAGV
join DETAI dt on tg.MADT = dt.MADT
where dt.KINHPHI > 100
group by gv.MAGV, gv.HOTEN
having count (distinct dt.madt) = (
	select count(*)
	from DETAI dt2
	where dt2.KINHPHI > 100
)

-- 13. Cho biết tên đề tài nào mà được tất cả các giáo viên của khoa Sinh Học tham gia
-- C1:
select dt.TENDT
from DETAI dt
where not exists (
	select gv.MAGV
	from GIAOVIEN gv 
	join BOMON bm on gv.MABM = bm.MABM
	join KHOA k on bm.MAKHOA = k.MAKHOA
	where k.TENKHOA = N'Sinh học'

	except

	select tg.MAGV
	from THAMGIADT tg
	where tg.MADT = dt.MADT
)

-- C2:
select dt.TENDT
from DETAI dt
where not exists (
	select 1
	from GIAOVIEN gv 
	join BOMON bm on gv.MABM = bm.MABM
	join KHOA k on bm.MAKHOA = k.MAKHOA
	where k.TENKHOA = N'Sinh học'
	and not exists (
		select 1
		from THAMGIADT tg
		where tg.MAGV = gv.MAGV and tg.MADT = dt.MADT
	)
)

-- C3:
select dt.TENDT
from DETAI dt
join THAMGIADT tg on dt.MADT = tg.MADT
join GIAOVIEN gv on gv.MAGV = tg.MAGV
join BOMON bm on gv.MABM = bm.MABM
join KHOA k on bm.MAKHOA = k.MAKHOA
where k.TENKHOA = N'Sinh học'
group by dt.MADT, dt.TENDT
having count (distinct gv.magv) = (
	select count(gv2.magv)
	from GIAOVIEN gv2
	join BOMON bm2 on gv2.MABM = bm2.MABM
	join KHOA k2 on bm2.MAKHOA = k2.MAKHOA
	where k2.TENKHOA = N'Sinh học'
)

-- 14. Cho biết mã số, họ tên, ngày sinh của giáo viên tham gia tất cả các công việc của đề tài 'Ứng dụng hóa học xanh'
-- C1:
select gv.MAGV, gv.HOTEN, gv.NGSINH
from GIAOVIEN gv
where not exists (
	select cv.MADT, cv.SOTT
	from CONGVIEC cv join DETAI dt on cv.MADT = dt.MADT
	where dt.TENDT = N'Ứng dụng hóa học xanh'

	except

	select tg.MADT, tg.STT
	from THAMGIADT tg
	where tg.MAGV = gv.MAGV
)
and exists (
	select cv.MADT, cv.SOTT
	from CONGVIEC cv join DETAI dt on cv.MADT = dt.MADT
	where dt.TENDT = N'Ứng dụng hóa học xanh'
)

-- C2:
select gv.MAGV, gv.HOTEN, gv.NGSINH
from GIAOVIEN gv
where not exists (
	select 1
	from CONGVIEC cv join DETAI dt on cv.MADT = dt.MADT
	where dt.TENDT = N'Ứng dụng hóa học xanh'
	and not exists (
		select 1
		from THAMGIADT tg
		where tg.MADT = cv.MADT and tg.STT = cv.SOTT and tg.MAGV = gv.MAGV
	)
)
and exists (
	select cv.MADT, cv.SOTT
	from CONGVIEC cv join DETAI dt on cv.MADT = dt.MADT
	where dt.TENDT = N'Ứng dụng hóa học xanh'
)

-- C3:
select gv.MAGV, gv.HOTEN, gv.NGSINH
from GIAOVIEN gv
join THAMGIADT tg on gv.MAGV = tg.MAGV
join DETAI dt on tg.MADT = dt.MADT
where dt.TENDT = N'Ứng dụng hóa học xanh'
group by gv.MAGV, gv.HOTEN, gv.NGSINH
having count (distinct tg.STT) = (
	select count (cv.sott)
	from CONGVIEC cv join DETAI dt2 on cv.MADT = dt2.MADT
	where dt2.TENDT = N'Ứng dụng hóa học xanh'
)

-- 15. Cho biết mã số, họ tên, tên bộ môn và tên người quản lý chuyên môn của giáo viên tham gia tất cả các đề tài thuộc
-- chủ đề 'Nghiên cứu phát triển'
-- C1:
select gv.MAGV, gv.HOTEN, bm.TENBM, ql.HOTEN as TenNQL
from GIAOVIEN gv
join BOMON bm on gv.MABM = bm.MABM
join GIAOVIEN ql on gv.GVQLCM = ql.MAGV
where not exists (
	select dt.MADT
	from DETAI dt join CHUDE cd on dt.MACD = cd.MACD
	where cd.TENCD = N'Nghiên cứu phát triển'

	except

	select tg.MADT
	from THAMGIADT tg
	where tg.MAGV = gv.MAGV
)
and exists (
	select 1
	from DETAI dt join CHUDE cd on dt.MACD = cd.MACD
	where cd.TENCD = N'Nghiên cứu phát triển'
)

-- C2:
select gv.MAGV, gv.HOTEN, bm.TENBM, ql.HOTEN as TenNQL
from GIAOVIEN gv
join BOMON bm on gv.MABM = bm.MABM
join GIAOVIEN ql on gv.GVQLCM = ql.MAGV
where not exists (
	select 1
	from DETAI dt join CHUDE cd on dt.MACD = cd.MACD
	where cd.TENCD = N'Nghiên cứu phát triển'
	and not exists (
		select 1
		from THAMGIADT tg
		where tg.MADT = dt.MADT and tg.MAGV = gv.MAGV
	)
)
and exists (
	select 1
	from DETAI dt join CHUDE cd on dt.MACD = cd.MACD
	where cd.TENCD = N'Nghiên cứu phát triển'
)

-- C3:
select gv.MAGV, gv.HOTEN, bm.TENBM, ql.HOTEN as TenNQL
from GIAOVIEN gv
join BOMON bm on gv.MABM = bm.MABM
join GIAOVIEN ql on gv.GVQLCM = ql.MAGV
join THAMGIADT tg on gv.MAGV = tg.MAGV
join DETAI dt on tg.MADT = dt.MADT
join CHUDE cd on dt.MACD = cd.MACD
where cd.TENCD = N'Nghiên cứu phát triển'
group by gv.MAGV, gv.HOTEN, bm.TENBM, ql.HOTEN
having count(distinct dt.MADT) = (
	select count(distinct dt2.MADT)
	from DETAI dt2
	join CHUDE cd2 on dt2.MACD = cd2.MACD
	where cd2.TENCD = N'Nghiên cứu phát triển'
)

-- 16. Cho biết họ tên, ngày sinh, tên khoa, tên trưởng khoa của giáo viên tham gia tất cả các đề tài có giáo viên 'Nguyễn
-- Hoài An' tham gia
-- C1:
select gv.HOTEN, gv.NGSINH, k.TENKHOA, tk.HOTEN as TENTRUONGKHOA
from GIAOVIEN gv
join BOMON bm on gv.MABM = bm.MABM
join KHOA k on bm.MAKHOA = k.MAKHOA
join GIAOVIEN tk on k.TRUONGKHOA = tk.MAGV
where gv.HOTEN != N'Nguyễn Hoài An'
and not exists (
	select distinct tg.MADT
	from THAMGIADT tg join GIAOVIEN gv2 on tg.MAGV = gv2.MAGV
	where gv2.HOTEN = N'Nguyễn Hoài An'

	except

	select tg2.MADT
	from THAMGIADT tg2
	where tg2.MAGV = gv.MAGV
)
and exists (
	select 1
	from THAMGIADT tg join GIAOVIEN gv2 on tg.MAGV = gv2.MAGV
	where gv2.HOTEN = N'Nguyễn Hoài An'
)

-- C2:
select gv.HOTEN, gv.NGSINH, k.TENKHOA, tk.HOTEN as TENTRUONGKHOA
from GIAOVIEN gv
join BOMON bm on gv.MABM = bm.MABM
join KHOA k on bm.MAKHOA = k.MAKHOA
join GIAOVIEN tk on k.TRUONGKHOA = tk.MAGV
where gv.HOTEN != N'Nguyễn Hoài An'
and not exists (
    select 1
    from THAMGIADT tg
    join GIAOVIEN gv2 on tg.MAGV = gv2.MAGV
    where gv2.HOTEN = N'Nguyễn Hoài An'
    and not exists (
        select 1
        from THAMGIADT tg2
        where tg2.MAGV = gv.MAGV and tg2.MADT = tg.MADT
    )
)
and exists (
	select 1
	from THAMGIADT tg join GIAOVIEN gv2 on tg.MAGV = gv2.MAGV
	where gv2.HOTEN = N'Nguyễn Hoài An'
)

-- C3:
select gv.HOTEN, gv.NGSINH, k.TENKHOA, tk.HOTEN as TENTRUONGKHOA
from GIAOVIEN gv
join THAMGIADT tg on gv.MAGV = tg.MAGV
join DETAI dt on tg.MADT = dt.MADT
join BOMON bm on gv.MABM = bm.MABM
join KHOA k on bm.MAKHOA = k.MAKHOA
join GIAOVIEN tk on k.TRUONGKHOA = tk.MAGV
where gv.HOTEN != N'Nguyễn Hoài An'
and tg.MADT in (
    select distinct tg1.MADT
    from THAMGIADT tg1
    join GIAOVIEN gv1 on tg1.MAGV = gv1.MAGV
    where gv1.HOTEN = N'Nguyễn Hoài An'
)
group by gv.MAGV, gv.HOTEN, gv.NGSINH, k.TENKHOA, tk.HOTEN
having count(distinct tg.MADT) = (
    select count(distinct tg2.MADT)
    from THAMGIADT tg2
    join GIAOVIEN gv2 on tg2.MAGV = gv2.MAGV
    where gv2.HOTEN = N'Nguyễn Hoài An'
)
