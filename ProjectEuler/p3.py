import sys;

pm = [];
st = [True]*1000001;

pm.append (2);
for i in xrange (4, 1000001, 2):
	st[i] = False;
for i in xrange (3, 1000001, 2):
	if st[i] == True:
		pm.append (i);
		for j in range (long(i * i), 1000001L, i):
			st[j] = False;

while True:
	n = input ();
	ans = 2;
	for x in pm:
		while n % x == 0:
			n /= x;
			ans = x;
	if n != 1:
		ans = n;
	print ans;
	

	


	
