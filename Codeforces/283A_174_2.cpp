#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200011;

int a[N], n, cur;
long long ans;

int main () {
	int i, j, k;
	a[cur = 1] = 0;
	for (scanf ("%d", &n); n; --n) {
		scanf ("%d", &k);
		if (k == 1) {
			scanf ("%d%d", &i, &j);
			if (cur == i)
				a[i] += j;
			else
				a[i] -= j;
			ans += j * i;
		}
		else if (k == 2) {
			scanf ("%d", &i);
			a[cur] = i - a[cur];
			a[++cur] = i; ans += i;
		}
		else {
			a[cur - 1] = a[cur] - a[cur - 1];
			ans -= a[cur--];
		}
		printf ("%.15lf\n", double (ans) / cur);
	}
	return 0;
}
