# a
# Data: Scores and frequencies
scores <- c(rep(5, 5), rep(6, 10), rep(7, 15), rep(8, 20), rep(9, 12), rep(10, 8))

# Check the transformed data
print(scores)

# Stem-and-leaf plot
stem(scores)

# b
# Function for one-sided t-test (mu > mu0)
test.geq.oneside <- function(x, mu0, alpha) {
  sample_mean <- mean(x)
  sample_sd <- sd(x)
  n <- length(x)
  
  t_stat <- (sample_mean - mu0) / (sample_sd / sqrt(n))
  df <- n - 1
  
  # mu > mu0
  p_value <- 1 - pt(t_stat, df)
  
  # Compare p-value with alpha
  if (p_value < alpha) {
    result <- paste("Reject H0: The average score is greater than", mu0)
  } else {
    result <- paste("Fail to reject H0: No evidence that the average score is greater than", mu0)
  }
  
  # Output results
  cat("t-statistic:", t_stat, "\n")
  cat("p-value:", p_value, "\n")
  cat(result, "\n")
}

# Apply the function with data, mu = 8, and alpha = 0.05
test.geq.oneside(scores, mu0 = 8, alpha = 0.05)


# c
# Function for one-sided t-test (mu < mu0)
test.leq.oneside <- function(x, mu0, alpha) {
  sample_mean <- mean(x)
  sample_sd <- sd(x)
  n <- length(x)
  
  t_stat <- (sample_mean - mu0) / (sample_sd / sqrt(n))
  df <- n - 1
  
  # mu < mu0
  p_value <- pt(t_stat, df)
  
  # Compare p-value with alpha
  if (p_value < alpha) {
    result <- paste("Reject H0: The average score is less than", mu0)
  } else {
    result <- paste("Fail to reject H0: No evidence that the average score is less than", mu0)
  }
  
  # Output results
  cat("t-statistic:", t_stat, "\n")
  cat("p-value:", p_value, "\n")
  cat(result, "\n")
}

# Apply the function with data, mu = 8, and alpha = 0.05
test.leq.oneside(scores, mu0 = 8, alpha = 0.05)