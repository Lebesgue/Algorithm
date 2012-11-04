#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

class DAWG {

private:
    struct state {
        int to[11];
        int sp;
        int ma, mi;
        int sum, deg;
        int way;
        bool fg;
        state () {}
        state (int _ma) {
            ma = _ma; sum = 0; deg = 0; fg = false; way = 0;
            memset (to, 0, sizeof (to));
        }

    }*au;

    int maxStateNumber, mempt;
    string s;
    int *pt;
    int n;

    inline bool isPr (int u, int a) {
        int k = au[u].to[a];
        return au[u].ma + 1 == au[k].ma;
    }

    inline bool hasTrans (int u, int a) {
        return au[u].to[a] != 0;
    }

    int split (int pa, int cd, int a) {
        int i, j, k, id;

        au[id = (mempt++)] = state (au[pa].ma + 1);
        au[pa].to[a] = id;
        for (i = 0; i < 11; ++i)
            au[id].to[i] = au[cd].to[i];

        au[id].sp  = k = au[cd].sp; au[id].mi = au[k].ma + 1;
        au[cd].sp = id; au[cd].mi = au[id].ma + 1;

        for (int u = pa; u != 0; ) {
            u = au[u].sp;
            if (au[u].to[a] == cd && !isPr (u, a))
                au[u].to[a] = id;
            else break;
        }
        return id;
    }

    int update (int u, int a) {
        int i, j, k, id;
        au[id = (mempt++)] = state (au[u].ma + 1);
        au[u].to[a] = id;

        for (k = -1; u != 0 && k == -1;) {
            u = au[u].sp;
            j = au[u].to[a];

            if (!j)
                au[u].to[a] = id;
            else if (isPr (u, a)) {
                k = j;
            }
            else
                k = split (u, j, a);
        }
        if (k == -1) k = 0;
        au[id].sp = k;
        au[id].mi = au[k].ma + 1;
        return id;
    }

    void init () {
        n = s.size ();
        maxStateNumber = 2 * n + 11;
        mempt = 0;

        au = new state [maxStateNumber];
        pt = new int [maxStateNumber];

        au[mempt++] = state (0);
        au[0].mi = 0;
    }

public:
    int trans (char x) {
        return (x<='9') ? x - '0' : 10;
    }

    long long numberOfString () {
        long long ans = 0;
        for (int i = 1; i < mempt; ++i)
            ans += au[i].ma - au[i].mi + 1;
        return ans;
    }

    DAWG (const string &t) {
        s = t;
        init ();

        int cur = 0;
        for (int i = 0; i < n; ++i) {
            pt[i] = update (cur, trans (s[i]));
            cur = pt[i];
        }
    }

    int solve () {
        int i, j, k;
        if (au[0].to[0]) au[au[0].to[0]].fg = true;
        for (i = 0; i < mempt; ++i) {
            j = au[i].to[10];
            if (j) au[j].fg = true;
        }

        for (i = 0; i < mempt; ++i) if (!au[i].fg)
            for (j = 0; j < 10; ++j) {
                k = au[i].to[j];
                if (!k || i == 0 && j == 0) continue;
                au[k].deg ++;
            }
        queue<int>q;
        for (i = 0; i < mempt; ++i)
            if (!au[i].fg && au[i].deg == 0)
                q.push (i);
        au[0].way = 1;

        int ans = 0;
        while (!q.empty()) {
            int u = q.front (); q.pop ();
            //printf ("head %d\n", u);
            for (i = 0; i < 10; ++i) {
                j = au[u].to[i];
                if (!j || u == 0 && i == 0) continue;
                au[j].sum = (au[j].sum + (au[u].sum * 10) % 2012 + au[u].way * i % 2012) % 2012;
                au[j].way = (au[j].way + au[u].way) % 2012;
                //printf ("\t%d->%d by %d: %d %d %d\n", u, j, i, au[u].sum, au[u].ma - au[u].mi + 1, au[j].sum);
                if ((--au[j].deg) == 0)
                    q.push (j);
            }
        }
        for (i = 0; i < mempt; ++i)
            ans = (ans + au[i].sum) % 2012;
        return ans;
    }
};


int main () {
    int i, j, k, n;
    while (cin >> n) {
        string s, tot;
        for (i = 0; i < n; ++i) {
            cin >> s;
            tot += s + "A";
        }
    //    cout << tot << endl;
        DAWG G(tot);
        cout << G.solve () << endl;
    }
    return 0;
}
