data <- read.csv("data32.csv", header = T)
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

print(mean(data$KHTN))
ci.mean(data$KHTN, 0.05)

ci.prop <- function(f, n, alpha) {
  p_hat <- f / n  # T? l? m?u
  z <- qnorm(1 - alpha / 2)  # Giá tr? z t?i h?n t? phân ph?i chu?n
  
  se <- sqrt(p_hat * (1 - p_hat) / n)
  epsilon <- z * se

  cat('KTC', (1 - alpha) * 100, '% cho ty le: [', p_hat - epsilon, ';', p_hat + epsilon, ']\n')
 
}

f <- sum(data$KHTN > 5)
n <- 120
print(f/n)
ci.prop(f, n, 0.1)
ci.prop(f, n, 0.05)
ci.prop(f, n, 0.01)
