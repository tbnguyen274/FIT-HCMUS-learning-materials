# a
data <- read.delim("teen-birth-rate-2002.txt", header=TRUE)
print(data)

# Remove rows where all values in the relevant columns are NA (e.g., "Residence Unknown", "Guam", "Puerto Rico", "Virgin Islands")
data_cleaned <- data[!apply(is.na(data[, 2:4]), 1, all), ]

# Inspect the cleaned data
print(data_cleaned)

# Calculate the means, standard deviations, and sample sizes for each group
means <- colMeans(data_cleaned[, 2:4], na.rm = TRUE)
sds <- apply(data_cleaned[, 2:4], 2, sd, na.rm = TRUE)
ns <- apply(data_cleaned[, 2:4], 2, function(x) sum(!is.na(x)))

# Compute the overall mean (mu_0)
mu_0 <- weighted.mean(means, ns)


# Display the overall mean
cat("Overall mean (mu_0):", mu_0, "\n")

# Calculate Z-statistics and p-values
Z <- (means - mu_0) / (sds / sqrt(ns))
p_values <- 2 * (1 - pnorm(abs(Z)))  # Two-tailed p-value

# Create a table of the results
order <- c("Black", "Hispanic", "White")
results <- data.frame(
  X = means[order],
  S = sds[order],
  n = ns[order],
  Z = Z[order],
  p = p_values[order]
)

# Print the results
print(results)
