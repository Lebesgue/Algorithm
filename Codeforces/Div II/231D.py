rint = lambda: map (int, raw_input() .split ());

[a, b, c] = rint ();
[x, y, z] = rint ();
A = rint ();
B = [b, b - y, c, c - z, a, a - x];
d = [-1, 1, -1, 1, -1, 1];
ans = 0;

for i in xrange (6):
	if B[i] * d[i] > 0:
		ans += A[i];
print ans;
