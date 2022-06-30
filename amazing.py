from itertools import chain, combinations

def powerset(iterable):
    "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))

s = list(range(1,36))

ans = 0;
for s in powerset(s):
	if sum(s) % 7 == 0:
		ans += 1

print(ans)
