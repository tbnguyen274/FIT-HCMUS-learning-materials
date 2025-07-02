print("Cau 1")
f = function(p) {.07 * p**(-0.93)}

check = integrate(f, lower=0, upper=0.2)
print(check)

check_pdf = integrate(f, lower = 0, upper = 1)
print(check_pdf)

print("Cau 2")
x=sample(1:5,100,TRUE,c(0.1,0.2,0.4,0.2,0.1))

probabilities <- table(x) / 100

print(probabilities)





