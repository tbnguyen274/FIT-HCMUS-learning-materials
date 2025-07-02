heights <- c(rep(1.3, 6),    # [1.2, 1.4) trung bình khoang: 1.3
             rep(1.5, 34),   # [1.4, 1.6) trung bình khoang: 1.5
             rep(1.7, 31),   # [1.6, 1.8) trung bình khoang: 1.7
             rep(1.9, 42),   # [1.8, 2.0) trung bình khoang: 1.9
             rep(2.1, 12))   # [2.0, 2.2) trung bình khoang: 2.1

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

ci.prop <- function(f, n, alpha) {
  p_hat <- f / n  # Ty le mau
  z <- qnorm(1 - alpha / 2)
  
  se <- sqrt(p_hat * (1 - p_hat) / n)
  epsilon <- z * se

  cat('KTC', (1 - alpha) * 100, '% cho ty le: [', p_hat - epsilon, ';', p_hat + epsilon, ']\n')
 
}

ci.mean(heights, alpha = 0.05)

f <- sum(heights >= 1.7)  # S? ngu?i th?a yêu c?u
n <- length(heights)      # T?ng s? thanh niên
ci.prop(f, n, alpha = 0.05)
