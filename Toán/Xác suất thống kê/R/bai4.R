#set.seed(20)
data <- rhyper(10000, m = 25, n = 75, k = 15)
hist(data, breaks = 50, main = "")


print('bai 2')
x <- 5:12
P5_12 = sum(dhyper(x, 25, 75, 15))
print(P5_12)

p1 <- phyper(4, 25, 75, 15)
p2 <- phyper(12, 25, 75, 15)
ans <- p2 - p1
print(ans)


print('bai 3')
curve(dexp(x, 0.6), 0, 10)
curve(dexp(x, 0.3), 0, 10, add = T)
# T�nh P(X <= 2) khi ? = 0.6
ans <- pexp(Inf, rate = 0.6)
print(ans)


print('bai 4')
# �?nh nghia c�c tham s?
lambda <- 1
x <- 0:8

# T�nh x�c su?t
prob <- dpois(x, lambda)

# V? d? th?
plot(x, prob, type = "p")


print('bai 5')
df <- 3  # �? t? do
x <- seq(0, 10, by = 0.1)  # T?o m?t vector c�c gi� tr? t? 0 d?n 10

# T�nh h�m m?t d? x�c su?t
density <- dchisq(x, df = df)

plot(x, density, type = "l")


print('bai 6')
# �?nh nghia c�c tham s?
n <- 50
p <- 0.08
lambda <- 4
x <- 0:50

# Chia c?a s? d? th? th�nh 2 h�ng, 1 c?t
par(mfrow = c(2, 1))

# T�nh x�c su?t cho t?ng ph�n ph?i
prob_binomial <- dbinom(x, size = n, prob = p)
prob_poisson <- dpois(x, lambda = lambda)

# V? d? th? ri�ng bi?t cho m?i ph�n ph?i
# �? th? ph�n ph?i nh? th?c
plot(x, prob_binomial, type = "h", col = "blue",
     ylim = c(0, 0.25),
     xlab = "Success", ylab = "Prob",
     main = "Binomial Distribution (n = 50, p = 0.08)")

# �? th? ph�n ph?i Poisson
plot(x, prob_poisson, type = "h", col = "red",
     ylim = c(0, 0.25),
     xlab = "Success", ylab = "Prob",
     main = "Poisson Distribution (lambda = 4)")


print('bai 7')
# �?nh nghia c�c tham s?
n <- 50
p <- 0.4
mean <- n * p
sd <- sqrt(n * p * (1 - p))
x <- 0:n

# T�nh x�c su?t cho t?ng ph�n ph?i
prob_binomial <- dbinom(x, size = n, prob = p)
prob_normal <- dnorm(x, mean = mean, sd = sd)

# V? d? th? ph�n ph?i nh? th?c
plot(x, prob_binomial, type = "h", col = "blue",
     ylim = c(0, max(prob_binomial, prob_normal)),
     xlab = "S? l?n th�nh c�ng", ylab = "X�c su?t",
     main = "So s�nh ph�n ph?i Nh? th?c v� Chu?n")

# V? th�m d? th? ph�n ph?i chu?n
lines(x, prob_normal, col = "red")
