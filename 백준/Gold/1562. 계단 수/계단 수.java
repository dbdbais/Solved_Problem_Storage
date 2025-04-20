import java.util.*;
import java.io.*;

public class Main {

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb;
	static final int MOD = 1000000000;
	static int N;

	static int dp[][][];
	// N 번째 위치, 이전에 볼 숫자, 비트마스킹으로 표현한 이전 상태들 
	

	public static void main(String[] args) throws Exception {
		
		N = Integer.parseInt(in.readLine());
		
		dp = new int [N+1][10][1024];
		
		for(int i=1;i<10;i++) {
			dp[1][i][1<<i] = 1;
			//1 ~ 9 까지 1로 설정 0은 올수 없으니 0으로 내비둠.
		}
		
		for(int i=1;i<N;i++) {
			for(int j=0;j<10;j++) {
				for(int k=0;k<1024;k++) {
					int curVal = dp[i][j][k];
					// 현재 보고 있는 값
					if(j > 0) {
						//현재 위치가 0보다 크다면 이전의 값이 있음
						dp[i+1][j-1][k | (1<< (j-1))] += curVal;
						// 지금의 상태 반영해준 dp 배열에 내 현재 보고 있는 값 더한다.
						dp[i+1][j-1][k | (1<< (j-1))] %= MOD;
					}
					if(j <9) {
						//현재 위치가 9보다 작다면
						dp[i+1][j+1][k | (1 << (j+1))] += curVal;
						// 지금의 상태 반영해준 dp 배열에 내 현재 보고 있는 값 더한다.
						dp[i+1][j+1][k | (1 << (j+1))] %= MOD;
					}
					
				}
				
			}
			
		}
		
		int sm = 0;
		
		for(int i=0;i<=9;i++) {
			sm += dp[N][i][1023];
			//N개의 len을 가진 수 중에 마지막 j로 끝난 수 중 1023(1111111111), 즉 모든 수가 있는 형태의 숫자를 카운팅
			sm %= MOD;
		}
		
		System.out.println(sm);
		
	}

}
