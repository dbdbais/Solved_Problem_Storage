import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
private static StringBuilder sb = new StringBuilder();
private static StringTokenizer st;
static int N,M;

static int[][] maze;
static int[][] dp;

static int[] dx = {0,1,1};	// 우, 하, 우하
static int[] dy = {1,0,1};

static void print() {
//	for(int i=1;i<=N;i++) {
//		for(int j =1; j<=M;j++) {
//			System.out.print(maze[i][j]+" ");
//		}
//		System.out.println();
//	}
//	System.out.println();
	
	for(int i=1;i<=N;i++) {
		for(int j =1; j<=M;j++) {
			System.out.print(dp[i][j]+" ");
		}
		System.out.println();
	}
	System.out.println();
}
static boolean out(int x,int y) {
	return x<1 || y<1 || x>N || y >M;
}
static void solve() {
	for(int i=1;i<=N;i++) {
		for(int j =1; j<=M;j++) {
			for(int k=0;k<3;k++) {
				int qx = i + dx[k];
				int qy = j + dy[k];
				if(out(qx,qy)) continue;
				dp[qx][qy] = Math.max(dp[i][j]+maze[qx][qy], dp[qx][qy]);
			}
		}
	}
	
	
}

public static void main(String[] args) throws Exception {
	/**
	 * 0. 입력파일 읽어들이기
	 */
	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	st = new StringTokenizer(in.readLine());
	N = Integer.parseInt(st.nextToken());
	M = Integer.parseInt(st.nextToken());
	
	
	maze = new int [N+1][M+1];
	dp = new int [N+1][M+1];

	for(int i=1;i<=N;i++) {
		st = new StringTokenizer(in.readLine());
		for(int j=1;j<=M;j++) {
			maze[i][j] = Integer.parseInt(st.nextToken());
		}
	}
	dp[1][1] = maze[1][1];	//첫번째 값 대입
	solve();
	
	//print();
	System.out.println(dp[N][M]);
	
}
}