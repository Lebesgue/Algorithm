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


class DengklekPaintingSquares
{
        public:
        int numSolutions(int N, int M);

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, numSolutions(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 8; verify_case(1, Arg2, numSolutions(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 5; verify_case(2, Arg2, numSolutions(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 47; int Arg1 = 7; int Arg2 = 944149920; verify_case(3, Arg2, numSolutions(Arg0, Arg1)); }

// END CUT HERE

};

const int MD = 1000000007;
int d[110][9][7000];
int mo[7000][9];

inline int dv(int k, int j)
{
	return mo[k][j];
}

inline void add(int &x, int y)
{
	x += y;
	if(x >= MD) x-=MD;
}

int DengklekPaintingSquares::numSolutions(int N, int M)
{
	int i, j, k;
	int n, m;
	int P3[9] = {1,3,9,27,81,243,729,2187,6561};
	n = N; m = M;

	clr(d);

	for(i= 0; i <= P3[8]; i++){
		k = i;
		for(j = 0; j < 9; j++){
			mo[i][j] = k % 3;
			k/=3;
		}
	}


	d[1][0][0] = 1;
	for(i = 1; i <= n; i++){
		for(j = 0; j < m; j++)
			for(k = 0; k < P3[m]; k++)
			{
				if(dv(k, j) != 1)
					add(d[i][j+1][k - dv(k, j) * P3[j]], d[i][j][k]);

				if(dv(k, j) != 2)
				{
					int kk = k, tog = 0;
					if(dv(k, j) == 1){
						tog++;
						kk -= dv(k, j) * P3[j];
					}
					if(j > 0 && dv(k, j-1) != 0){
						tog++;
						kk = kk + (3-2*dv(k, j-1)) * P3[j-1];
					}

					if(tog&1) kk += P3[j];
					else kk += 2*P3[j];
					add(d[i][j+1][kk], d[i][j][k]);
				}
			}
		for(k = 0; k < P3[m]; k++)
			d[i+1][0][k] = d[i][m][k];
	}

	int ans = 0;
	for(k = 0; k < P3[m]; k++)
	{
		for(j = 0; j < m; j++)
			if(dv(k, j) == 1) break;
		if(j < m) continue;
		else add(ans, d[n+1][0][k]);
	}
	return ans;
}


// BEGIN CUT HERE
int main()
{
        DengklekPaintingSquares ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE

