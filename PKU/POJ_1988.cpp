#include <cstdio>
#include <cstring>
using namespace std;

#define clr(x,v) memset ((x), (v), sizeof((x)))

const int N = 30010;

int pa[N], up[N], sz[N];
int n;

int find (int x) {
	if (pa[x] == -1) return x;
	int j = pa[x];
	pa[x] = find (pa[x]);
	up[x] += up[j];
	return pa[x];
}

int main()
{
	int i, j, k, Q, x, y;
	char ch;

	for (i = 0; i < N; i++) pa[i] = -1, sz[i] = 1, up[i] = 0;
	for (scanf ("%d",&Q); Q; Q--) {
		getchar();
		scanf ("%c", &ch);
		if (ch == 'M') {
			scanf ("%d%d",&x, &y);
			x = find (x), y = find (y);
			pa[y] = x;
			up[y] += sz[x];
			sz[x] += sz[y];
		}
		else if (ch == 'C') {
			scanf ("%d", &x);
			int xx = find (x);
			printf ("%d\n", sz[xx] - up[x] - 1);
		}
	}
	return 0;
}

