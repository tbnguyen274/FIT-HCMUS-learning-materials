ktc.tb <- function(xbar, sigma = NULL, S = NULL, n, alpha) {
  
  # X�c d?nh m?c tin c?y
  confidence <- (1 - alpha) * 100
  
  # Tru?ng h?p 1: �? l?ch chu?n t?ng th? bi?t tru?c (d�ng Z)
  if (!is.null(sigma)) {
    z_value <- qnorm(1 - alpha / 2)  # Tra ph�n ph?i chu?n
    epsilon <- z_value * sigma / sqrt(n)
	
  }
  
  # Tru?ng h?p 2: �? l?ch chu?n t?ng th? kh�ng bi?t
  else {
  	if (n >= 30) {
		z <- qnorm(1 - alpha / 2)
		epsilon <- z * S / sqrt(n)
	} else {
		t <- qt(1 - alpha / 2, df = n - 1)
		epsilon <- t * S / sqrt(n)
	}
  }

  cat('KTC', confidence, '% cho trung binh: [', xbar - epsilon, ';', xbar + epsilon, ']\n')

}

# Test
ktc.tb(xbar = 50, s = 12, n = 25, alpha = 0.05)

