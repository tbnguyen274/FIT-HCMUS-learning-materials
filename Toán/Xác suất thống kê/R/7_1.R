x <- rnorm(35, 10, 5)	# make sample
alpha <- 0.05
xbar <- mean(x)
z <- qnorm(1 - alpha/2)
sigma <- 5
n <- 35
epsilon <- z * sigma / sqrt(n)
cat('KTC', (1 - alpha) * 100, '% cho trung binh: [', xbar - epsilon, ';', xbar + epsilon, ']\n')
