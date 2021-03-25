import math

plist = []
for i in range(2,2000000):
    is_prime = True
    li = math.ceil(math.sqrt(i))
    for n in plist:
        if n > li:
            break
        if i % n == 0:
            is_prime = False
            break
    if is_prime:
        plist.append(i)

print(sum(plist))
