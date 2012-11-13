import java.io.*;
import java.util.*;
import java.math.*;


public class Solution {
	
	final static int N = 530;
	static boolean a[] = new boolean [10];
	static boolean ret [] = new boolean [N];
	static int pos [] = new int [N];
	void SGU153 () {
		
	}
	public static void main(String[] args) {
		int i, j, k, n, m, T, ma;
		Scanner in = new Scanner (System.in);
		T = in.nextInt ();
		for (int ca = 1; ca <= T; ++ca) {
			n = in.nextInt (); m = in.nextInt ();
			Arrays.fill (a, false);
			Arrays.fill (pos, 0);
			ma = 1;
			a[1] = true;
			for (i = 1; i <= m; ++i) {
				j = in.nextInt();
				a[j] = true;
				ma = Math.max (ma, j);
			}
			ret[0] = true;
			int cur = 0;
			for (i = 1; i <= ma; ++i) {
				boolean flag = true;
				for (j = 1; j <= 9; ++j)
					if (a[j] && i >= j) 
						flag = flag & ret[i - j];
				ret[i] = !flag;
				cur = cur * 2 + (ret[i] ? 1 : 0);
			}
			for (; ; i ++) {
				boolean flag = true;
				for (j = 1; j <= 9; ++j)
					if (a[j] && i >= j) 
						flag = flag & ret[i - j];
				ret[i] = !flag;
				cur = (cur * 2 + (ret[i] ? 1 : 0)) % (1<<ma);
				if (pos[cur] != 0) break;
				else pos[cur] = i;	
			}
			
		
			int last = pos[cur];
			boolean ans;
			if (n > last) ans = ret[(n - last) % (i - last) + last];
			else ans = ret[n];
			System.out.printf ("%s\n", ans ? "FIRST PLAYER MUST WIN": "SECOND PLAYER MUST WIN");
		}
	}
}
