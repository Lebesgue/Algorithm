import java.io.BufferedInputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


public class Solution {

	/**
	 * @param args
	 */
	class E {
		int x, d;
		E (int x, int d) {
			this.x = x;
			this.d = d;
		}
	}
	
	public void solve () {
		Scanner in = new Scanner (new BufferedInputStream (System.in));
		int n = in.nextInt ();
		int i, j, k;
		
		ArrayList<E> [] a = new ArrayList [n + 1];
		int [] dis = new int[n];
		int [] disx = new int[n];
		int [] disy = new int[n];
		
		int mx, my, x, y;
		
		for (i = 0; i < n; ++i) 
			a[i] = new ArrayList<E> ();
		
		for (i = 1; i < n; ++i) {
			j = in.nextInt (); --j;
			k = in.nextInt ();
			a[i].add (new E (j, k));
			a[j].add (new E (i, k));
		}
		
		Arrays.fill(dis, -1);
		Arrays.fill(disx, -1);
		Arrays.fill(disy, -1);
		
		Queue<Integer> q = new LinkedList<Integer> ();
		q.add (1); 
		dis[1] = 0; mx = -1; my = -1; x = 0; y = 0;
		while (!q.isEmpty()) {
			int u = q.poll();
			for (E e : a[u]) {
				int v = e.x, d = e.d;
				if (dis[v] == -1) {
					dis[v] = dis[u] + d;
					if (dis[v] > mx) {
						mx = dis[v];
						x = v;
					}
					q.add (v);
				}
			}
		}
		
		q.add (x);
		disx[x] = 0;
		while (!q.isEmpty()) {
			int u = q.poll ();
			for (E e : a[u]) {
				int v = e.x, d = e.d;
				if (disx[v] == -1) {
					disx[v] = disx[u] + d;
					if (disx[v] > my) {
						my = disx[v];
						y = v;
					}
					q.add(v);
				}
			}
		}
		
		q.add (y);
		disy[y] = 0;
		while (!q.isEmpty()) {
			int u = q.poll ();
			for (E e : a[u]) {
				int v = e.x, d = e.d;
				if (disy[v] == -1) {
					disy[v] = disy[u] + d;
					q.add(v);
				}
			}
		}
		for (i = 0; i < n; ++i)
			System.out.printf("%d\n", Math.max (disx[i], disy[i]));
	}
	
	public static void main(String[] args) {
		Solution solution = new Solution ();
		solution.solve ();
	}
		
}

