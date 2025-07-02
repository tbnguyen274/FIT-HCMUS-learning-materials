k = 0:8;
p = function(k) choose(8,k) * 0.3^k * 0.7^(8-k);
p(k)
print(p(k))
print(sum(p(k)))

f = function(x, mu=0, sigma=1){
	1/sqrt(2*pi*sigma^2) * exp(-(x-mu)^2/(2*sigma^2))
}
