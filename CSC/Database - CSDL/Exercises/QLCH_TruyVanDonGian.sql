USE QLCH_TraSua;
/*1a: Lấy danh sách tất cả các món*/
SELECT *
FROM DS_MON

/*1B: Chỉ lấy tên món và giá tiền*/
SELECT TenMon, Gia
FROM DS_MON

-- 2a: Tìm các món có giá lớn hơn 30,000
SELECT *
FROM DS_MON
WHERE Gia > 30000

/* 2b: Tìm ra các món ăn thuộc loại ‘A’ hoặc ‘C’*/
SELECT *
FROM DS_MON
WHERE Loai = 'A' OR Loai = 'C'

SELECT *
FROM DS_MON
WHERE Loai IN ('A','C')


/* 3a: Tìm các khách hàng có tên bắt đầu bằng "Nguyễn" */
SELECT *
FROM KHACH_HANG
WHERE TenKH LIKE N'Nguyễn%'

/* 3b: Tìm các khách hàng tên có “Văn” ở bất kỳ vị trí nào */
SELECT *
FROM KHACH_HANG
WHERE TenKH LIKE N'%Văn%'

/*3c: Tìm các loại món có tên loại bắt đầu bằng T và có 3 ký tự*/
SELECT *
FROM LOAI_MON
WHERE TenLoai LIKE N'T__'

/*Lấy danh sách món và loại món tương ứng*/
SELECT *
FROM DS_MON, LOAI_MON
WHERE Loai = MaLoai

SELECT *
FROM DS_MON ds JOIN LOAI_MON l ON ds.Loai = l.MaLoai


SELECT hd.MaHD, hd.TongTien, kh.TenKH
FROM HOA_DON AS hd, KHACH_HANG AS kh
WHERE hd.MaKH = kh.MaKH AND TongTien > 200000

SELECT hd.MaHD, hd.TongTien, kh.TenKH
FROM HOA_DON AS hd JOIN KHACH_HANG AS kh ON hd.MaKH = kh.MaKH
WHERE TongTien > 200000

-- 4c: Lấy tất cả khách hàng (mã và tên KH) và hoá đơn tương ứng
SELECT KH.MaKH, KH.TenKH, HD.MaHD
FROM KHACH_HANG KH LEFT JOIN HOA_DON HD ON KH.MaKH = HD.MaKH

SELECT KH.MaKH, KH.TenKH, HD.MaHD
FROM HOA_DON HD RIGHT JOIN KHACH_HANG KH ON KH.MaKH = HD.MaKH

/* 5a: Lấy thông tin khách hàng và vắp xếp tên khách hàng theo thứ tự tăng dần*/
SELECT *
FROM KHACH_HANG
ORDER BY TenKH

/* 6a: Lấy khác hàng (MaKH) đã từng mua trà hoặc từng mua cà phê 
<=> DS khách hàng mua Trà HỢP (UNION) DS khách hàng mua cà phê*/
SELECT HD.MaKH, L.TenLoai
FROM HOA_DON HD, CT_HD CT, DS_MON DS, LOAI_MON L
WHERE HD.MAHD = CT.MAHD AND CT.MaMon = DS.MaMon AND DS.Loai = L.MaLoai
        AND (L.TenLoai = N'Trà' OR L.TenLoai = N'Cà phê')

SELECT HD.MaKH
FROM HOA_DON HD, CT_HD CT, DS_MON DS, LOAI_MON L
WHERE HD.MAHD = CT.MAHD AND CT.MaMon = DS.MaMon AND DS.Loai = L.MaLoai
        AND L.TenLoai = N'Trà'
UNION
SELECT HD.MaKH
FROM HOA_DON HD, CT_HD CT, DS_MON DS, LOAI_MON L
WHERE HD.MAHD = CT.MAHD AND CT.MaMon = DS.MaMon AND DS.Loai = L.MaLoai
        AND L.TenLoai = N'Cà phê'

/* 6a: Lấy khách hàng từng mua trà và cũng từng mua cà phê 
<=> DS khách hàng mua Trà GIAO (INTERSECT) DS khách hàng mua cà phê*/
SELECT HD.MaKH
FROM HOA_DON HD, CT_HD CT, DS_MON DS, LOAI_MON L
WHERE HD.MAHD = CT.MAHD AND CT.MaMon = DS.MaMon AND DS.Loai = L.MaLoai
        AND L.TenLoai = N'Trà'
