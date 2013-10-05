[n, k] = map (int, raw_input().split ());
a = map (int, raw_input().split ());
for i in xrange (2 * n + 1):
	if k == 0:
		break
	if i % 2 == 1 and a[i] > a[i-1] + 1 and a[i] > a[i+1] + 1:
		a[i] -= 1;
		k -= 1;
print ' '.join(map (str, a));
