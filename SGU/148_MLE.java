import java.io.*;
import java.util.*;
import java.math.*;


public class Solution {
	class P implements Comparable <P>{
		int v, id;
		P () {}
		P (int v, int id) {
			this.v = v;
			this.id = id;
		}
		public int compareTo (P e) {
			return e.v - this.v;
		}
	}
	final static int N = 15011;
	
	void SGU149 () {
		int [] W = new int [N];
		int [] L = new int [N];
		int [] P = new int [N];
		int [] sp = new int [N];
		int m, i;
		@SuppressWarnings("resource")
		Scanner in = new Scanner (new BufferedInputStream (System.in));
		m = in.nextInt ();
		sp[0] = 0;
		for (i = 1; i <= m; ++i) {
			W[i] = in.nextInt(); L[i] = in.nextInt();
			P[i] = in.nextInt();
			sp[i] = sp[i - 1] + W[i];
		}
		int ans = m, best = P[m];
		PriorityQueue<P> pq = new PriorityQueue<P> ();
		int s = 0;
		for (i = m; i >= 1; --i) {
			while (!pq.isEmpty()) {
				P u = pq.peek();
				if (u.v > sp[i-1]) {
					s -= P[u.id];
					pq.poll ();
				}
				else break;
			}
			s += P[i];
			if (s < best) {
				best = s;
				ans = i;
			}
			pq.add(new P(sp[i] - L[i], i));
		}
		for (i = ans; i <= m; ++i)
			if (sp[i] - sp[ans - 1] <= L[i])
				System.out.printf ("%d\n", i);
	}
	public static void main(String[] args) {
		Solution lebesgue = new Solution ();
		lebesgue.SGU149 ();
	}
}
