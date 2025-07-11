use DB_QuanLyLuanVan
go

select * from luanvan

-- d. Lấy danh sách giảng viên và số lượng luận văn họ đánh giá
SELECT bd.MaGVDanhGia, gv.HoTen, COUNT(*) AS SoLuongLuanVan 
FROM BangDiem bd 
JOIN GiangVien gv ON bd.MaGVDanhGia = gv.MaGV 
GROUP BY bd.MaGVDanhGia, gv.HoTen;

-- Tìm tên sinh viên có tổng điểm đánh giá luận văn thấp hơn trung bình tổng điểm của các sinh viên còn lại
select sv.HoTen
from SinhVien sv
join ThucHienLV thlv on sv.MSSV = thlv.MaSVThucHien
join BangDiem bd on thlv.malv = bd.MaLV and thlv.MaSVThucHien = bd.MaSVThucHien
group by sv.MSSV, sv.HoTen
having sum(bd.diem) < (
	select sum(bd2.diem) / count(distinct bd2.MaSVThucHien)
	from BangDiem bd2
	where bd2.MaSVThucHien != sv.MSSV
)

/*
1. Tìm các sinh viên có điểm luận văn trung bình (tính từ bảng bangdiem) cao hơn điểm trung bình của tất cả sinh viên trong cùng khoa,
hiển thị mã sinh viên, tên sinh viên, mã luận văn, và điểm trung bình.
*/
select sv.HoTen
from SinhVien sv
join ThucHienLV thlv on sv.MSSV = thlv.MaSVThucHien
join BangDiem bd on thlv.malv = bd.MaLV and thlv.MaSVThucHien = bd.MaSVThucHien
group by sv.MSSV, sv.HoTen, sv.ThuocKhoa
having avg(bd.diem) > (
	select AVG(bd2.Diem)
	from BangDiem bd2
	join SinhVien sv2 on bd2.MaSVThucHien = sv2.MSSV
	where sv2.ThuocKhoa = sv.ThuocKhoa
)

/*
2. Liệt kê các giảng viên thuộc khoa 'IS' đã hướng dẫn ít nhất một luận văn có điểm trung bình (theo bangdiem) lớn hơn
điểm trung bình của tất cả luận văn trong khoa đó, hiển thị tên giảng viên, mã luận văn, và điểm trung bình.
*/
SELECT gv.HoTen, bd.MaLV, AVG(bd.Diem) DiemTB
FROM GiangVien gv
JOIN BangDiem bd ON gv.MaGV = bd.MaGVDanhGia
JOIN LuanVan lv ON bd.MaLV = lv.MaLV
WHERE (gv.ThuocKhoa) = 'IS' AND bd.VaiTro = N'Hướng dẫn'
GROUP BY gv.HoTen, bd.MaLV
HAVING AVG(bd.Diem) > (
    SELECT AVG(bd2.Diem)
    FROM BangDiem bd2
    INNER JOIN LuanVan lv2 ON bd2.MaLV = lv2.MaLV
    WHERE RTRIM(lv2.ThuocKhoa) = 'IS'
);

select *
from GiangVien gv
join BangDiem bd on gv.MaGV = bd.MaGVDanhGia
where gv.ThuocKhoa = 'IS' and bd.VaiTro = N'Hướng dẫn'
and exists (
	select 1
	from LuanVan lv
	join BangDiem bd2 on lv.MaLV = bd2.MaLV
	where bd2.MaLV in (
		select bd3.MaLV
		from BangDiem bd3
		where bd3.MaGVDanhGia = gv.MaGV
	)
)

