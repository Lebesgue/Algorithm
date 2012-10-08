import java.util.*;
import java.io.*;

public class 1070 {
	
	public static class MinCostFlow {
		final static int M = 100000;
		final static int N = 800;
		final static int inf = 0x3f3f3f3f;
		
		int [] eb = new int [N];
		int en;
		int [] to = new int [M];
		int [] nxt = new int [M];
		int [] f = new int [M];
		int [] cst = new int [M];
		
		int [] pre = new int [N];
		int [] dis = new int [N];
		int [] inc = new int [N];
		
		boolean [] st = new boolean [N];
		int [] q = new int [M];
		int hd, tl;
		
		void adde (int x, int y, int cap, int c) {
			to[en] = y; nxt[en] = eb[x]; cst[en] = c; f[en] = cap; eb[x] = en++;
			to[en] = x; nxt[en] = eb[y]; cst[en] = -c; f[en] = 0; eb[y] = en++;
		}
		boolean BB (int ss, int tt) {
			Arrays.fill (st, false);
			Arrays.fill (dis, inf);
			Arrays.fill (inc, inf);
			st[q[hd = tl = 1] = ss] = true;
			dis[ss] = 0;
			while (hd <= tl) {
				int u = q[hd++];
				for (int ee = eb[u]; ee != -1; ee = nxt[ee]) {
					int j = to[ee];
					if (f[ee] > 0 && dis[u] + cst[ee] < dis[j]) {
						dis[j] = dis[u] + cst[ee];
						inc[j] = Math.min (inc[u], f[ee]);
						pre[j] = ee;
						if (!st[j]) {q[++tl] = j; st[j] = true;}
					}
				}
				st[u] = false;
			}
			return inc[tt] < inf;
		}
		int run (int ss, int tt) {
			int ans = 0;
			while (BB (ss, tt)) {
				int i = tt;
				ans += inc[tt] * dis[tt];
				while (i != ss) {
					f[pre[i]] -= inc[tt];
					f[pre[i]^1] += inc[tt];
					i = to[pre[i]^1];
				}
			}
			return ans;
		}
		public MinCostFlow () {
			Arrays.fill(eb, -1);
			en = 0;
		}
	}
	public static void main(String[] args) {
		Scanner in = new Scanner (new InputStreamReader (System.in));
		int n, m;
		m = in.nextInt(); 
		n = in.nextInt();
		MinCostFlow G  = new MinCostFlow ();
		int ss = 0; int tt = (m + 1) * n + 1;
		for (int i = 1; i <= n; i++) {
			G.adde (ss, i, 1, 0);
			for (int j = 1; j <= m; j++) {
				int t = in.nextInt();
				for (int k = 1; k <= n; k++)  
					G.adde (i, n + (j - 1) * n + k, 1, k * t);
			}
		}
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) 
				G.adde ( n + (i - 1) * n + j, tt, 1, 0);
		System.out.printf ("%.2f\n", (double)G.run(ss, tt) / n); 
	}

}
