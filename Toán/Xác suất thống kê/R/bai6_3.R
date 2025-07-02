# Cách 1: Dùng c()
sinh_vien <- 1:10
cau_hoi_1 <- c(3, 3, 3, 4, 3, 4, 3, 4, 3, 4)
cau_hoi_2 <- c(5, 3, 5, 5, 2, 2, 5, 5, 4, 2)
cau_hoi_3 <- c(1, 3, 1, 1, 1, 3, 1, 1, 1, 1)

# Tạo dataframe
diem <- data.frame(Sinh_vien = sinh_vien, Cau_hoi_1 = cau_hoi_1, Cau_hoi_2 = cau_hoi_2, Cau_hoi_3 = cau_hoi_3)
#print(diem)

# Cách 2: Dùng scan()
# cat("Nhập điểm cho Câu hỏi 1:")
# cau_hoi_1 <- scan()
# cat("Nhập điểm cho Câu hỏi 2:")
# cau_hoi_2 <- scan()
# cat("Nhập điểm cho Câu hỏi 3:")
# cau_hoi_3 <- scan()

# Tạo dataframe
# diem <- data.frame(Sinh_vien = 1:10, Cau_hoi_1 = cau_hoi_1, Cau_hoi_2 = cau_hoi_2, Cau_hoi_3 = cau_hoi_3)
# print(diem)

# Tạo bảng riêng cho Câu hỏi 1 và Câu hỏi 2
bang_cau_hoi_1_2 <- diem[, c("Sinh_vien", "Cau_hoi_1", "Cau_hoi_2")]
print(bang_cau_hoi_1_2)

# Vẽ biểu đồ bar ngang cho Câu hỏi 2 và Câu hỏi 3
print(diem)
barplot(as.matrix(diem[, c("Cau_hoi_2", "Cau_hoi_3")]),
        beside = TRUE, horiz = TRUE,
        col = c("skyblue", "orange"),
        legend.text = c("Câu hỏi 2", "Câu hỏi 3"),
        xlab = "Điểm", ylab = "Sinh viên",
        main = "Biểu đồ bar ngang cho Câu hỏi 2 và Câu hỏi 3")