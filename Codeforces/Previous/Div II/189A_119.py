n, a, b, c = map (int, raw_input().split());
d = [];
for i in xrange (n + 1):
	d.append(0);

for i in xrange (1, n + 1):
	for j in [a, b, c]:
		if i == j or (i > j and d[i-j] != 0):
			d[i] = max (d[i], 1 + d[i - j]);
print d[n];

