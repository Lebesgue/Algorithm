# There is a way more simpler solution noticing that boxes of different sizes are really independent.
from math import *

n = input ();
d = [map (int, raw_input().split()) for i in xrange (n)];

d.sort (key = lambda x : x[0]);

for i in xrange (n - 1):
	p1 = d[i]; p2 = d[i+1];
	if log (p1[1] / (float (p2[1])), 4) <= p2[0] - p1[0]:
		continue
	else:
		cnt = 4 ** (p2[0] - p1[0]);
		d[i+1][1] += ((p1[1] - cnt * p2[1]) + cnt - 1) / cnt;

print "%d" % (d[n - 1][0] + max (1, ceil (log (d[n - 1][1], 4))));









	
	
