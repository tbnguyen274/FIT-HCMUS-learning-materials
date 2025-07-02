data <- read.csv("data31.csv", header = T)
print(data)

ci.mean <- function(x, alpha) {
	n <- length(x)
	xbar <- mean(x)
	S <- sd(x)

	if (n >= 30) {
		z <- qnorm(1 - alpha / 2)
		epsilon <- z * S / sqrt(n)
	} else {
		t <- qt(1 - alpha / 2, df = n - 1)
		epsilon <- t * S / sqrt(n)
	}

	cat('KTC', (1 - alpha) * 100, '% cho trung binh: [', xbar - epsilon, ';', xbar + epsilon, ']\n')
}

print(mean(data$profit))
ci.mean(data$profit, 0.05)
ci.mean(data$profit, 0.01)


