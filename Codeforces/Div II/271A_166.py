n = input ();
i = n;

while True:
	i += 1;
	a = []; j = i;
	while j != 0:
		a.append (j%10);
		j /= 10;
	if len(a) == len(set(a)):
		print i
		break;
