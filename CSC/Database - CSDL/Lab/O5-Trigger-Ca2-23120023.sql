/*
Phần 1: Ghi chú thông tin sinh viên
- MSSV: 23120023
- Họ tên: Nguyễn Thái Bảo
- Lớp: 23CTT1
- Nhóm: N2
- Ca: 2
- Email: 23120023@student.hcmus.edu.vn
*/

-- 1. Tên đề tài phải duy nhất
CREATE TRIGGER tg_23120023_R1
ON DETAI
FOR INSERT, UPDATE
AS
IF EXISTS (
    SELECT TENDT
    FROM DETAI
    GROUP BY TENDT
    HAVING COUNT(*) > 1
)
BEGIN
    RAISERROR (N'Lỗi: Tên đề tài phải duy nhất.', 16, 1)
    ROLLBACK
END

-- 2. Trưởng bộ môn phải sinh trước 1975
CREATE TRIGGER tg_23120023_R2
ON BOMON
FOR INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT *
        FROM BOMON BM JOIN GIAOVIEN GV ON BM.TRUONGBM = GV.MAGV
        WHERE YEAR(GV.NGSINH) >= 1975
    )
    BEGIN
        RAISERROR (N'Lỗi: Trưởng bộ môn phải sinh trước 1975.', 16, 1)
        ROLLBACK
    END
END

-- 3. Một bộ môn có tối thiểu 1 GV nữ
CREATE TRIGGER tg_23120023_R3
ON GIAOVIEN
FOR INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT MABM
        FROM BOMON
        WHERE MABM NOT IN (
            SELECT MABM FROM GIAOVIEN WHERE PHAI = N'Nữ'
        )
    )
    BEGIN
        RAISERROR (N'Lỗi: Mỗi bộ môn phải có ít nhất một giáo viên nữ.', 16, 1)
        ROLLBACK
    END
END

-- 4. Một giáo viên phải có ít nhất 1 SĐT
CREATE TRIGGER tg_23120023_R4
ON GIAOVIEN
FOR INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT GV.MAGV
        FROM GIAOVIEN GV
        WHERE GV.MAGV NOT IN (SELECT MAGV FROM DIENTHOAI)
    )
    BEGIN
        RAISERROR (N'Lỗi: Giáo viên phải có ít nhất 1 số điện thoại.', 16, 1)
        ROLLBACK
    END
END

-- 5. Một giáo viên có tối đa 3 SĐT
CREATE TRIGGER tg_23120023_R5
ON DIENTHOAI
FOR INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT MAGV
        FROM DIENTHOAI
        GROUP BY MAGV
        HAVING COUNT(*) > 3
    )
    BEGIN
        RAISERROR (N'Lỗi: Mỗi giáo viên chỉ được có tối đa 3 số điện thoại.', 16, 1)
        ROLLBACK
    END
END

-- 6. Một bộ môn phải có tối thiểu 4 giáo viên
CREATE TRIGGER tg_23120023_R6
ON GIAOVIEN
FOR INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT MABM
        FROM BOMON
        WHERE MABM NOT IN (
            SELECT MABM
            FROM GIAOVIEN
            GROUP BY MABM
            HAVING COUNT(*) >= 4
        )
    )
    BEGIN
        RAISERROR (N'Lỗi: Mỗi bộ môn phải có tối thiểu 4 giáo viên.', 16, 1)
        ROLLBACK
    END
END

-- 7. Trưởng bộ môn phải là người lớn tuổi nhất trong bộ môn
CREATE TRIGGER tg_23120023_R7
ON BOMON
FOR INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT BM.MABM
        FROM BOMON BM
        JOIN GIAOVIEN GV_TRUONG ON BM.TRUONGBM = GV_TRUONG.MAGV
        WHERE GV_TRUONG.NGSINH > (
            SELECT MIN(GV.NGSINH)
            FROM GIAOVIEN GV
            WHERE GV.MABM = BM.MABM
        )
    )
    BEGIN
        RAISERROR (N'Lỗi: Trưởng bộ môn phải là người lớn tuổi nhất trong bộ môn.', 16, 1)
        ROLLBACK
    END
