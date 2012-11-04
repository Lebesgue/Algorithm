#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;


struct acnode {
    int to[26];
    int f, cnt;
    acnode () {
        memset (to, -1, sizeof (to));
        f = cnt = 0;
    }
}au[250011];

int mempt;
int sm[500011];
bool st[500011];


void getFailPt () {
    queue<int>q;
    int i, j, k, t;

    for (int i = 0; i < 26; ++i) {
        if (au[0].to[i]) {
            j = au[0].to[i];
            q.push (j);
            au[j].f = 0;
        }
    }
        
    while (!q.empty()) {
        int hd = q.front ();
        q.pop ();
        for (i = 0; i < 26; ++i) {
            if (au[hd].to[i] != -1) {
                int k = au[hd].to[i], cur = hd;
                q.push (k);
                for (cur = au[cur].f; cur && au[cur].to[i] == -1; cur = au[cur].f);
                au[k].f = (j = au[cur].to[i]);
            }
        }
    }
}

void insert (char *t) {
    int i, j, k, id, tn = strlen (t), cur = 0;
    for (i = 0; i < tn; ++i) {
        int lab = t[i] - 'a';
        if (au[cur].to[lab] != -1) cur = au[cur].to[lab];
        else {
            au[id = (mempt ++)] = acnode ();
            au[cur].to[lab] = id; cur = id;
        }
    }
    sm[cur]++;
}

void init (){
    mempt = 0;
    memset (sm, 0, sizeof (sm));
    memset (st, false, sizeof (st));    
    au[mempt++] = acnode ();
}

int getMatchNO (char *s) {
    int sn = strlen (s), ans = 0;;
    int cur = 0, j, k;
    for (int i = 0; i < sn; ++i) {
        int lab = s[i] - 'a';
        if ((j = au[cur].to[lab]) != -1) 
            cur = j;
        else {
            for (cur = au[cur].f; cur && au[cur].to[lab] == -1; cur = au[cur].f);
            cur = au[cur].to[lab];
        }
        for (int up = cur; up; up = au[up].f)
            st[up] = true;
    }
    for (int i = 1; i < mempt; ++i)
        if (st[i])
            ans += sm[i];
    return ans;
}



char s[1000011];
int main () {
    int i, j, k, T, sn;
    
    for (scanf ("%d", &T); T; --T) {
        scanf ("%d", &k); getchar ();
        init ();
        for (; k; --k) {
            scanf ("%s", s);
            insert (s);
        }
        for (int i = 0; i < 26; ++i)
            if (au[0].to[i] == -1) au[0].to[i] = 0;
        getFailPt ();

        scanf ("%s", s);
        printf ("%d\n", getMatchNO (s));
    }
    return 0;
}


	
