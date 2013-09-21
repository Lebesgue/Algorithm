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

class StringPath {
    public:
    int countBoards(int n, int m, string A, string B) {
        return 0;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int n, int m, string A, string B, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    StringPath *instance = new StringPath();
    int __result = instance->countBoards(n, m, A, B);
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
            int n = 2;
            int m = 2;
            string A = "ABC";
            string B = "ADC";
            int __expected = 2;
            return do_test(n, m, A, B, __expected, __no);
        }
        case 1: {
            int n = 2;
            int m = 2;
            string A = "ABC";
            string B = "ABD";
            int __expected = 0;
            return do_test(n, m, A, B, __expected, __no);
        }
        case 2: {
            int n = 3;
            int m = 4;
            string A = "ABCDDE";
            string B = "ACCBDE";
            int __expected = 1899302;
            return do_test(n, m, A, B, __expected, __no);
        }
        case 3: {
            int n = 8;
            int m = 8;
            string A = "ZZZZZZZZZZZZZZZ";
            string B = "ZABCDEFGHIJKLMZ";
            int __expected = 120390576;
            return do_test(n, m, A, B, __expected, __no);
        }

        // Your custom testcase goes here
        case 4:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "StringPath (900 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1379383054;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 900 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
