import java.io.*;
import java.util.*;


class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	
	static int [][] dp;
	static int N;
	static int mod = 9901;
	public static void main(String[] args) throws IOException {

		N = Integer.parseInt(in.readLine());
		
		dp = new int[N+1][3];
		// 0은 이전이 빈칸일 경우, 1은 이전이 좌측일 경우, 2는 이전이 우측일 경우
		dp[1][0] = dp[1][1] = dp[1][2] = 1;
		
		for(int i=2;i<=N;i++) {
			dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % mod ;
			dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % mod;
			dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % mod;
		}
		
//		for(int i=1;i<=N;i++) {
//			for(int j=0;j<3;j++) {
//				System.out.print(dp[i][j] +" ");
//			}
//			System.out.println();
//		}
		
		int sm = 0;
		
		for(int i=0;i<3;i++) {
			sm = (sm + dp[N][i]) % mod;
		}
		
		System.out.println(sm);

	}

}