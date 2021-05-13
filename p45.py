import math

def isint(n):
	return (n % 1) == 0

for i in range(1,100000):
	y = i*(i+1)/2
	r1 = (math.sqrt(1+24*y)+1)/6
	if isint(r1):
		print(y, r1)
