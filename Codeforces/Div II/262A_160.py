[n, k] = map (int, raw_input().split())
a = map (int, raw_input().split());
ans = 0;
for i in a:
	cnt = 0;
	while i != 0:
		j = i % 10;
		if j == 4 or j == 7:
			cnt += 1
		i = i // 10;
	if cnt <= k:
		ans += 1;
print ans
		
