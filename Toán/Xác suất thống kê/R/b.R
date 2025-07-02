print("Cau 1 bonus")
fy <- function(y) {
	ifelse(0 < y & y < 1, y, 
		ifelse(1 <= y & y < 2, 2-y, 0))
}
#curve(fy,from=-3,to=3)

Fy <- Vectorize(function(y) {
	if (y < 0) {
		return(0)
	} else if (0 <= y & y < 1) {
		return(y^2/2)
	}
	else if (1 <= y & y < 2) {
		return(-1 + 2*y -y^2/2)
	}
	#else if (y < 2) {
	#	integrate(fy, lower = -Inf, upper = y)$value
	#}

	else return(1)
})


curve(Fy, from = -2, to = 4)

#c
print(Fy(1.2) - Fy(0.8))

#d
pAB = 1 - Fy(1.5)
pB = 1 - Fy(1)
print(pAB / pB)

print("Cau 2 Bonus")
tung_dong_xu <- function(n) {
  ket_qua <- sample(0:1, n, replace = TRUE, prob = c(0.5, 0.5))
  return(ket_qua)
}

print(tung_dong_xu(10))

tinh_tien <- function(m) {
	ket_qua <- sample(c(10,-5), m, replace = TRUE, prob = c(0.35, 0.65))
	return(sum(ket_qua))
}

print(tinh_tien(10))