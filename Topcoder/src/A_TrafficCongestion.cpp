#include <string>
#include <vector>
using namespace std;

const long long md = 1000000007;
long long s[1000111], d[1000111];
class TrafficCongestion {
	public:

	int theMinCars(int n) {
        d[0] = d[1] = 1;
        for (i = 0; i <= n; ++i) {
        	if (n & 1) {
        		d[i+1] = (1 + 2 * d[i] % md) % md;
        		d[i+2] = (1 + 4 * d[i] % md) % md;
        	}
        }
        return d[n];
	}
};
