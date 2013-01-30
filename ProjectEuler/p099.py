import urllib, math

fin = urllib.urlopen ('http://projecteuler.net/project/base_exp.txt');

mx = -1;
cnt = 0;
while True:
	s = fin.readline();
	if len (s) == 0:
		break
	[a, b] = map (int, s.split(','));
	t = b * math.log (a);
	cnt += 1;
	if t > mx:
		mx = t;
		ans = cnt;
print ans;
	
	