INTERSECT
SELECT HD.MaKH
FROM HOA_DON HD, CT_HD CT, DS_MON DS, LOAI_MON L
WHERE HD.MAHD = CT.MAHD AND CT.MaMon = DS.MaMon AND DS.Loai = L.MaLoai
        AND L.TenLoai = N'Cà phê'

/* 6c: Lấy khách hàng từng mua trà nhưng chưa từng mua cà phê 
<=> DS khách hàng mua Trà - (EXCEPT) DS khách hàng mua cà phê */
SELECT HD.MaKH
FROM HOA_DON HD, CT_HD CT, DS_MON DS, LOAI_MON L
WHERE HD.MAHD = CT.MAHD AND CT.MaMon = DS.MaMon AND DS.Loai = L.MaLoai
        AND L.TenLoai = N'Trà'
EXCEPT
SELECT HD.MaKH
FROM HOA_DON HD, CT_HD CT, DS_MON DS, LOAI_MON L
WHERE HD.MAHD = CT.MAHD AND CT.MaMon = DS.MaMon AND DS.Loai = L.MaLoai
        AND L.TenLoai = N'Cà phê'

/* Tính giá trung bình của các món trong danh sách */
SELECT AVG(Gia) AS Gia_Trung_Binh
FROM DS_MON

SELECT KHACH_HANG.MaKH, KHACH_HANG.TenKH, COUNT(HOA_DON.MaHD) AS SoLuongHoaDon, SUM(HOA_DON.TongTien) AS TongChiTieu
FROM KHACH_HANG
JOIN HOA_DON ON KHACH_HANG.MaKH = HOA_DON.MaKH
GROUP BY KHACH_HANG.MaKH, KHACH_HANG.TenKH

/*Đếm số món khác nhau mà mỗi khách hàng đã mua*/

SELECT HD.MAKH, COUNT(DISTINCT CT.MaMon)
FROM HOA_DON HD JOIN CT_HD CT ON HD.MaHD = CT.MaHD
GROUP BY HD.MAKH

/*Đếm số món khác nhau mà mỗi khách hàng đã mua, xuất ra MaKH đã 2 món khác nhau*/
SELECT HD.MAKH, COUNT(DISTINCT CT.MaMon)
FROM HOA_DON HD JOIN CT_HD CT ON HD.MaHD = CT.MaHD
GROUP BY HD.MAKH
HAVING COUNT(DISTINCT CT.MaMon) > 1

-- Thêm dữ liệu minh hoạ COUNT (DISTINCT)
-- INSERT INTO CT_HD VALUES
-- ('HD01', '3', 'M01', 4, 80000)

-- SELECT *
-- FROM CT_HD


/* Ví dụ 8a:: Liệt kê các món ăn thuộc loại Cà phê*/
SELECT DS.*
FROM DS_MON DS JOIN LOAI_MON L ON DS.Loai = L.MaLoai
WHERE L.TenLoai = N'Cà phê'

SELECT *
FROM DS_MON
WHERE Loai IN (
        SELECT MaLoai
        FROM LOAI_MON
        WHERE TenLoai = N'Cà phê'
)

/*8b: Tìm món ăn có giá cao hơn tất cả các món thuộc loại ‘Tráng miệng’*/

SELECT *
FROM DS_MON
WHERE Gia > ALL (
        SELECT Gia
        FROM DS_MON DS JOIN LOAI_MON L ON DS.Loai = L.MaLoai
        WHERE L.TenLoai = N'Tráng miệng'
)

/*8c: Tìm nhân viên đã từng lập (ít nhất một) hóa đơn*/
SELECT *
FROM NHAN_VIEN NV
WHERE EXISTS (
        SELECT 1
        FROM HOA_DON HD
        WHERE HD.MaNV = NV.MaNV
)

/*28. Tìm các món ăn có giá thấp hơn ít nhất một món trong loại "Cà phê".*/

SELECT Gia, TenLoai
FROM DS_MON DS JOIN LOAI_MON L ON DS.Loai = L.MaLoai
WHERE L.TenLoai = N'Cà phê'

SELECT *
FROM DS_MON
WHERE Gia < ANY (
        SELECT Gia
        FROM DS_MON DS JOIN LOAI_MON L ON DS.Loai = L.MaLoai
        WHERE L.TenLoai = N'Cà phê')

/*31. Tìm tên những món ăn có đơn giá cao hơn mọi món mà khách hàng "Trần Văn Quyết" đã từng mua. */
SELECT Gia
FROM DS_MON DS JOIN CT_HD CT ON DS.MaMon = CT.MaMon
        JOIN HOA_DON HD ON HD.MaHD = CT.MaHD
        JOIN KHACH_HANG KH ON KH.MaKH = HD.MaKH
