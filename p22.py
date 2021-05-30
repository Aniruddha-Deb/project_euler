names_file = open("p022_names.txt")
names = names_file.read().splitlines()

names.sort()

print(names)

weight = 0
i = 1
for name in names:
	name_wt = 0;
	for letter in name:
		name_wt += (ord(letter) - 65) + 1
	weight += (name_wt*i)
	i += 1

print(weight)
