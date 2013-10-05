#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <list>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;

int d[2][1000011];

int a[511][511];
int main () {
	int i, j, k;
	int n, m;
	scanf ("%d%d", &n, &m);
	if (3 * m > n) {
		printf ("-1");
		return 0;
	}

	for (i = 1; i <= m; ++i) printf ("%d ", i);
	for (i = 1; i <= m; ++i) printf ("%d ", i);
	for (i = 2; i <= m; ++i) printf ("%d ", i); printf ("1 ");
	for (i = 1; i <= n - 3 * m; ++i)
		printf ("1%c", i == (n-3*m) ? '\n' : ' ');
	return 0;
}
