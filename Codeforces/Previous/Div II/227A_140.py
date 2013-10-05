import sys

r = lambda : list (map (int, sys.stdin.readline().split()));

A = r ();
B = r ();
C = r ();

x1 = B[0] - A[0]; y1 = B[1] - A[1];
x2 = C[0] - B[0]; y2 = C[1] - B[1];

if x1*y2 == x2 * y1:
	print ('TOWARDS');
elif x1 * y2 < x2 * y1:
	print ('RIGHT');
else:
	print ('LEFT');
