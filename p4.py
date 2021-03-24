for i in range(999,900,-1):
    for j in range(i,900,-1):
        num = str(i*j)
        if num == num[::-1]:
            print(f"{i}*{j} = {num}")
