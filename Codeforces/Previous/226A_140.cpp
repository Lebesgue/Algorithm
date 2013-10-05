#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n, m;

int main () {
	int i, j, k;
	scanf ("%d%d", &n, &m);
	int p[40], cnt = 0;
	while (n != 0) {
		p[++cnt] = n % 2;
		n /= 2;
	}
	long long ans = 1;
	for (i = cnt; i >= 1; --i) {
		ans = (ans * ans) % m;
		if (p[i])
			ans = (ans * 3) % m;
	}
	cout << (ans + m - 1) % m << endl;
	return 0;
}
