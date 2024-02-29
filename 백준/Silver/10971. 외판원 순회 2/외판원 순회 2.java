import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	private static StringBuilder sb = new StringBuilder();
	private static StringTokenizer st;
	static int N;
	static int[][] adjMatirx;
	static int[] input;
	static boolean[] isSel;
	static int ans = Integer.MAX_VALUE;
	static int getDist(int from, int to) {
		return adjMatirx[from][to];
	}

	
	static void solve(int idx) {
		if(idx == N) {
			int totDist =0;
//			for(int i=0;i<N;i++) {
//				System.out.print(input[i]+" ");
//			}
			for(int i=0;i<N-1;i++) {
				int way = getDist(input[i], input[i+1]);
				if(way == 0) return;
				totDist += way;
			}
			int finalWay = getDist(input[N-1],input[0]);
			if(finalWay == 0) return;
			totDist += finalWay;
			
			if(totDist < ans) ans = totDist;
			
			return;
		}
		
		for(int i=1;i<=N;i++) {
			if(isSel[i]) continue;
			isSel[i] = true;
			input[idx] = i;
			solve(idx+1);
			isSel[i]= false;
		}
		
		
	}
	
	public static void main(String[] args) throws Exception {
		/**
		 * 0. 입력파일 읽어들이기
		 */
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(in.readLine());
		adjMatirx = new int[N+1][N+1];
		input = new int[N];
		isSel = new boolean[N+1];
		
		for(int i=1;i<=N;i++) {
			st = new StringTokenizer(in.readLine());
			for(int j=1;j<=N;j++) {
				adjMatirx[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		solve(0);
		sb.append(ans);
		System.out.println(sb);
	}
}