data <- read.csv("profit.csv", header = T)
# a
hist(data$profit, col="lightblue", border="black", breaks=10)
print('Nhan xet: phan phoi chuan lech phai')

# b
profitable_day <- data$profit[data$profit > 65]
n <- length(profitable_day)
# print(n)

mean_val <- mean(profitable_day)
S <- sd(profitable_day, na.rm=FALSE)

alpha <- 0.01
confidence <- (1 - alpha) * 100

if (n >= 30) {
    z <- qnorm(1 - alpha / 2)
    epsilon <- z * S / sqrt(n)
}  else {
    t <- qt(1 - alpha / 2, df = n - 1)
    epsilon <- t * S / sqrt(n)
}

cat('KTC', confidence, '% cho doanh so ban trung binh: [', mean_val - epsilon, ';', mean_val + epsilon, ']\n')

# c
# Gia thuyet
# H0: mean = 60
# H1: mean khac 60

mean_current <- mean(data$profit)

t_test_result <- t.test(data$profit, mu=60, conf.level=0.99)


cat("Gia tri trung binh doanh so hien tai:", mean_current, "trieu dong\n")
cat("Gia tri p-value cua kiem dinh t:", t_test_result$p.value, "\n")

# (alpha = 0.01)
if (t_test_result$p.value < 0.01) {
  cat("Phuong thuc ban hang moi co anh huong dang ke den doanh so voi muc y nghia 1%.\n")
} else {
  cat("Khong du co so de bac bo H0: doanh so ban khong doi voi muc y nghia 1%.\n")
}