#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 400010;
const int MG = 7;

map<int, int> cg;

int pm[N], pmN;
bool isP[N];
int last[N];

void genPrime () {
	int i, j, k;
	memset (isP, true, sizeof (isP));
	last[1] = 1;
	for (i = 2; i <= 700; ++i) {
		if (isP[i]){
			pm[++pmN] = i; last[i] = i;
			for (j = i * i; j <= 400000; j += i) {
				isP[j] = false;
				last[j] = i;
			}
		}
	}
	for (; i <= 400000; ++i)
		if (isP[i]) {
			pm[++pmN] = i;
			last[i] = i;
		}
}

int fLst[300000], fn;
int xx;
long long sum;

void DFS (int x, int cnt, int pd) {
	if (x == fn + 1) {
		long long num = xx / pd;
		sum += (num * num + num) / 2 * pd * (cnt % 2 == 1 ? 1 : -1);
		return;
	}

	DFS (x + 1, cnt, pd);
	if (pd * fLst[x] <= xx)
		DFS (x + 1, cnt + 1, pd * fLst[x]);
}

long long solve (int x) {
	int i;
	
	sum = 0;
	xx = x;
	DFS (1, 0, 1);
	
	return  - sum;			
}

int gcd (int x, int y) {
	int r = x % y;
	while (r) {
		x = y; y = r; r = x % y;
	}
	return y;
}

int main () {
	int i, j, k;
	int n, m, ca;
	genPrime ();
	
	for (scanf ("%d", &ca); ca; --ca) {
		cg.clear ();
		for (scanf ("%d%d", &n, &m); m; --m) {
			int ins, l, r, p;
			scanf ("%d", &ins);
			if (ins == 1) {
				scanf ("%d%d%d", &l, &r, &p);
				fn = 0; int t = p;
				while (t != 1) {
					fLst[++fn] = last[t];
					t /= last[t];
				}
				
				sort (fLst + 1, fLst + fn + 1);
				fn = unique (fLst + 1, fLst + fn + 1) - fLst - 1;
	
				long long ans = solve (r) - solve (l - 1);
				map<int,int>::iterator it;
				for (it = cg.begin (); it != cg.end(); it++)
				{
					int x = it->first, y = it->second;
					if (x >= l && x <= r) {
						ans += gcd (y, p) == 1 ? y : 0;
						ans -= gcd (x, p) == 1 ? x : 0;
					}
				}
				printf ("%I64d\n", ans);
			}
			else {
				scanf ("%d%d", &l, &r);
				cg[l] = r;
			}
		}
	}
	return 0;
}
		
