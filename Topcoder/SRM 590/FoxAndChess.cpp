#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>

using namespace std;

class FoxAndChess {
public:
	string ableToMove(string a, string b) {
		int i, j, k, n = a.size ();
		vector<pair<int, int> >la, lb, ra, rb;
		int lina = 0, linb = 0, rina = 0, rinb = 0;

		for (i = 0; i < n; ++i) {
			if (a[i] == 'L') la.push_back(make_pair (rina, i));
			else if (a[i] == 'R') rina ++;

			if (b[i] == 'L') lb.push_back(make_pair (rinb, i));
			else if (b[i] == 'R') rinb ++;
		}

		for (j = n - 1; j >= 0; --j) {
			if (a[j] == 'R') ra.push_back(make_pair (lina, j));
			else if (a[j] == 'L') lina ++;

			if (b[j] == 'R') rb.push_back(make_pair (linb, j));
			else if (b[j] == 'L') linb ++;
		}


		if (la.size() != lb.size() || ra.size() != rb.size()) return "Impossible";

		k = la.size();
		for (i = 0; i < k; ++i)
			if (la[i].first != lb[i].first || lb[i].second > la[i].second) return "Impossible";

		k = ra.size();
		for (i = 0; i < k; ++i)
			if (ra[i].first != rb[i].first || rb[i].second < ra[i].second) return "Impossible";

		for (i = 0; i < n && a[i] != 'R' && b[i] != 'R'; ++i);
		if (i < n && b[i] == 'R' && a[i] != 'R') return "Impossible";

		for (i = n - 1; i >= 0 && a[i] != 'L' && b[i] != 'L'; --i);
		if (i >= 0 && b[i] == 'L' && a[i] != 'L') return "Impossible";

		return "Possible";
	}
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(string begin, string target, string __expected, int caseNo) {
	cout << "  Testcase #" << caseNo << " ... ";

	time_t startClock = clock();
	FoxAndChess *instance = new FoxAndChess();
	string __result = instance->ableToMove(begin, target);
	double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
	delete instance;

	if (__result == __expected) {
		cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
		return true;
	}
	else {
		cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
		cout << "           Expected: " << pretty_print(__expected) << endl;
		cout << "           Received: " << pretty_print(__result) << endl;
		return false;
	}
}

bool run_testcase(int __no) {
	switch (__no) {
	case 0: {
		string begin = "R...";
		string target = "..R.";
		string __expected = "Possible";
		return do_test(begin, target, __expected, __no);
	}
	case 1: {
		string begin = "..R.";
		string target = "R...";
		string __expected = "Impossible";
		return do_test(begin, target, __expected, __no);
	}
	case 2: {
		string begin = ".L.R.R.";
		string target = "L...R.R";
		string __expected = "Possible";
		return do_test(begin, target, __expected, __no);
	}
	case 3: {
		string begin = ".L.R.";
		string target = ".R.L.";
		string __expected = "Impossible";
		return do_test(begin, target, __expected, __no);
	}
	case 4: {
		string begin = "LRLLRLRLLRLLRLRLRL";
		string target = "LRLLRLRLLRLLRLRLRL";
		string __expected = "Possible";
		return do_test(begin, target, __expected, __no);
	}
	case 5: {
		string begin = "L";
		string target = ".";
		string __expected = "Impossible";
		return do_test(begin, target, __expected, __no);
	}

	// Your custom testcase goes here
	case 6:
		break;
	default: break;
	}
	return 0;
}

int main(int argc, char *argv[]) {
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(2);
	cout << "FoxAndChess (250 Points)" << endl << endl;

	int nPassed = 0, nAll = 0;
	if (argc == 1)
		for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
	else
		for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
	cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

	int T = time(NULL) - 1379369063;
	double PT = T / 60.0, TT = 75.0;
	cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
	cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
	return 0;
}
// CUT end

