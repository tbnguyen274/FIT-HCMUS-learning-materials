# File diesel_engine.dat và diesel_time.xls chứa số liệu về hoạt động của các động cơ chạy bằng dầu diesel. Thực hiện:
#a. Đọc số liệu từ hai file này, gán và hai dataframe, đặt tên hai dataframe cùng tên với file.
# b. Liệt kê tên các biến có trong hai dataframe vừa nhập.

#a
diesel_engine <- read.table("diesel_engine.dat", header = TRUE)
diesel_time <- read.csv("diesel_time.csv", header = TRUE)
# print(diesel_engine)
# print(diesel_time)

#b
print("Names of diesel_engine and diesel_time dataframes:")
print(names(diesel_engine))
print(names(diesel_time))

# c. Xác định có bao nhiêu dữ liệu bị khuyết (missing data) trong diesel_engine. Thay
# thế các giá trị khuyết trong biến speed bằng 1500, biến load bằng 20.
print("Number of missing data in diesel_engine:")
print(sum(is.na(diesel_engine)))
diesel_engine$speed[is.na(diesel_engine$speed)] <- 1500
diesel_engine$load[is.na(diesel_engine$load)] <- 20
print(diesel_engine)

# d. Tính: trung bình, phương sai, độ lệch tiêu chuẩn, giá trị lớn nhất, nhỏ nhất của biến alcohol trong dataframe diesel_engine.
mean_alcohol <- mean(diesel_engine$alcohol)
var_alcohol <- var(diesel_engine$alcohol)
sd_alcohol <- sd(diesel_engine$alcohol)
max_alcohol <- max(diesel_engine$alcohol)
min_alcohol <- min(diesel_engine$alcohol)

print("Statistics of alcohol variable in diesel_engine:")
print(paste("Mean: ", mean_alcohol))
print(paste("Variance: ", var_alcohol))
print(paste("Standard deviation: ", sd_alcohol))
print(paste("Max: ", max_alcohol))
print(paste("Min: ", min_alcohol))

# e. Ghép hai dataframe diesel_engine và diesel_time lại thành một frame có tên là diesel.
diesel <- cbind(diesel_engine, diesel_time)
print(diesel)

# f. Trích giá trị của biến run (số thứ tự các động cơ) mà có thời gian trễ (biến delay) dưới 1.000.
diesel_run_under1000 <- diesel[diesel$delay < 1000, "run"]
print("Engines with delay under 1000:")
print(diesel_run_under1000)

# g. Đếm xem có bao nhiêu động cơ có timing bằng 30.
print(paste("Number of engines with timing 30: ", sum(diesel$timing == 30)))

# h. Vẽ biểu đồ boxplot cho các biến speed, timing và delay.
boxplot(diesel$speed, main = "Boxplot of Speed", ylab = "Speed")
boxplot(diesel$timing, main = "Boxplot of Timing", ylab = "Timing")
# boxplot(diesel$delay, main = "Boxplot of Delay", ylab = "Delay")

# i. Vẽ biểu đồ phân tán cho các cặp biến (timing, speed), (temp, press).
plot(diesel$timing, diesel$speed, main = "Scatter plot of Timing and Speed", xlab = "Timing", ylab = "Speed")
plot(diesel$temp, diesel$press, main = "Scatter plot of Temp and Press", xlab = "Temp", ylab = "Press")

# j. Chuyển biến load sang biến nhân tố.
diesel$load <- as.factor(diesel$load)
# print(str(diesel$load))

# j. Chia delay thành 4 đoạn đều nhau
diesel$delay_group <- cut(diesel$delay, breaks = 4, labels = FALSE)
table_diesel_delay_group <- table(diesel$delay_group)
barplot(table(diesel$delay_group))

# k. Chia delay thành các đoạn cụ thể
diesel$delay_group2 <- cut(diesel$delay, breaks = c(0.283, 0.7, 0.95, 1.2, 1.56),
                          labels = c("0.283-0.7", "0.7-0.95", "0.95-1.2", "1.2-1.56"))
table_diesel_delay_group2 <- table(diesel$delay_group2)
barplot(table(diesel$delay_group2))