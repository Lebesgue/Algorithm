#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 131;

int a[N][N], dis[N], n, d;
bool has[N];

bool chk () {
    int i, j, k;
    fill (dis + 1, dis + n + 1, 500000);
    dis[1] = 0;
    bool change = true;
    for (int cnt = 1; cnt <= n + 10 && change; cnt++) {
        change = false;
        for (i = 1; i <= n; ++i) if (2 * dis[i] < d)
                for (j = 1; j <= n; ++j)
                    if (dis[i] + a[i][j] < dis[j]) {
                        change = true;
                        dis[j] = dis[i] + a[i][j];
                        if (has[j] && dis[j] <= d)
                            dis[j] = 0;
                    }
    }
    for (i = 1; i <= n; ++i)
        if (2 * dis[i] > d) return false;
    return true;
}

int main () {
    int i, j, k;
    int x[N], y[N];
    //freopen ("in", "r", stdin);
    
    while (cin >> n >> d) {
        memset (a, 0, sizeof (a));
        for (i = 1; i <= n; ++i) 
            cin >> x[i] >> y[i];
        for (i = 1; i <= n; ++i)
            for (j = i + 1; j <= n; ++j)
                a[i][j] = a[j][i] = ceil (hypot (x[i] - x[j], y[i] - y[j]));

        for (i = 1; i <= n; ++i) has[i] = true;

        if (!chk ()) cout << "-1\n";
        else {
            for (i = n; i > 1; --i) {
                has[i] = false;
                if (chk()) continue;
                has[i] = true;
            }
            i = n;
            while (i >= 1 && !has[i]) --i;
            for (; i >= 1; --i)
                cout << (has[i] ? 1 : 0);
            cout << endl;
        }
    }
    return 0;
}
