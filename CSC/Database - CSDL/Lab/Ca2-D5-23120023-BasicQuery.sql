/*
Phần 1: Ghi chú thông tin sinh viên
- MSSV: 23120023
- Họ tên: Nguyễn Thái Bảo
- Lớp: 23CTT1
- Nhóm: N2
- Ca: 2
- Email: 23120023@student.hcmus.edu.vn
- Ngày làm bài: 6/4/2025 (chỉnh sửa: 10/4/2025)
*/

use DB_QLDeTai_23120023
go

-- 1. Cho biết họ tên và mức lương của các giáo viên nữ. Sắp xếp tăng dần theo ngày sinh.
select HOTEN, LUONG
from GIAOVIEN
where PHAI = N'Nữ'
order by NGSINH

-- 2. Cho biết họ tên của các giáo viên và lương của họ sau khi tăng 10%
select HOTEN, luong * 1.1 as LUONGSAUTANG
from GIAOVIEN

-- 3. Cho biết mã của các giáo viên có họ tên bắt đầu là "Nguyễn" và lương trên $2000 hoặc,
-- giáo viên là trưởng bộ môn nhận chức sau năm 1995. Sắp xếp giảm dần theo lương, sau đó tăng dần theo mã bộ môn.
select GV.MAGV
from GIAOVIEN GV
left join BOMON BM on GV.MAGV = BM.TRUONGBM
where (GV.HOTEN like N'Nguyễn%' and GV.LUONG > 2000) or (BM.TRUONGBM is not null and YEAR(BM.NGAYNHANCHUC) > 1995)
order by GV.LUONG desc, GV.MABM asc

-- không thể order by
select magv
from GIAOVIEN
where hoten like N'Nguyễn%' and LUONG > 2000
union
select TRUONGBM
from BOMON
where YEAR(NGAYNHANCHUC) > 1995

-- 4. Cho biết tên những giáo viên thuộc bộ môn có mã "HTTT".
select HOTEN
from GIAOVIEN
where MABM = 'HTTT'

-- 5. Cho biết Mã Giáo viên làm trưởng bộ môn có thân nhân.
select TRUONGBM
from BOMON
intersect
select MAGV
from NGUOITHAN

-- 6. Cho biết Mã đề tài nào chưa có giáo viên tham gia.
select MADT
from DETAI
except
select MADT
from THAMGIADT

-- 7. Cho biết Mã Giáo viên có tham gia thực hiện đề tài nhưng không có thân nhân.
select distinct MAGV
from THAMGIADT
except
select distinct MAGV
from NGUOITHAN

-- 8. Cho biết Mã Giáo viên nào vừa làm trưởng bộ môn, vừa làm trưởng khoa.
select TRUONGBM as MAGV
from BOMON
intersect
select TRUONGKHOA
from KHOA