import sys
s , x, x1, x2= [0, 0, 1, 0];
while x <= 4000000:
	x = x1 + x2;
	if x <= 4000000 and x % 2 == 0:
		s += x;
	x2 = x1; x1 = x; 
print (s);
