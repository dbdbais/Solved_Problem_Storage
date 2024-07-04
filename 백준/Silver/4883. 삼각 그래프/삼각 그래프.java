import java.io.*;
import java.util.*;
import java.awt.*;

public class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N;
	static long ans;
	static int [][] arr;
	static long [][] dp;

	static void solve() {
		
		dp[1][1] = arr[1][1];
		dp[1][2] = arr[1][1] + arr[1][2];
		//맨 오른쪽 누적
		
		
		for(int i=2;i<=N;i++) {
			
				long mn = Long.MAX_VALUE;
				dp[i][0] = Math.min(dp[i-1][0],dp[i-1][1]) + arr[i][0];
				dp[i][1] = Math.min(Math.min(Math.min(dp[i-1][0],dp[i-1][1]),dp[i-1][2]),dp[i][0]) + arr[i][1];
				dp[i][2] = Math.min(Math.min(dp[i-1][1], dp[i-1][2]),dp[i][1]) + arr[i][2];
	
		}
		
		ans = dp[N][1];
	}
	
	static void print() {
		for(int i=0;i<=N;i++) {
			for(int j=0;j<3;j++) {
				System.out.print(dp[i][j] +" ");
			}
			System.out.println();
		}
	}
	
	static void reset() {
		arr = new int[N+1][3];
		dp = new long[N+1][3];
		for(int i=0;i<=N;i++) {
			Arrays.fill(dp[i],Long.MAX_VALUE);
		}
		ans = Long.MAX_VALUE;
		
	}
	
	public static void main(String[] args) throws IOException{
		int k = 0;
		while(true) {
			N = Integer.parseInt(in.readLine());
			if(N == 0) break;
			k++;
			reset();
			for(int i=1;i<=N;i++) {
				st = new StringTokenizer(in.readLine());
				for(int j=0;j<3;j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			solve();
			//print();
			System.out.println(k+". " + ans);
			
		}
	}
	
}