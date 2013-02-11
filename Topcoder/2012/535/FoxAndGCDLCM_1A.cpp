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

class FoxAndGCDLCM
{
        public:
        long long get(long long G, long long L);
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 2LL; long long Arg1 = 20LL; long long Arg2 = 14LL; verify_case(0, Arg2, get(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 5LL; long long Arg1 = 8LL; long long Arg2 = -1LL; verify_case(1, Arg2, get(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 1000LL; long long Arg1 = 100LL; long long Arg2 = -1LL; verify_case(2, Arg2, get(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 100LL; long long Arg1 = 1000LL; long long Arg2 = 700LL; verify_case(3, Arg2, get(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 10LL; long long Arg1 = 950863963000LL; long long Arg2 = 6298430LL; verify_case(4, Arg2, get(Arg0, Arg1)); }

// END CUT HERE

};

bool prm[1000010];
long long plist[1000010];
int cnt[1000010], num;

long long pp(long long x, int y)
{
	long long ans = 1;
	for(int i = 1; i <= y; i++)
		ans = ans * x;
	return ans;
}

long long FoxAndGCDLCM::get(long long G, long long L)
{
	if(L % G != 0) return -1;
	long long p, q, t;
	int i, j, k;

	p = L / G;
	memset(prm, true, sizeof(prm));
	memset(cnt, 0, sizeof(cnt));
	num = 0;

	for(i = 4; i <= 1000000; i += 2) prm[i] = false;
	for(j = 3; j <= 1000; j += 2)
		if(prm[j])
			for(i = j * j; i <= 1000000; i += j) prm[i] = false;

	q = p; i = 2;
	while(q != 1 && i <= 1000000){
		if(prm[i] && q % i == 0){
			plist[num] = i;
			while(q % i == 0){
				cnt[num]++;
				q /= i;
			}
			num++;
		}
		i++;
	}
	if(q != 1){
		plist[num] = q;
		cnt[num] = 1;
		num++;
	}
	long long ans = 1 + p;
	for(i = 0; i < (1<<num); i++){
		long long tot = 1;
		for(j = 0; j < num; j++)
			if(i & (1<<j)) tot = tot * pp(plist[j], cnt[j]);
		ans = min(ans, tot + p / tot);
	}
	return ans * G;
}

// BEGIN CUT HERE
int main()
{
        FoxAndGCDLCM ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
