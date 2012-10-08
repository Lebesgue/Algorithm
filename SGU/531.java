import java.util.*;
import java.io.*;

class A implements Comparable<A>{
	int x, y;
	public A (int x1, int y1){
		this.x = x1; this.y = y1;
	}
	public int compareTo (A e) {
		return this.x == e.x ? this.y - e.y : this.x - e.x;
	}
}
public class Solution {

	final static int N = 200010;
	public static void main(String[] args) {
		int [] a = new int [N];
		int [] b = new int [N];
		TreeSet<A> S = new TreeSet<A> ();
		Scanner in = new Scanner (new BufferedInputStream (System.in));
		int n, d;
		n = in.nextInt (); d = in.nextInt ();
		S.add(new A(-1000000000, -1));
		for (int i = 1; i <= n; i++) {
			a[i] = in.nextInt (); b[i] = in.nextInt ();
			S.add (new A (b[i], i));
		}
		int besta = -1, bestb = -1, ma = -1;
		for (int i = 1, j = 1; i <= n; ++i) {
			for (; j <= n && a[j] - a[i] < d; ++j) {
				S.remove (new A (b[j], j));
			}
			if (S.isEmpty()) break;
			else if (S.last ().x + b[i] > ma) {
				ma = S.last ().x + b[i];
				besta = i;
				bestb = S.last ().y;
			}
		}
		System.out.printf ("%d %d\n", besta, bestb);
	}
}

