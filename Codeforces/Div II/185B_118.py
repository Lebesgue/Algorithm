S = input ();
a, b, c = map (int, raw_input().split());
if a == 0 and b == 0 and c == 0:
	print ("%d 0 0"%(S));
else:
	print ("%.15f %.15f %.15f"%( float(a)*S/(a+b+c), float(b)*S/(a+b+c), float(c)*S/(a+b+c)));

