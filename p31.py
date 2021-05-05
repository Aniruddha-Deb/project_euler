import functools
coins = [200,100,50,20,10,5,2,1]

@functools.lru_cache(maxsize=None)
def cs_rec(n, t):
	print(n)
	if n == 0:
		return 1
	cs = [i for i in coins if i<=n and i<=t]
	return sum([cs_rec(n-k,k) for k in cs])

print(cs_rec(200,200))
