sum = 2
n1 = 1
n2 = 2
while n2 < 4000000:
    temp = n1
    n1 = n2
    n2 = n1 + temp
    if n2%2 == 0:
        sum += n2
        print(n2)
print(sum)
