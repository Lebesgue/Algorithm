import sys

[n, m] = list (map (int, sys.stdin.readline().split()));
ba = [i + 1 for i in range (m)];
ba = sorted (ba, key = lambda x: abs(float(m+1)/2 - x))
print ('\n'.join([str(ba[i%m]) for i in range (n)]));
