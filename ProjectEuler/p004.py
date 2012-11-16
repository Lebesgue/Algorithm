ans = -1;
for i in range (999, 99, -1):
	for j in range (999, 99, -1):
		t = i * j;
		s = str(t);
		if s == s[::-1] and t > ans:
			ans = t;
print (ans);

	

