#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstring>


using namespace std;

const int N = 300011;
map<int,int> ord, rev;
long long possum[N];
int cntneg[N];

int a[N], n;

long long f(int x, int y) {
	return possum[y-1]-possum[x] + a[x] + a[y];
}

int g(int x, int y) {
	return cntneg[y-1]-cntneg[x];
}

int main () {
	int i, j, k;
	scanf ("%d", &n);
	memset(cntneg, 0, sizeof(cntneg));
	memset(possum, 0, sizeof(possum));
	
	for (i = 1; i <= n; ++i) {
		scanf ("%d", &a[i]);
		possum[i] = possum[i-1] + max(a[i], 0);
		cntneg[i] = cntneg[i-1] + (a[i] < 0 ? 1 : 0);
		if (ord.find(a[i]) != ord.end()) continue;
		else ord[a[i]] = i;
	}
	for (i = n; i >= 1; --i) {
		if (rev.find(a[i]) != rev.end()) continue;
		else rev[a[i]] = i;
	}
	int bestx, besty;
	long long best = -1000000000000000;
	for (i = 1; i <= n; ++i) {
		int x = ord[a[i]], y = rev[a[i]];
		if (x != i || ord[a[i]] == rev[a[i]]) continue;
		long long t;
		if ((t = f(x, y)) > best) {
			best = t;
			bestx = x;
			besty = y;
		}
		
	}
	printf ("%I64d %d\n", best, g(bestx, besty) + bestx - 1 + n - besty);
	for (i = 1; i < bestx; printf("%d ", i++));
	for (i = bestx + 1; i < besty; ++i)
		if (a[i] < 0) printf ("%d ", i);
	for (i = besty+1; i <= n; printf("%d ", i++));
	return 0;
}
