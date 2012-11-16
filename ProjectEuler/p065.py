import math
def Pell (n, a0):

	p0, p1, q0, q1 = 0, 1, 1, 0;
	g, h = 0, 1;
	a = a0;
	while True:
		p = a * p1 + p0;
		q = a * q1 + q0;
		if p * p - n * q * q == 1:
			return p, q

		p0 = p1; p1 = p;
		q0 = q1; q1 = q;
		
		g = -g + a * h;
		h = (n - g * g) / h;
		a = (g + a0) // h;


# How to compute CF for any irrational number to arbitrary precision ?

def ProjectEuler66 ():
	ma = -1; ans = -1;
	for n in xrange (1, 1001):
		a0 = int  (math.floor (math.sqrt (n)));
		if a0 * a0 == n:
			continue
		
		x, y = Pell (n, a0);
		print n, x;
		if x > ma:
			ma = x;
			ans = n;
			
	print ans;

def ProjectEuler65 ():
	v = math.e
	a0 = int (v);

	p0, p1, q0, q1 = 1, a0, 0, 1;
	k = 0;
	for i in xrange (1, 100):
		a = 1;
		if i % 3 == 2:
			k += 2;
			a = k;

		p , q = a * p1 + p0, a * q1 + q0;
		p0 = p1; p1 = p; q0 = q1; q1 = q;
		
	k = 0; x = int (p);
	while x != 0:
		k += x % 10;
		x //= 10;
	print k

if __name__ == "__main__":
	ProjectEuler65 ();

		




