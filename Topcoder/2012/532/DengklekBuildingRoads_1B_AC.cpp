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

using namespace std;



#define clr(x) memset(x, 0, sizeof(x))


class DengklekBuildingRoads
{
        public:
        int numWays(int N, int M, int K);
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 1; int Arg3 = 3; verify_case(0, Arg3, numWays(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 3; int Arg3 = 4; verify_case(1, Arg3, numWays(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 1; int Arg3 = 0; verify_case(2, Arg3, numWays(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 0; int Arg2 = 3; int Arg3 = 1; verify_case(3, Arg3, numWays(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 20; int Arg2 = 5; int Arg3 = 26964424; verify_case(4, Arg3, numWays(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

long long d[31][31][10][512];

const int MD = 1000000007;

inline void add(long long &x, long long y)
{
	x = x + y;
	if(x >= MD) x -= MD;
}

int DengklekBuildingRoads::numWays(int N, int M, int K)
{
	int i, j, k;

	memset(d, 0, sizeof(d));
	d[0][0][0][0] = 1;
	for(i = 0; i < N; i++)
		for(j = 0; j <= M; j++){
			for(k = 0; k < K; k++){
				if(i + k + 1 >= N) break;
				for(int mask = 0; mask < 1<<(K+1); mask++)
					for(int kk = 0; j + kk <= M; kk ++){
						int st = mask^(kk%2)^((kk%2)<<(k+1));
						add(d[i][j+kk][k+1][st], d[i][j][k][mask]);
					}
			}
			for(int mask = 0; mask < 1<<(K+1); mask++) if(!(mask&1))
				add(d[i+1][j][0][mask>>1], d[i][j][k][mask]);
		}
	return (int) d[N][M][0][0];
}

// BEGIN CUT HERE
int main()
{
        DengklekBuildingRoads ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
