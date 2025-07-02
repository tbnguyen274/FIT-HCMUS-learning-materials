data <- data.frame(
  Temperature = c(53, 57, 63, 70, 70, 75),
  Erosion_incidents = c(3, 1, 1, 1, 1, 0),
  Blowby_incidents = c(2, 0, 0, 0, 0, 2),
  Total_incidents = c(5, 1, 1, 1, 1, 1)
)

print(data)

plot(data$Temperature, data$Total_incidents, type = "l", main = "Total incidents by temperature",
                                                 xlab = "Temperature", ylab = "Total incidents")