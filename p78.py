import functools

def coinp(n):
	if n == 1:
		return 1 
	return 1 + coinp(n-1)
