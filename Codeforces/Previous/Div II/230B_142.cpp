#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <list>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

const int N = 1000010;

bool p[N];

int main () {
	int i, j, k;
	memset (p, true, sizeof (p));
	for (i = 2; i <= 1000; ++i) {
		if (p[i]) 
			for (j = i * i; j <= 1000000; p[j] = false, j += i);
	}
	for (cin >> k; k; --k) {
		long long x, y;
		cin >> y;
		x = (int) sqrt (1.0 * y);
		if (y != 1 && y == x * x && p[x])
			printf ("YES\n");
		else
			printf ("NO\n");
	}
	return 0;
}
