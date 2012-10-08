#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <list>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(v) (int)v.size()
#define clr(x, v) memset(x, v, sizeof(x))
#define rep(i, l, u) for(int i = (l); i < (u); i++)
#define repv(i, v) for(i = 0; i < (int)v.size(); i++)
#define repi(it, c) for(typeof(c.begin()) it = c.begin(); it != c.end(); ++it)
#define L(rt) seg[(rt)].l
#define R(rt) seg[(rt)].r
#define SS(rt) seg[(rt)].S

const int N = 500010;
const int INF = 2000000010;

struct node{
	int be, en, f, id;
	bool operator<(const node &x) const{ return be == x.be ? en < x.en : be < x.be;}
}bus[N], cus[N];

struct Snode{
	int l, r;
	set<int>S;
}seg[(2*N)*3];

vector<PII> tid;
int lst[2*N], cnt;

void build (int h, int ll, int rr) {
	L(h) = ll; R(h) = rr; SS(h).insert(INF);
	if(ll == rr) return;
	int mid = (ll + rr) >> 1;
	build(h << 1, ll, mid); build(h << 1 | 1, mid + 1, rr);
}

void insert (int h, int pos, int f) {
	SS(h).insert(f);
	if (L(h) == R(h)) return;
	int mid = (L(h) + R(h)) >> 1;
	if (pos <= mid) insert (h << 1, pos, f);
	else insert (h << 1 | 1, pos, f);
}

int query (int h, int pos, int f) {
	if (pos <= L(h)) return *SS(h).lower_bound(f);
	int mid = (L(h) + R(h)) >> 1;
	int i = query (h << 1 | 1, pos, f), j = INF;
	if (pos <= mid) j = query ( h << 1, pos, f);
	return min (i, j);
}

int main()
{
	int i, j, k, n, m;
	int ans[N];

	scanf("%d%d",&n, &m);
	for (i = 1; i <= n; i++) {
		scanf ("%d%d%d",&bus[i].be, &bus[i].en, &bus[i].f);
		bus[i].id = i; tid.pb(mp(bus[i].f, i));
		lst[cnt++] = bus[i].en;
	}
	for (j = 1; j <= m; j++) {
		scanf ("%d%d%d",&cus[j].be, &cus[j].en, &cus[j].f);
		cus[j].id = j;
		lst[cnt++] = cus[j].en;
	}
	tid.pb(mp(INF, -1));
	sort (lst, lst + cnt);
	sort (bus + 1, bus + n + 1);
	sort (cus + 1, cus + m + 1);
	sort (tid.begin(), tid.end());
	k = unique(lst, lst + cnt) - lst;

	memset (ans, -1, sizeof(ans));
	build(1, 0, cnt - 1);
	for (int cid = 1, bid = 1; cid <= m; cid ++) {
		while (bid <= n && bus[bid].be <= cus[cid].be) {
			k = lower_bound (lst, lst + cnt, bus[bid].en) - lst; //printf("bus %d\n", k);
			insert (1, k, bus[bid].f);
			bid ++;
		}
		k = lower_bound (lst, lst + cnt, cus[cid].en) - lst; //printf("cus %d\n", k);
		j = query (1, k, cus[cid].f); //printf("j %d\n", j);
		ans[cus[cid].id] = lower_bound(tid.begin(), tid.end(), mp(j, -1))->ss;
	}
	for (i = 1; i <= m; i++)
		printf("%d%c", ans[i], i == m? '\n' : ' ');
	return 0;
}


