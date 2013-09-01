#include <iostream>
#include <cstdio>
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

using namespace std;



#define clr(x) memset(x, 0, sizeof(x))

const long long md = 1000000007;
long long s[1000111], d[1000111];
int n;

class TrafficCongestion
{
        public:
        int theMinCars(int treeHeight);
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; verify_case(0, Arg1, theMinCars(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; verify_case(1, Arg1, theMinCars(Arg0)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 5; verify_case(2, Arg1, theMinCars(Arg0)); }
	void test_case_3() { int Arg0 = 585858; int Arg1 = 548973404; verify_case(3, Arg1, theMinCars(Arg0)); }

// END CUT HERE

};

int TrafficCongestion::theMinCars(int n)
{
	d[0] = d[1] = 1;
	for (int i = 0; i <= n; ++i) {
		if (i & 1) {
			d[i+1] = (1 + 2 * d[i] % md) % md;
			d[i+2] = (1 + 4 * d[i] % md) % md;
		}
		//printf ("%d %Ld\n", i, d[i]);
	}
	return (int) d[n];
}

// BEGIN CUT HERE
int main()
{
        TrafficCongestion ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
