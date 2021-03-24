import math

n = 600851475143

def is_prime(n):
    for i in range(2, math.floor(math.sqrt(n)+1)):
        if n%i == 0:
            return False
    return True

for i in range(math.floor(math.sqrt(n)+1), 2, -1):
    if n%i == 0 and is_prime(i):
        print(i)
        break
