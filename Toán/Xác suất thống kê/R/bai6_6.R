year <- seq(1970, 1979, 1)
snow.cover <- c(6.5, 12.0, 14.9, 10.0, 10.7, 7.9, 21.9, 12.5, 14.5, 9.2)
plot(year, snow.cover, type = "l", main = "Snow cover in the Northern Hemisphere", xlab = "Year", ylab = "Snow cover")

# plot histogram for snow cover
hist(snow.cover, main = "Histogram of snow cover", xlab = "Snow cover", ylab = "Frequency", col = "lightblue")

# take log of snow cover
log.snow.cover <- log(snow.cover)

plot(year, log.snow.cover, type = "l", main = "Snow cover in the Northern Hemisphere", xlab = "Year", ylab = "Snow cover")

# plot histogram for snow cover
hist(log.snow.cover, main = "Histogram of snow cover", xlab = "Snow cover", ylab = "Frequency", col = "lightblue")