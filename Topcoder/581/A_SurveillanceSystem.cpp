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


class SurveillanceSystem
{
        public:
        string getContainerInfo(string containers, vector <int> reports, int L);
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "-X--XX"; int Arr1[] = {1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "??++++"; verify_case(0, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "-XXXXX-"; int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "???-???"; verify_case(1, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "------X-XX-"; int Arr1[] = {3, 0, 2, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; string Arg3 = "++++++++++?"; verify_case(2, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "-XXXXX---X--"; int Arr1[] = {2, 1, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "???-??++++??"; verify_case(3, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "-XX--X-XX-X-X--X---XX-X---XXXX-----X"; int Arr1[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; string Arg3 = "???++++?++++++++++++++++++++??????--"; verify_case(4, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

int cnt[100];
int n;

bool chk (int x, int L, string c) {
	int i, j, k;
	int cnt2[111] = {0};
	for (i = 0; i <= n - L; ++i) {
		if (x >= i && x < i + L) continue;
		for (k = 0, j = i; j < i + L; ++j)
			k += (c[j] == 'X');
		cnt2[k]++;
	}
	for (i = 0; i < 100; ++i)
		if (cnt2[i] < cnt[i]) return false;

	return true;
}

string SurveillanceSystem::getContainerInfo(string c, vector <int> a, int L)
{
	int sum[100][100];
	int ans[111];
	int i, j, k;

	n = c.size ();

	memset (cnt, 0, sizeof (cnt));
	for (i = 0; i < a.size(); ++i) cnt[a[i]]++;

	memset (sum, 0, sizeof (sum));
	for (i = 0; i < n; ++i)
		for (j = i; j < n; ++j)
			for (k = i; k <= j; ++k)
				sum[i][j] += (c[k] == 'X');


	memset(ans, -1, sizeof (ans));
	for (i = 0; i < n; ++i)
		if (!chk(i, L, c))
			ans[i] = 1;

	for (i = 0; i < n; ++i)
		if (ans[i] != 1) {
			for (j = max(i - L + 1, 0); j <= i && j + L <= n; ++j) {
				if (cnt[sum[j][j + L - 1]]) {
					ans[i] = 0;
					break;
				}
			}
		}
	string ret;
	for (i = 0; i < n; ++i) {
		if (ans[i] == 1) ret += "+";
		else if (ans[i] == -1) ret += "-";
		else ret += "?";
	}
	return ret;
}

// BEGIN CUT HERE
int main()
{
        SurveillanceSystem ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
