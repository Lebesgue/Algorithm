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



#define clr(x) memset(x, 0, sizeof(x))


class FruitTrees
{
        public:
        int maxDist(int apple, int kiwi, int grape);
        int maxDist2(int apple, int kiwi, int grape);
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 8; int Arg3 = 0; verify_case(0, Arg3, maxDist(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 6; int Arg3 = 1; verify_case(1, Arg3, maxDist(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 40; int Arg1 = 30; int Arg2 = 20; int Arg3 = 5; verify_case(2, Arg3, maxDist(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 899; int Arg1 = 1073; int Arg2 = 1147; int Arg3 = 14; verify_case(3, Arg3, maxDist(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 2000; int Arg1 = 2000; int Arg2 = 2000; int Arg3 = 666; verify_case(4, Arg3, maxDist(Arg0, Arg1, Arg2)); }

// END CUT HERE

};


int T[3][3][2011];

void go (int be, int en, int x, int y)
{
	bool f[2011];
	for (int i = 0; i <= 2000; ++i) {
		int cur = i % x, ans = 200000;
		memset (f, false, sizeof (f));
		while (!f[cur]) {
			ans = min (ans, min (cur, x - cur));
			f[cur] = true;
			cur = (cur + y) % x;
		}
		T[be][en][i] = ans;
	}
}
int FruitTrees::maxDist(int a, int b, int c)
{
	memset (T, 0, sizeof(T));
	go (0, 1, a, b);
	go (0, 2, a, c);
	go (1, 2, b, c);

	int i, j, ans = 0;
	for (i = 0; i <= 2000; ++i) {
		for (j = i; j <= 2000; ++j) {
			int tmp = min (T[0][1][i], min (T[0][2][j], T[1][2][j - i]));
			ans = max (tmp, ans);

			tmp = min (T[0][2][i], min (T[0][1][j], T[1][2][j - i]));
			ans = max (tmp, ans);
		}
	}
	return ans;
}

// BEGIN CUT HERE
int main()
{
        FruitTrees ___test;
        cout << ___test.maxDist(747, 1494, 1494);
        return 0;
}
// END CUT HERE
