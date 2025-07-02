data1 <- read.csv('data01.csv', header = TRUE)
#print(data1)
#print(data1$FPSA)

#a
mean_FPSA <- mean(data1$FPSA)
var_FPSA <- var(data1$FPSA)
median_FPSA <- median(data1$FPSA)

mean_TPSA <- mean(data1$TPSA)
var_TPSA <- var(data1$TPSA)
median_TPSA <- median(data1$TPSA)

print(mean_FPSA)
print(var_FPSA)
print(median_FPSA)
print(mean_TPSA)
print(var_TPSA)
print(median_TPSA)

#b
plot(data1$FPSA, type = "l", main = "FPSA line", xlab = "observations", ylab = "FPSA")
plot(data1$TPSA, type = "l", main = "FPSA line", xlab = "observations", ylab = "FPSA")
boxplot(data1$FPSA, main = "Boxplot FPSA", ylab = "FPSA", col = "lightblue")
boxplot(data1$TPSA, main = "Boxplot TPSA", ylab = "TPSA", col = "lightcoral")

#c
# Tach FPSA theo K
data_FPSA_K0 <- subset(data1, K == 0)$FPSA
data_FPSA_K1 <- subset(data1, K == 1)$FPSA
print('FPSA co K = 0')
print(data_FPSA_K0)
print('FPSA co K = 1')
print(data_FPSA_K1)

#d
data2 = read.csv("data02.csv", header = TRUE)
merged_data <- merge(data1, data2, by = "K")

#e
data1$tPSA <- ifelse(data1$Age <= 30, 0, 
                     ifelse(data1$Age <= 50, 1, 2))

table_tPSA <- table(data1$tPSA)

print(table_tPSA)




