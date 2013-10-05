import sys

r = lambda : list (map (int, sys.stdin.readline().split()));

[n] = r();
[x] = r();

ans = 'YES';
for i in range (n):
	[a, b] = r ();
	if x == a or x == b or x + a == 7 or x + b == 7:
		ans = 'NO';
		break

print (ans);
