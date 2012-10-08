#include <cstdio>
#include <algorithm>
using namespace std;
 
const int N = 1500;
int a[N][N], dmx[N][N], dmi[N][N], mx[N][N], mi[N][N];
int q[N], hd, tl;
int m, n, s;
 
int main () {
    int i, j, k;
    scanf ("%d%d%d", &m, &n, &s);
    if (s == 0) while (1);
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            scanf ("%d", &a[i][j]);
    for (i = 1; i <= m; i++) {
        mx[i][q[hd = tl = 1] = 1] = a[i][1];
        for (j = 2; j <= n; j++) {
            while (tl >= hd && a[i][j] >= a[i][q[tl]]) tl--;
            q[++tl] = j;
            while (hd <= tl && j - q[hd] >= s) hd ++;
            mx[i][j] = a[i][q[hd]];
        }
        mi[i][q[hd = tl = 1] = 1] = a[i][1];
        for (j = 2; j <= n; j++) {
            while (tl >= hd && a[i][j] <= a[i][q[tl]]) tl--;
            q[++tl] = j;
            while (hd <= tl && j - q[hd] >= s) hd ++;
            mi[i][j] = a[i][q[hd]];
        }
    }
    for (j = s; j <= n; j++) {
        dmx[q[hd = tl = 1] = 1][j] = a[1][j];
        for (i = 2; i <= m; i++) {
            while (tl >= hd && mx[i][j] >= mx[q[tl]][j]) tl --;
            q[++tl] = i;
            while (hd <= tl && i - q[hd] >= s) hd++;
            dmx[i][j] = mx[q[hd]][j];
        }
        dmi[q[hd = tl = 1] = 1][j] = a[1][j];
        for (i = 2; i <= m; i++) {
            while (tl >= hd && mi[i][j] <= mi[q[tl]][j]) tl--;
            q[++tl] = i;
            while (hd <= tl && i - q[hd] >= s) hd++;
            dmi[i][j] = mi[q[hd]][j];
        }
    }
/*  printf ("\n mx\n");
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            printf ("%d%c", mx[i][j], j == n ? '\n' : ' ');
    printf ("\n mi\n");
    for (i = 1; i <= m; i++)
            for (j = 1; j <= n; j++)
                printf ("%d%c", mi[i][j], j == n ? '\n' : ' ');
    printf ("\n dmx\n");
    for (i = 1; i <= m; i++)
            for (j = 1; j <= n; j++)
                printf ("%d%c", dmx[i][j], j == n ? '\n' : ' ');
    printf ("\n dmi\n");
    for (i = 1; i <= m; i++)
            for (j = 1; j <= n; j++)
                printf ("%d%c", dmi[i][j], j == n ? '\n' : ' ');*/
    int ans = 1000000010;
    for (i = s; i <= m; i++)
        for (j = s; j <= n; j++)
            ans = min (ans, dmx[i][j] - dmi[i][j]);
    printf ("%d\n", ans);
    return 0;
}
