#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int N = 100011;

bool pm[N];
vector<int>prL;
int pn;

void genPrime () {
	int i, j, k;
	fill (pm, pm + N, true);
	for (i = 2; i * i < N; ++i)
		if (pm[i]) {
			prL.push_back (i);
			for (j = i * i; j < N; pm[j] = false, j += i);
		}
	for (; i < N; ++i)
		if (pm[i]) prL.push_back (i);
	
	pn = prL.size ();
}

int n, m;
long long ans;

int pp (int x, int e) {
	int ans = 1;
	for (int i = 1; i <= e; i++)
		ans = ans * x;
	return ans;
}

void DFS (const vector<pair<int,int> > &a, int x, long long t) {
	if (x == a.size ()) {
		while (t != 0) {
			int p = t % m;
			ans += p * p;
			t /= m;
		}
		return;
	}
	int cnt = a[x].second;
	for (int i = 0; i <= cnt; ++i)
		DFS (a, x + 1, t * pp (a[x].first, i));
}

inline void prt (int x) {
	if (x < 10) printf ("%d", x);
	else printf ("%c", (x - 10) + 'A');
}

void output (int x) {
	if (x == 0) return;
	output (x / m);
	prt (x % m);
}

int main () {
	int i, j, k;
	genPrime ();
	
//	freopen ("in", "r", stdin);
	
	while (scanf ("%d%d", &n, &m) == 2) {
		vector<pair<int,int> >pC;
		for (i = 0; i < pn; ++i) {
			k = 0;
			while (n % prL[i] == 0) {
				++k;
				n /= prL[i];
			}
			if (k) pC.push_back (make_pair(prL[i], k));
		}
		if (n != 1)
			pC.push_back (make_pair (n, 1));
		ans = 0;
		DFS (pC, 0, 1);
		output (ans); printf ("\n");
	}
	return 0;
}
