def gcd (x, y):
	r = x % y;
	while r != 0:
		x = y;
		y = r;
		r = x % y;
	return y

ans = 1;
for i in range (2, 21):
	ans = i * ans / gcd (i, ans);
	
print (ans);
