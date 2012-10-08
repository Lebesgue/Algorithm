import math
x1, y1, r1 = map (float, raw_input().split());
x2, y2, r2 = map (float, raw_input().split());

d = math.sqrt ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

t1 = max (r1, r2);
t2 = min (r1, r2);

if d > r1 + r2:
	print "%.15f\n"%((d - r1 - r2)/2);
elif d + t2 < t1:
	print "%.15f\n"%((t1 - d - t2)/2);
else:
	print "%.15f\n"%(0);
	
