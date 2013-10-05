#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int main () {
	int i, j, k;
	priority_queue<int> pm, pi;
	int n, m;
	scanf ("%d%d", &n, &m);
	for (i = 1; i <= m; i++) {
		scanf ("%d", &j);
		pm.push (j);
		pi.push (-j);
	}
	int am = 0, ai = 0;
	for (i = 1; i <= n; ++i) {
		am += (j = pm.top ());
		pm.pop ();
		if (j > 1)
			pm.push (j - 1);

		ai += (j = (-pi.top ()));
		pi.pop ();
		if (j > 1)
			pi.push (-(j - 1));
	}
	printf ("%d %d\n", am, ai);
	return 0;
}
