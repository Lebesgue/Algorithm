#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define F(x) de[(x)].f
#define S(x) de[(x)].s
#define P(x) de[(x)].p
#define DEBUG 0

const int N = 50010;

struct de_node {
	int f, s;
	int p;
	de_node (){};
	de_node (int f1, int s1, int p1) : f(f1), s(s1), p(p1) {};
}de[N];

int n, top;
long long a[N], d[N], L;

int findPos (int x) {
	int up = top, low = 1;
	if (up == low) return up;
	while (true) {
		int mid = (up + low) >> 1;
		if (F(mid) <= x && S(mid) >= x) return mid;
		if (x < F(mid)) up = mid - 1;
		else if (x > S(mid)) low = mid + 1;
	}
}

inline long long calc (int x, int j) {
	long long len = a[x] - a[j] + x - j - 1;
	return d[j] + (L - len) * (L - len);
}
inline void pushDe (int x, int y, int p) { de[++top] = de_node (x, y, p);}
int main () {
	int i, j, k;
	scanf ("%d%Ld", &n, &L);
	for (i = 1; i <= n; i++) {
		scanf ("%Ld", &a[i]);
		a[i] += a[i-1];
	}

	pushDe (1, n, 0);
	for (i = 1; i <= n; i++) {
		int pos = findPos (i);
		d[i] = calc (i, P(pos));

		while (F(top) > i && calc (F(top), i) <= calc (F(top), P(top))) top --;
		if (S(top) <= i || calc (S(top), i) > calc (S(top), P(top))) {
			if ( (j = S(top)) != n)
				pushDe (S(top) + 1, n, i);
			continue;

		}
		int up = S(top), low = max (i + 1, F(top));
		while (up > low) {
			int mid = (up + low) >> 1;
			if (calc (mid, i) <= calc (mid, P(top))) up = mid;
			else low = mid + 1;
		}
		S(top) = up - 1;
		pushDe (up, n, i);
#if DEBUG
		printf ("after %dth update\n", i);
		for (j = 1; j <= top; j++)
			printf ("%d %d %d\n", F(j), S(j), P(j));
		printf ("optimal value: ");
		for (j = 1; j <= n; j++)
			printf ("%Ld%c", d[j], j == n ? '\n' : ' ');
#endif
	}
	printf ("%Ld\n", d[n]);
	return 0;
}



