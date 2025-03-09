import java.util.*;
import java.io.*;

public class Main{
	
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N,M,K,r,c;
	static int [][] arr,dp;
	
	static int calcMatrix(int a,int b) {
		return arr[a][0] * arr[a][1] * arr[b][1]; 
		//이전 행 & 이전 열 * 다음 열
	}
	public static void main(String[] args) throws Exception {
		N = Integer.parseInt(in.readLine());
		
		arr = new int [N+1][2];
		dp = new int[N+1][N+1];
		//좌에서 부터 우까지의 최솟값
		
		for(int i=1;i<=N;i++) {
			st = new StringTokenizer(in.readLine());
			r = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			arr[i][0] = r;
			arr[i][1] = c;
			//r행 c열 의 행렬
		}
		
		for(int i=0;i<N;i++) {
			dp[i][i] = 0;
			//내 행렬에서 내까지 0으로 init
			dp[i][i+1] = calcMatrix(i, i+1);
			//바로 다음 행렬까지의 연산 값 계산
			
		}
		
		for(int k=2;k<N;k++) {
			//System.out.println(k+"k");
			//k를 점차 증가 시켜 그 구간이 점점 길어지며 더하게 만듦
			for(int i=1;i+k<=N;i++) {
				//System.out.println(i+"i");
				dp[i][i+k] = Integer.MAX_VALUE;
				//최댓값을 집어 넣어 최소를 점점 찾아나감
				for(int j=i;j<i+k;j++) {
					//System.out.println(j+"j");
					dp[i][i+k] = Math.min(dp[i][i+k], dp[i][j]+ dp[j+1][i+k] + arr[i][0] * arr[j][1] * arr[i+k][1]);
					// dp[i][i+k] i부터 k 구간에  j라는 구간을 두어 최솟값 을 업데이트
					
				}
				
			}
		}
		
		
		System.out.println(dp[1][N]);
		
		}
	
}