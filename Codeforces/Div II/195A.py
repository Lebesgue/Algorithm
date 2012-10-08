import sys
[a, b, c] = list (map (int, sys.stdin.readline().split()));



for t in range (1, a * c + 1):
	if a * t * b >= a * c * (a-b):
		print (t);
		break
