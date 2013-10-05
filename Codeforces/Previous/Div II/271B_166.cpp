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

bool isp[110011];
vector<int>p;
int r[511], c[511];
void genPrime () {
	int i, j, k;
	memset (isp, true, sizeof (isp));
	for (i = 2; i < 1000; ++i) {
		if (isp[i])
			for (j = i * i; j <= 110000; j += i)
				isp[j] = false;
	}
	p.push_back(2);
	for (i = 3; i <= 110000; i+=2)
		if (isp[i]) p.push_back(i);
}

int a[511][511];
int main () {
	int i, j, k, m, n;
	genPrime ();
	scanf ("%d%d", &m, &n);
	for (i = 1; i <= m; ++i)
		for (j = 1; j <= n; ++j) {
			scanf ("%d", &a[i][j]);
			a[i][j] = *lower_bound (p.begin(), p.end(), a[i][j]) - a[i][j];
			r[i] += a[i][j];
			c[j] += a[i][j];
		}
	int ans = 1000000011;
	for (i = 1; i <= m; ++i) ans = min (ans, r[i]);
	for (j = 1; j <= n; ++j) ans = min (ans, c[j]);
	printf ("%d\n", ans);
	return 0;

}
