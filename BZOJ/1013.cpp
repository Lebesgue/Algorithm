#include <cstdio>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
const int N = 20;
 
int n;
double a[N][N], b[N], sol[N];
double pt[N];
int id[N];
 
int main ()
{
    int i, j, k;
    double x;
    scanf ("%d", &n);
 
    double nm0 = .0;
    for (i = 1; i <= n; i++) {
        id[i] = i;
        scanf ("%lf", &pt[i]);
        nm0 += pow (pt[i], 2);
    }
    for (i = 1; i <= n; i++) {
        double nm = .0;
        for (j = 1; j <= n; j++) {
            scanf ("%lf", &x);
            a[i][j] = 2 * (pt[j] - x);
            nm += pow (x, 2);
        }
        b[i] = nm0 - nm;
    }
    for (i = 1; i < n; i++) {
        double V = 0;
        int pvt;
        for( j = i; j <= n; j++) {
            if (fabs (a[j][i]) > V) {
                V = fabs (a[j][i]);
                pvt = j;
            }
        }
        if (pvt != i) { for (j = 1; j <= n; j++) swap (a[i][j], a[pvt][j]); swap(b[i], b[pvt]); swap (id[i], id[pvt]);}
        if (V == 0) continue;
        for (j = i + 1; j <= n; j++) {
            double mul = - a[j][i] / a[i][i];
            for (k = i; k <= n; k++)
                a[j][k] += a[i][k] * mul;
            b[j] += b[i] * mul;
        }
    }
    sol[n] = b[n] / a[n][n];
    for (i = n - 1; i >= 1; i--) {
        double sum = .0;
        for (j = n; j > i; j --)
            sum += a[i][j] * sol[j];
        sol[i] = (b[i] - sum ) / a[i][i];
    }
    for (i = 1; i <= n; i++) {
        //if (fabs (sol[i]) < 1e-4) sol[i] = .0;
        printf ("%.3lf%c", sol[i], i==n? '\n' : ' ');
    }
    return 0;
}
