#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <list>
#include <cstring>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>

#include <cmath>
#include <ctime>

using namespace std;



#define clr(x) memset(x, 0, sizeof(x))


class EllysCheckers
{
        public:
        string getWinner(string board);
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = ".o..."; string Arg1 = "YES"; verify_case(0, Arg1, getWinner(Arg0)); }
	void test_case_1() { string Arg0 = "..o..o"; string Arg1 = "YES"; verify_case(1, Arg1, getWinner(Arg0)); }
	void test_case_2() { string Arg0 = ".o...ooo..oo.."; string Arg1 = "NO"; verify_case(2, Arg1, getWinner(Arg0)); }
	void test_case_3() { string Arg0 = "......o.ooo.o......"; string Arg1 = "YES"; verify_case(3, Arg1, getWinner(Arg0)); }
	void test_case_4() { string Arg0 = ".o..o...o....o.....o"; string Arg1 = "NO"; verify_case(4, Arg1, getWinner(Arg0)); }

// END CUT HERE

};

bool d[1060900];
int a[30];

string EllysCheckers::getWinner(string board)
{
	int i, j, k, n = board.size();

	memset(d, false, sizeof(d));

	//cout << (1<<n) << endl;
	for(i = 1; i < (1<<n); i++)
	{
		if(i&1) d[i] = d[i-1];
		else{
			j = i;
			for(k = 0; k < n; k++){
				a[k] = j % 2;
				j/=2;
			}
			j = i;
			bool ans = true;
			for(k = 0; k < n; k++){
				if(!a[k]) continue;
				if(k > 0 && !a[k-1]){
					int jj = j - (1<<k) + (1<<(k-1));
					ans = ans & d[jj];
				}
				if(k > 2 && a[k-1] && a[k-2] && !a[k-3]){
					int jj = j - (1<<k) + (1<<(k-3));
					ans = ans & d[jj];
				}
			}
			d[i] = !ans;
		}
	}
	j = 0;
	for(i = 0; i < n; i++)
		j = j * 2 + (board[i] == 'o'? 1: 0);
	return (d[j]? "YES" : "NO");
}

// BEGIN CUT HERE
int main()
{
        EllysCheckers ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
