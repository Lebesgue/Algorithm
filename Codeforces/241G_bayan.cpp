#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int main () {
	int n = 400;
	int metaN = 400;
	int ma = 600;
	int i, j, k;

	printf ("%d\n", n + 2);
	printf ("%d %d\n", 0, ma * ma);
	for (i = metaN, j = 0, k = ma * ma; i >= 1; --i) {
		j += ceil (2 * sqrt (k * (double)i)) + 1;
		printf ("%d %d\n", j, i);
		k = i;
	}
	printf ("%d %d\n", j + 2 * ma + 1, (ma + 1) * (ma + 1));
	return 0;
}
	
		
		
	
