import java.io.*;
import java.util.*;

public class CF_163A {
	final static int N = 5010;
	final static long md = 1000000007;
	static long [][] d = new long [2][N];
	static String s, t;
	static int sn, tn;
	
	public static void main(String[] args) {
		Scanner in = new Scanner (new InputStreamReader (System.in) );
		int cur = 1, last = 0;
		s = in.next (); sn = s.length();
		t = in.next (); tn = t.length();
		long ans = 0;
		for (int i = 1; i <= sn; i++) {
			Arrays.fill (d[cur], 0);
			for (int j = 1; j <= tn; j++)
				d[cur][j] = (d[cur][j] + d[cur][j-1] + (s.charAt(i-1) == t.charAt(j-1)? d[last][j-1] + 1 : 0)) % md;
			ans = (ans + d[cur][tn]) % md;
			cur ^= 1; last ^= 1;
		}
		System.out.println (ans);
	}

}
