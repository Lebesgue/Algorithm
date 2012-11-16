md = 10000000000;
ans = 0;
for i in range (1, 1001):
	ans += i ** i;
print (ans % md);
