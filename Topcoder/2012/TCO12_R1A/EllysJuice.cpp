/*

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

class EllysJuice
{
        public:
        vector <string> getWinners(vector <string> players);
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = { "elly", "kriss", "elly" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"elly", "stancho" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getWinners(Arg0)); }
	void test_case_1() { string Arr0[] = {"torb", "elly", "stancho", "kriss"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getWinners(Arg0)); }
	void test_case_2() { string Arr0[] = {"elly", "elly", "elly", "elly", "elly"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"elly" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getWinners(Arg0)); }
	void test_case_3() { string Arr0[] = { "ariadne", "elly", "ariadne", "stancho", "stancho", "kriss", "stancho", "elly" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ariadne", "elly", "stancho" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getWinners(Arg0)); }

// END CUT HERE

};

vector <string> EllysJuice::getWinners(vector <string> players)
{
	int n;
	n = sz (players);
	map<string, int> M;
	rep (i, 0, n) M[players[i]] = i;

	sort (players.begin(), players.end());
	vector <string> ans;
	double cnt[10];
	do {
		double to = 1.0, ta = 1.0;
		clr (cnt, 0);
		rep (i, 0, n) {
			if (i & 1) cnt[M[players[i]]] += (ta /= 2);
			else cnt[M[players[i]]] += (to /= 2);
		}
		string name; bool multi = false; double amt = -1;
		rep (i, 0, n) {
			if (cnt[M[players[i]]] > amt + 1e-15) {
				amt = cnt[M[players[i]]];
				name = players[i];
				multi = false;
			}
			else if (players[i] != name && fabs (cnt[M[players[i]]] - amt) < 1e-12) {
				multi = true;
			}
		}
		if (!multi) {ans.pb (name); }//cout << name << endl;}
	}while (next_permutation(players.begin(), players.end()) );
	sort (ans.begin(), ans.end());
	cout << sz (ans) << endl;
	int num = unique(ans.begin(), ans.end()) - ans.begin();
	cout << num << endl;
	vector <string> ret;
	rep (i, 0, num) ret.pb (ans[i]);
	return ret;
}


// BEGIN CUT HERE
int main()
{
        EllysJuice ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE

*/
