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

class MonsterFarm
{
        public:
        int numMonsters(vector <string> transforms);
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, numMonsters(Arg0)); }
	void test_case_1() { string Arr0[] = {"1 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, numMonsters(Arg0)); }
	void test_case_2() { string Arr0[] = {"2", "3", "1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, numMonsters(Arg0)); }
	void test_case_3() { string Arr0[] = {"1", "3 4", "2", "2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, numMonsters(Arg0)); }
	void test_case_4() { string Arr0[] = {"2 2", "3", "4 4 4", "5", "6", "7 7 7 7", "7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; verify_case(4, Arg1, numMonsters(Arg0)); }
	void test_case_5() { string Arr0[] = {"2 2 2 2 2 2 2 2 2 2 2 11 11 11 11 11 11", "3 3 3 3 3 3 3 3 3 3 3 12 12 12 12 12 12 12 12 12", "4 4 4 4 4 4 4 4 4 4 4 13 13 13 13 13 13 13 13", "5 5 5 5 5 5 5 5 5 5 5 14 14 14", "6 6 6 6 6 6 6 6 6 6 6 15 15", "7 7 7 7 7 7 7 7 7 7 7 16 16 16 16 16", "8 8 8 8 8 8 8 8 8 8 8 17 17 17", "9 9 9 9 9 9 9 9 9 9 9 18 18 18 18 18 18 18", "10 10 10 10 10 10 10 10 10 10 10 19 19 19 19", "10", "12", "13", "14", "15", "16", "17", "18", "19", "20", "11 11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(5, Arg1, numMonsters(Arg0)); }

// END CUT HERE

};

const int N = 100;
const int MD = 1000000007;

bool p[N][N];
int a[N][N];
int deg[N];
int MonsterFarm::numMonsters(vector <string> transforms)
{
	int n = transforms.size();
	clr(deg, 0);
	clr(a, 0);
	clr(p, false);
	rep(i, 0, n) {
		int j;
		stringstream ss(transforms[i]);
		while (ss >> j) {
			p[i][j-1] = true;
			a[j-1][i] ++;
			deg[i] ++;
		}
	}
	cout << n << endl;
	rep(k, 0, n)
		rep(i, 0, n)
			rep(j, 0, n)
				if (p[i][k] && p[k][j]) p[i][j] = true;

	rep(i, 0, n)
		if (p[0][i] && deg[i] > 1 && p[i][i]) return -1;

		long long ans[N][N], tmp[N][N];
		clr(ans, 0);
		rep (i, 0, n) ans[i][i] = 1;
		printf("a:\n");
		rep (i, 0, n)
			rep(j , 0, n)
				printf("%d%c", a[i][j], j==n-1? '\n':' ');

		rep (cnt, 0, n + 10) {
			clr(tmp, 0);
			rep (i, 0, n)
					rep (j, 0, n)
						rep (k, 0, n)
							tmp[i][j] = (tmp[i][j] + a[i][k] * ans[k][j]) % MD;

			rep (i, 0, n)
				rep (j, 0, n)
					ans[i][j] = tmp[i][j];
		}
		int ret = 0;
		rep (i, 0, n)
			ret = (ret + ans[i][0]) % MD;
		return ret;
}

// BEGIN CUT HERE
int main()
{
        MonsterFarm ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
