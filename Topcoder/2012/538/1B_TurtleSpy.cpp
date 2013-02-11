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
#define PI acos(-1.0)

class TurtleSpy
{
        public:
        double maxDistance(vector <string> commands);
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"forward 100", "backward 100", "left 90" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 141.4213562373095; verify_case(0, Arg1, maxDistance(Arg0)); }
	void test_case_1() { string Arr0[] = {"left 45", "forward 100", "right 45", "forward 100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 200.0; verify_case(1, Arg1, maxDistance(Arg0)); }
	void test_case_2() { string Arr0[] = {"left 10", "forward 40",  "right 30", "left 10", "backward 4", "forward 4" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 40.58520737741619; verify_case(2, Arg1, maxDistance(Arg0)); }

// END CUT HERE

};



double TurtleSpy::maxDistance(vector <string> commands)
{
	vector <int> ang;
	bool d[500] = {false}, tmp[500];
	int sumP = 0, sumN = 0;
	int cmdN = sz(commands);
	int i, j, k;
	for (i = 0; i < cmdN; i++) {
		stringstream ss (commands[i]);
		string s;
		ss >> s >> j;
		if ( s == "right") ang.pb (j);
		else if (s == "left") ang.pb (360 - j);
		else if (s == "forward") sumP += j;
		else sumN += j;
	}
	d[0] = true;
	for (i = 0; i < sz (ang); ++ i) {
//		cout << "ang: " << ang[i] << endl;
		clr (tmp, false);
		for (j = 0; j < 360; j++) if (d[j])
			tmp[(j + ang[i]) % 360] = true;
		for (j = 0; j < 360; ++j) d[j] = d[j] | tmp[j];
	}
//	for (i = 0; i < 360; i++) if (d[i]) cout << i << endl;
	double x, y; int dl;
	for (dl = 0; dl <= 180; dl ++) {
		if (d[180 + dl]) {
			double theta = 180 + dl;
			x = cos (theta / 180 * PI), y = sin (theta / 180 * PI);
			break;
		}
		else if (d[180 - dl]) {
			double theta = 180 - dl;
			x = cos (theta / 180 * PI), y = sin (theta / 180 * PI);
			break;
		}
	}
//	cout << dl << ' ' << x << ' ' << y << endl;
	x = (-sumN) * x, y = (-sumN) * y;
	x = sumP + x;
	return sqrt (x * x + y * y);
}

// BEGIN CUT HERE
int main()
{
        TurtleSpy ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