END

-- 8. Nếu 1 giáo viên đã là trưởng bộ môn thì giáo viên đó không làm người quản lý chuyên môn
CREATE TRIGGER tg_23120023_R8
ON BOMON
FOR INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT *
        FROM BOMON BM
        JOIN GIAOVIEN GV ON BM.TRUONGBM = GV.MAGV
        WHERE GV.MAGV IN (
            SELECT GVQLCM
			FROM GIAOVIEN
			WHERE GVQLCM IS NOT NULL
        )
    )
    BEGIN
        RAISERROR (N'Lỗi: Trưởng bộ môn không được làm người quản lý chuyên môn.', 16, 1)
        ROLLBACK
    END
END

-- 9. Giáo viên và GVQLCM của giáo viên đó phải thuộc về 1 bộ môn
CREATE TRIGGER tg_23120023_R9
ON GIAOVIEN
FOR INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT *
        FROM GIAOVIEN GV
        JOIN GIAOVIEN GVQL ON GV.GVQLCM = GVQL.MAGV
        WHERE GV.MABM != GVQL.MABM
    )
    BEGIN
        RAISERROR (N'Lỗi: Giáo viên và giáo viên quản lý chuyên môn phải cùng một bộ môn.', 16, 1)
        ROLLBACK
    END
END

-- 10. Mỗi giáo viên chỉ có tối đa 1 vợ chồng
CREATE TRIGGER tg_23120023_R10
ON GIAOVIEN
FOR INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT MAGV
        FROM GIAOVIEN
        WHERE MAGV IN (
            SELECT MAGV
            FROM NGUOITHAN
            WHERE QUANHE = N'Vợ chồng'
            GROUP BY MAGV
            HAVING COUNT(*) > 1
        )
    )
    BEGIN
        RAISERROR (N'Lỗi: Mỗi giáo viên chỉ có tối đa một vợ chồng.', 16, 1)
        ROLLBACK
    END
END

-- 11. Giáo viên là Nam thì chỉ có vợ chồng là Nữ hoặc ngược lại
CREATE TRIGGER tg_23120023_R11
ON NGUOITHAN
FOR INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT *
        FROM NGUOITHAN NT
        JOIN GIAOVIEN GV ON NT.MAGV = GV.MAGV
        WHERE NT.QUANHE = N'Vợ chồng'
		AND ((GV.PHAI = 'Nam' AND NT.PHAI != N'Nữ') OR (GV.PHAI = N'Nữ' AND NT.PHAI != 'Nam'))
    )
    BEGIN
        RAISERROR (N'Lỗi: Nếu giáo viên là Nam thì chỉ có vợ chồng là Nữ và ngược lại.', 16, 1)
        ROLLBACK
    END
END

-- 12. Nếu thân nhân có quan hệ là "con gái" hoặc "con trai" với giáo viên thì năm sinh của giáo viên phải nhỏ hơn
-- năm sinh của thân nhân
CREATE TRIGGER tg_23120023_R12
ON NGUOITHAN
FOR INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT TN.*
        FROM NGUOITHAN TN
        JOIN GIAOVIEN GV ON TN.MAGV = GV.MAGV
        WHERE (TN.QUANHE = N'Con gái' OR TN.QUANHE = N'Con trai') AND YEAR(GV.NGSINH) >= YEAR(TN.NGSINH)
    )
    BEGIN
        RAISERROR (N'Lỗi: Giáo viên phải sinh trước con gái/trai của mình.', 16, 1)
        ROLLBACK
    END
END

-- 13. Một giáo viên chỉ làm chủ nhiệm tối đa 3 đề tài
CREATE TRIGGER tg_23120023_R13
ON DETAI
FOR INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT GVCNDT
        FROM DETAI
        GROUP BY GVCNDT
        HAVING COUNT(*) > 3
    )
    BEGIN
        RAISERROR (N'Lỗi: Mỗi giáo viên chỉ làm chủ nhiệm tối đa 3 đề tài.', 16, 1)
        ROLLBACK
    END
