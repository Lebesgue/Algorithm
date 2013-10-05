import sys


f = [0] * (48);
f[1] = 1;
for i in range (2, 48):
	f[i] = f[i-1] + f[i-2];

n = int (sys.stdin.readline())
flag = False;
for i in range (48):
	for j in range (i, 48):
		for k in range (j, 48):
			if f[i] + f[j] + f[k] == n:
				a = [f[i], f[j], f[k]];
				flag = True;
				break
		if flag:
			break
	if flag:
		break
if flag:
	print (' '.join (map (str, a)));
else:
	print ('I\'m too stupid to solve this problem');
			
				
			
