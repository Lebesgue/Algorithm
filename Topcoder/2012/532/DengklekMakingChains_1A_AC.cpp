#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <list>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>

#include <cmath>
#include <ctime>

using namespace std;



#define clr(x) memset(x, 0, sizeof(x))


class DengklekMakingChains
{
        public:
        int maxBeauty(vector <string> chains);
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".15", "7..", "402", "..3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(0, Arg1, maxBeauty(Arg0)); }
	void test_case_1() { string Arr0[] = {"..1", "7..", "567", "24.", "8..", "234"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36; verify_case(1, Arg1, maxBeauty(Arg0)); }
	void test_case_2() { string Arr0[] = {"...", "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, maxBeauty(Arg0)); }
	void test_case_3() { string Arr0[] = {"16.", "9.8", ".24", "52.", "3.1", "532", "4.4", "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 28; verify_case(3, Arg1, maxBeauty(Arg0)); }
	void test_case_4() { string Arr0[] = {"..1", "3..", "2..", ".7."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, maxBeauty(Arg0)); }
	void test_case_5() { string Arr0[] = {"412", "..7", ".58", "7.8", "32.", "6..", "351", "3.9", "985", "...", ".46"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; verify_case(5, Arg1, maxBeauty(Arg0)); }

// END CUT HERE

};

int DengklekMakingChains::maxBeauty(vector <string> chains)
{
	int i, j, k;
	int lft[100], rt[100], mid[100];
 string s;

	int n = chains.size();
	for(i = 0; i < n; i++)
	{
		s = chains[i];
		lft[i] = 0;
		for(j = 0; j < 3; j++){
			if(s[j] == '.') break;
			lft[i] += s[j] - '0';
		}
		rt[i] = 0;
		for(j = 2; j >= 0; j--){
			if(s[j] == '.') break;
			rt[i] += s[j] - '0';
		}
		mid[i] = 0;
		for(j = 0; j < 3; j++){
			if(s[j] == '.') break;
			mid[i] += s[j] - '0';
		}
		if(j != 3) mid[i] = 0;
	}
	int ans = 0;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++){
			if(i != j){
				int t = lft[i] + rt[j];
				for(k = 0; k < n; k++)
					if(i != k && j != k)
						t += mid[k];
				ans = max(ans, t);
			}
		}

	int t;
	for(i = 0; i < n; i++)
	{
		s = chains[i];
		for(j = 0; j < 3; j++)
		{
			t = 0;
			for(k = j; k < 3; k++)
			{
				if(s[k] == '.') break;
				t = t + s[k] - '0';
			}
			ans = max(ans, t);
		}
	}
	return ans;
}

// BEGIN CUT HERE
int main()
{
        DengklekMakingChains ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
