# a
binom_values <- rbinom(100, size = 60, prob = 0.4)
hist(binom_values, breaks = 10, col = "lightblue", main = "Histogram of Binomial Distribution",
     xlab = "Number of Successes", ylab = "Frequency")
# b
poisson_values <- rpois(100, lambda = 4)
hist(poisson_values, breaks = 10, col = "lightgreen", main = "Histogram of Poisson Distribution",
     xlab = "Number of Events", ylab = "Frequency")

# c
norm_values <- rnorm(100, mean = 50, sd = 4)

plot(ecdf(norm_values), main = "Cumulative Distribution Function of Normal Distribution",
     xlab = "Values", ylab = "CDF", col = "blue")

plot(density(norm_values), main = "Density Function of Normal Distribution",
     xlab = "Values", ylab = "Density", col = "red")

# d
lambda <- 1/25
exp_values <- rexp(100, rate = lambda)

plot(ecdf(exp_values), main = "Cumulative Distribution Function of Exponential Distribution",
     xlab = "Values", ylab = "CDF", col = "blue")

plot(density(exp_values), main = "Density Function of Exponential Distribution",
     xlab = "Values", ylab = "Density", col = "red")
