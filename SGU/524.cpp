#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 401;

double a[N], b[N], c[N];
int n;

double calc (double x) {
	double ans = .0, b0;
	for (int i = 1; i <= n; i++)
		c[i] = a[i] - (i - 1) * x;
	sort (c + 1, c + n + 1);
	b0 = n % 2 == 1 ? c[(n+1)/2] : (c[n/2] + c[n/2+1] ) / 2;
	for (int i = 1; i <= n; ++i)
		ans += fabs (a[i] - b0 - (i - 1) * x);
	return ans;
}

int main () {
	int i, j, k;
	scanf ("%d", &n);
	for (i = 1; i <= n; ++i)
		scanf ("%lf", &a[i]);

	double up = a[n] - a[1], low = .0;
	while (up > low + 1e-10) {
		double um = (up + low) / 2, lm = (low + um) / 2;
		double clm = calc (lm), cum = calc (um);

		if (clm > cum + 1e-30)
			low = lm;
		else if (cum > clm + 1e-30)
			up = um;
		else {
			up = um;
			low = lm;
		}
	}
	double ans = .0;
	double m = (up + low) / 2;
	double b0;

	for (i = 1; i <= n; i++)
		c[i] = a[i] - (i - 1) * m;
	sort (c + 1, c + n + 1);

	b0 = n % 2 == 1 ? c[(n+1)/2] : (c[n/2] + c[n/2+1]) / 2;
	
	for (i = 1; i <= n; ++i) {
		b[i] = b0 + (i - 1) * m;
		ans += fabs (a[i] - b[i]);
	}
	printf ("%.7lf\n", ans);
	for (i = 1; i <= n; ++i)
		printf ("%.10lf%c", b[i], i == n ? '\n' : ' ');
	return 0;
}
		
