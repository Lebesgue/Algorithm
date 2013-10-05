

n, m = map (int, raw_input().split());

d = [ [False for i in xrange (251)] for j in xrange (n + 1)];

d[0][0] = True;

for cnt in xrange (0, n):
	for i in xrange (0, 251):
		if d[cnt][i] == True:
			if i + 3 <= 250:
				d[cnt+1][i+3] = True;
			if i + 4 <= 250:
				d[cnt+1][i+4] = True;
			if i + 5 <= 250:
				d[cnt+1][i+5] = True;

for i in xrange (n + 1):
	if m >= 2 * i and d[n-i][m - 2*i] == True:
		ans = i;
		break
print ans;
