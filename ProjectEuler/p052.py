def chk (x) :
	lst = [];
	for i in xrange (2, 7):
		lst.append (''.join(sorted (str (i * x))))
	ans = True;
	
	for i in xrange (0, 5):
		if i < 4 and lst[i] != lst[i+1]:
			ans = False;
			break
	return ans;
	
for i in xrange (1, 10000000000):
	if chk (i):
		ans = i;
		break

print ans;

