#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
const int N = 5010;
const int MD = 100000000;
int l[2][N];
long long d[2][N];
void add (long long &x, long long y) { x += y; if (x >= MD) x -= MD;}
char s[N], t[N];
int main ()
{
    int i, j, k;
    scanf ("%s\n%s", s, t);
    int ns = strlen (s) - 1, nt = strlen (t) - 1;
    memset (l, 0, sizeof (l)); memset (d, 0, sizeof (d));
    d[0][0] = d[1][0] = 1; int last = 0, cur = 1;
    for (j = 0; j <= nt; j++) d[0][j] = 1;
    for (i = 1; i <= ns; i++) {
        for (j = 1; j <= nt; j++) {
            d[cur][j] = 0; l[cur][j] = max (l[last][j], l[cur][j-1]);
            if (s[i-1] == t[j-1]) {
                l[cur][j] = max (l[cur][j], 1 + l[last][j-1]);
                add (d[cur][j], d[last][j-1]);
                if (l[cur][j] == l[last][j]) add (d[cur][j], d[last][j]);
                if (l[cur][j] == l[cur][j-1]) add (d[cur][j], d[cur][j-1]);
            }
            else {
                if (l[cur][j] == l[last][j]) add (d[cur][j], d[last][j]);
                if (l[cur][j] == l[cur][j-1]) add (d[cur][j], d[cur][j-1]);
                if (l[cur][j] == l[last][j-1]) d[cur][j] = (d[cur][j] + MD - d[last][j-1]) % MD;
            }
        }
        cur ^= 1, last ^= 1;
    }
    printf ("%d\n%Ld\n", l[last][nt], d[last][nt]);
    return 0;
}
