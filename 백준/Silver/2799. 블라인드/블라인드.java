import java.util.*;
import java.io.*;

public class Main {

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int M, N;
	static char[][] arr;

	static int[] curtain = new int[5];

	static void check(int x, int y) {
		int type = 0;
		for (int i = x; i <= x + 3; i++) {
			if (arr[i][y] == '*') {
				type++;
				continue;
			}
			break;
		}
		curtain[type]++;
	}

	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(in.readLine());
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());

		arr = new char[5 * M + 1][5 * N + 1];

		for (int i = 0; i < 5 * M + 1; i++) {
			String s = in.readLine();
			for (int j = 0; j < 5 * N + 1; j++) {
				arr[i][j] = s.charAt(j);
			}
		}
		int sx, sy;
		
		for(int i=0;i<M;i++) {
			sx = 1 + 5* i;
			for(int j=0;j<N;j++) {
				sy = 1 + 5*j;
				//System.out.println(sx+":"+sy);
				check(sx,sy);
			}
		}
		
		for(int i=0;i<5;i++) {
			System.out.print(curtain[i]+" ");
		}
		System.out.println();
	}

}