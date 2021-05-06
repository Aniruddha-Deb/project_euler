import sys
import numpy as np
from pprint import pprint

mat = np.zeros((40,40))
prob = [1/16,1/8,3/16,1/4,3/16,1/8,1/16]

for i in range(40):
	for j in range(7):
		mat[(i+2+j)%40][i] = prob[j]

cc_loc = [2, 17, 36]
ch_loc = [7, 22, 33]


pprint(mat.tolist())
