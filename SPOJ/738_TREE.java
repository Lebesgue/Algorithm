import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	final static int N = 32;
	final static int D = 16;
	
	void SPOJ738_TREE () {
		BigInteger [][] C = new BigInteger [N + 1][N + 1];
		BigInteger [][] d = new BigInteger [N + 1][D + 1];
		BigInteger [][] g = new BigInteger [N + 1][D + 1];
		int i, j, k, n, dep;
		for (i = 0; i <= N; ++i) {
			C[i][0] = BigInteger.valueOf(1);
			C[i][i] = BigInteger.valueOf(1);
		}
		for (i = 1; i <= N; ++i)
			for (j = 1; j < i; ++j)
				C[i][j] = C[i - 1][j].add (C[i - 1][j - 1]);
		
		for (i = 1; i <= N; ++i) {
			d[i][0] = BigInteger.valueOf(1);
			d[i][1] = BigInteger.valueOf(1);
			g[i][0] = BigInteger.valueOf(1);
			g[i][1] = BigInteger.valueOf(2);
		}
		for (i = 2; i <= N; ++i) {
			for (j = 2; j <= D; ++j) {
				d[i][j] = BigInteger.valueOf (0);
				g[i][j] = g[i][j - 1];
				for (k = 1; k <= i; ++k) 
					d[i][j] = d[i][j].add(C[i][k].multiply(d[i][j - 1].pow(k).multiply(g[i][j - 2].pow(i - k))));
				g[i][j] = g[i][j].add (d[i][j]);
				if (d[i][j].toString().length() > 200) break;
			}
		}
/*		PrintWriter pwriter = new PrintWriter (new FileWriter (new File ("out.txt")), true);
		for (i = 1; i <= N; ++i)
			for (j = 0; j <= D; ++j) {
				pwriter.printf ("s[%d][%d] = \"%s\"\n", i, j, d[i][j]);
			}*/
		Scanner in = new Scanner (new BufferedInputStream (System.in));
		try {
			while (in.hasNext()) {
				n = in.nextInt(); dep = in.nextInt();
				System.out.println (n + " " + dep + " " + d[n][dep].toString());
			}
		} catch (Exception e) {
			return;
		}
	}
		
	public static void main(String[] args) {
		Main SPOJSolver = new Main ();
		SPOJSolver.SPOJ738_TREE ();

	}

}

