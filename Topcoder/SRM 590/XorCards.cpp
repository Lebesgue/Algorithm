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

class XorCards {
    public:
    long long numberOfWays(vector<long long> number, long long limit) {
        return 0;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<long long> number, long long limit, long long __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    XorCards *instance = new XorCards();
    long long __result = instance->numberOfWays(number, limit);
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
            long long number[] = {
                1LL, 2LL
            };
            long long limit = 2LL;
            long long __expected = 3LL;
            return do_test(to_vector(number), limit, __expected, __no);
        }
        case 1: {
            long long number[] = {
                5LL, 5LL
            };
            long long limit = 3LL;
            long long __expected = 2LL;
            return do_test(to_vector(number), limit, __expected, __no);
        }
        case 2: {
            long long number[] = {
                1LL, 2LL, 3LL, 4LL, 5LL, 6LL, 7LL
            };
            long long limit = 5LL;
            long long __expected = 96LL;
            return do_test(to_vector(number), limit, __expected, __no);
        }
        case 3: {
            long long number[] = {
                123LL, 456LL, 789LL, 147LL, 258LL, 369LL, 159LL, 357LL
            };
            long long limit = 500LL;
            long long __expected = 125LL;
            return do_test(to_vector(number), limit, __expected, __no);
        }
        case 4: {
            long long number[] = {
                0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL
            };
            long long limit = 1000000000000000LL;
            long long __expected = 4294967296LL;
            return do_test(to_vector(number), limit, __expected, __no);
        }
        case 5: {
            long long number[] = {
                1000000000000000LL, 999999999999999LL
            };
            long long limit = 65535LL;
            long long __expected = 2LL;
            return do_test(to_vector(number), limit, __expected, __no);
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
    cout << "XorCards (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1379372557;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
