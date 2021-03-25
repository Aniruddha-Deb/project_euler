import math

plist = []
i = 2
while len(plist) <= 10000:
    is_prime = True
    li = math.ceil(math.sqrt(i))
    for n in plist:
        if li < n:
            break
        if i % n == 0:
            is_prime = False
            break
    if is_prime:
        print(i)
        plist.append(i)
    i += 1
        