END

-- 14. Một đề tài phải có ít nhất một công việc
CREATE TRIGGER tg_23120023_R14
ON DETAI
FOR INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT DT.MADT
        FROM DETAI DT
        WHERE DT.MADT NOT IN (
			SELECT MADT 
			FROM CONGVIEC
		)
    )
    BEGIN
        RAISERROR (N'Lỗi: Mỗi đề tài phải có ít nhất một công việc.', 16, 1)
        ROLLBACK
    END
END

--15. Lương của giáo viên phải nhỏ hơn lương người quản lý của giáo viên đó
CREATE TRIGGER tg_23120023_R15
ON GIAOVIEN
FOR INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT GV.MAGV
        FROM GIAOVIEN GV
        JOIN GIAOVIEN QL ON GV.GVQLCM = QL.MAGV
        WHERE GV.LUONG >= QL.LUONG
    )
    BEGIN
        RAISERROR (N'Lỗi: Lương của giáo viên phải nhỏ hơn lương người quản lý của giáo viên đó.', 16, 1)
        ROLLBACK
    END
END

-- 16. Lương của trưởng bộ môn phải lớn hơn lương của các giáo viên trong bộ môn
CREATE TRIGGER tg_23120023_R16
ON GIAOVIEN
FOR INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT BM.MABM
        FROM BOMON BM
        JOIN GIAOVIEN GV_TRG ON BM.TRUONGBM = GV_TRG.MAGV
        JOIN GIAOVIEN GV ON BM.MABM = GV.MABM
        WHERE GV_TRG.LUONG <= GV.LUONG AND GV.MAGV != GV_TRG.MAGV
    )
    BEGIN
        RAISERROR (N'Lỗi: Lương của trưởng bộ môn phải lớn hơn lương của các giáo viên trong bộ môn.', 16, 1)
        ROLLBACK
    END
END

-- 17. Bộ môn nào cũng phải có trưởng bộ môn và trưởng bộ môn phải là 1 giáo viên trong trường
CREATE TRIGGER tg_23120023_R17
ON BOMON
FOR INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT BM.MABM
        FROM BOMON BM
        LEFT JOIN GIAOVIEN GV ON BM.TRUONGBM = GV.MAGV
        WHERE BM.TRUONGBM IS NULL OR GV.MAGV IS NULL
    )
    BEGIN
        RAISERROR (N'Lỗi: Mỗi bộ môn phải có trưởng bộ môn là một giáo viên trong trường.', 16, 1)
        ROLLBACK
    END
END

-- 18. Một giáo viên chỉ quản lý tối đa 3 giáo viên khác
CREATE TRIGGER tg_23120023_R18
ON GIAOVIEN
FOR INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT GVQLCM
        FROM GIAOVIEN
        WHERE GVQLCM IS NOT NULL
        GROUP BY GVQLCM
        HAVING COUNT(*) > 3
    )
    BEGIN
        RAISERROR (N'Lỗi: Một giáo viên chỉ quản lý tối đa 3 giáo viên khác.', 16, 1)
        ROLLBACK
    END
END

-- 19. Giáo viên chỉ tham gia những đề tài mà GVCNĐT là người cùng bộ môn với giáo viên đó
CREATE TRIGGER tg_23120023_R19
ON THAMGIADT
FOR INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT 1
        FROM THAMGIADT TG
        JOIN GIAOVIEN GV_TG ON TG.MAGV = GV_TG.MAGV
        JOIN DETAI DT ON TG.MADT = DT.MADT
        JOIN GIAOVIEN GV_CN ON DT.GVCNDT = GV_CN.MAGV
        WHERE GV_TG.MABM != GV_CN.MABM
    )
    BEGIN
        RAISERROR (N'Lỗi: Giáo viên chỉ được tham gia đề tài mà giáo viên chủ nhiệm thuộc cùng bộ môn.', 16, 1)
        ROLLBACK
    END
END