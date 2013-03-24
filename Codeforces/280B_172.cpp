#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100011;
int a[N], f[N], st[N], top;
int n;

int main () {
	int i, j, k;
	scanf ("%d", &n);
	for (i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);

	top = 0;
	memset (f, -1, sizeof (f));
	for (i = 1; i <= n; ++i) {
		while (top > 0 && a[i] > a[st[top]]) {
			f[i] = max (f[i], (a[i] ^ a[st[top]]));
			top--;
		}
		st[++top] = i;
	}
	reverse (a + 1, a + n + 1);
	reverse (f + 1, f + n + 1);


	top = 0;
	for (i = 1; i <= n; ++i) {
		while (top > 0 && a[i] > a[st[top]]) {
			f[i] = max (f[i], (a[i] ^ a[st[top]]));
			top--;
		}
		st[++top] = i;
	}
	printf ("%d\n", *max_element (f + 1, f + n + 1));
}

