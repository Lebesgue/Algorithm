import urllib

fin = urllib.urlopen ('http://projecteuler.net/project/matrix.txt');
a = [];
for cnt in xrange (80):
	a.append (map (int, fin.readline().split (',')))

d = [ [100000000000000 for i in xrange (81)] for j in xrange (81)];
d[0][1] = 0;
for i in xrange (1, 81):
	for j in xrange (1, 81):
		d[i][j] = min (d[i][j - 1], d[i - 1][j]) + a[i-1][j-1];
print d[80][80];