WHERE KH.TenKH = N'Trần Văn Quyết'

SELECT *
FROM DS_MON
WHERE Gia > ALL (
        SELECT Gia
        FROM DS_MON DS JOIN CT_HD CT ON DS.MaMon = CT.MaMon
                JOIN HOA_DON HD ON HD.MaHD = CT.MaHD
                JOIN KHACH_HANG KH ON KH.MaKH = HD.MaKH
        WHERE KH.TenKH = N'Trần Văn Quyết'
)

/* 32.	Tìm những nhân viên quản lý 2 nhân viên trở lên 
và có lập hoá đơn trên 100,000.*/

SELECT NV.NguoiQL, NV2.TenNV
FROM NHAN_VIEN NV JOIN NHAN_VIEN NV2 ON NV.NguoiQL = NV2.MaNV
WHERE EXISTS (
        SELECT 1
        FROM HOA_DON HD
        WHERE HD.MaNV = NV.NguoiQL AND HD.TongTien > 100000
)
GROUP BY NV.NguoiQL, NV2.TenNV
HAVING COUNT(*) > 1

/* Danh sách khách hàng (MaKH) và món (MaMon) tương ứng mà họ mua */
SELECT HD.MaKH, CT.MaMon
FROM CT_HD CT JOIN HOA_DON HD
ON CT.MaHD = HD.MaHD

SELECT M.MaMon
FROM DS_MON M JOIN LOAI_MON L ON M.Loai = L.MaLoai AND L.TenLoai = N'Cà phê'

/* Đếm xem mỗi người mua bao nhiêu món loại "Cà phê" */
SELECT HD.MaKH, COUNT (DISTINCT CT.MaMon)
FROM HOA_DON HD 
        JOIN CT_HD CT ON HD.MaHD = CT.MaHD
        JOIN DS_MON M ON M.MaMon = CT.MaMon
        JOIN LOAI_MON L ON M.Loai = L.MaLoai
WHERE L.TenLoai = N'Cà phê'
GROUP BY HD.MaKH

/* Đếm xem bao nhiêu món thuộc loại cà phê*/
SELECT COUNT(DS.MaMon)
FROM DS_MON DS JOIN LOAI_MON L ON DS.Loai = L.MaLoai AND L.TenLoai = N'Cà phê'

/* PHÉP CHIA*/
SELECT HD.MaKH
FROM HOA_DON HD 
        JOIN CT_HD CT ON HD.MaHD = CT.MaHD
        JOIN DS_MON M ON M.MaMon = CT.MaMon
        JOIN LOAI_MON L ON M.Loai = L.MaLoai
WHERE L.TenLoai = N'Cà phê'
GROUP BY HD.MaKH
HAVING COUNT (DISTINCT CT.MaMon) = (
        SELECT COUNT(DS.MaMon)
        FROM DS_MON DS 
                JOIN LOAI_MON L ON DS.Loai = L.MaLoai AND L.TenLoai = N'Cà phê'
)

/*PHÉP CHIA: NOT EXISTS... EXCEPT*/

SELECT *
FROM KHACH_HANG KH
WHERE NOT EXISTS (
        SELECT M.MaMon
        FROM DS_MON M JOIN LOAI_MON L ON M.Loai = L.MaLoai
        WHERE L.TenLoai = N'Cà phê'

        EXCEPT

        SELECT CT.MaMon
        FROM CT_HD CT JOIN HOA_DON HD ON CT.MaHD = HD.MaHD
        WHERE KH.MaKH = HD.MaKH
) AND EXISTS (
        SELECT M.MaMon
        FROM DS_MON M JOIN LOAI_MON L ON M.Loai = L.MaLoai
        WHERE L.TenLoai = N'Cà phê'
)

/*PHÉP CHIA: NOT EXISTS... NOT EXISTS*/
SELECT *
FROM KHACH_HANG KH
WHERE NOT EXISTS (
        SELECT *
        FROM DS_MON M JOIN LOAI_MON L ON M.Loai = L.MaLoai AND L.TenLoai = N'Cà phê' 
        WHERE NOT EXISTS (
                        SELECT 1
                        FROM CT_HD CT JOIN HOA_DON HD ON CT.MaHD = HD.MaHD
                        WHERE M.MaMon = CT.MaMon AND HD.MaKH = KH.MaKH
                )
) AND EXISTS (
        SELECT M.MaMon
        FROM DS_MON M JOIN LOAI_MON L ON M.Loai = L.MaLoai
        WHERE L.TenLoai = N'Cà phê'
)