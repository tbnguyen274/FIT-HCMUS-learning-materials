/*
Phần 1: Ghi chú thông tin sinh viên
- MSSV: 23120023
- Họ tên: Nguyễn Thái Bảo
- Lớp: 23CTT1
- Nhóm: N2
- Ca: 2
- Email: 23120023@student.hcmus.edu.vn
*/

-- Lab F5

-- 1. Cho biết số lượng giáo viên và tổng lương của họ
select count(magv) as SoLuong, sum(luong) as TongLuong
from GIAOVIEN

-- 2. Cho biết số lượng giáo viên và lương trung bình của từng bộ môn
select count(gv.magv) as SoLuong, AVG(gv.luong) as LuongTB
from BOMON bm left join GIAOVIEN gv on bm.MABM = gv.MABM
group by bm.MABM

-- 3. Cho biết tên chủ đề và số lượng đề tài thuộc về chủ đề đó
select cd.TENCD, count(dt.madt) as SLDT
from CHUDE cd left join DETAI dt on cd.MACD = dt.MACD
group by cd.MACD, cd.TENCD

-- 4. Cho biết tên giáo viên và số lượng đề tài mà giáo viên đó tham gia
select gv.HOTEN, count(distinct tg.MADT) as SLDT
from GIAOVIEN gv left join THAMGIADT tg on gv.MAGV = tg.MAGV
group by gv.MAGV, gv.HOTEN

-- 5. Cho biết tên giáo viên và số lượng đề tài mà giáo viên đó làm chủ nhiệm
select gv.HOTEN, count(dt.madt) as SLDT
from GIAOVIEN gv left join DETAI dt on gv.magv = dt.GVCNDT
group by gv.magv, gv.HOTEN

-- 6. Với mỗi giáo viên cho tên giáo viên và số người thân của giáo viên đó
select gv.HOTEN, count(nt.magv) as SLNguoiThan
from GIAOVIEN gv left join NGUOITHAN nt on gv.MAGV = nt.MAGV
group by gv.MAGV, gv.HOTEN

-- 7. Cho biết tên những giáo viên đã tham gia từ 3 đề tài trở lên
select gv.HOTEN
from GIAOVIEN gv join THAMGIADT tg on gv.MAGV = tg.MAGV
group by gv.MAGV, gv.HOTEN
having count(distinct tg.MADT) >= 3

-- 8. Cho biết số lượng giáo viên đã tham gia vào đề tài Ứng dụng hóa học xanh
select count(distinct tg.MAGV) as SoLuongGV
from DETAI dt join THAMGIADT tg on dt.MADT = tg.MADT
where dt.TENDT = N'Ứng dụng hóa học xanh'