#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100010;

int pos[N], a[N];
long long x, y;

int main () {
	int i, j, k;
	int n, m;
	cin >> n;
	for (i = 1; i <= n; cin >> j, pos[j] = i, ++i);

	for (cin >> m; m; --m) {
		scanf ("%d", &j);
		x += pos[j];
		y += n - pos[j] + 1;
	}
	cout << x << " " << y << endl;
	return 0;
}
