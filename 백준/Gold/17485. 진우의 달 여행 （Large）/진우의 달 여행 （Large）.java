import java.io.*;
import java.util.*;


class Main {
	
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int N,M,ans = Integer.MAX_VALUE;
	static int [][] arr;
	static int [][][] DP;
	
	static final int[] dx = {-1,-1,-1};
	static final int[] dy = {-1,0,1};
	//왼 중 오
	
	static boolean out(int x,int y) {
		return x < 1 || x > N || y < 1 || y > M;
	}
	
	public static void main(String[] args) throws IOException {
		
		st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		arr = new int[N+1][M+1];
		DP = new int[N+1][M+1][3];
		//N행 M열 왼,중,오
		
		for(int i=1;i<=N;i++) {
			st = new StringTokenizer(in.readLine());
			for(int j=1;j<=M;j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		for(int i=0;i<=N;i++) {
			for(int j=1;j<=M;j++) {
				Arrays.fill(DP[i][j],Integer.MAX_VALUE);
			}
		}
	
		
		for(int j=1;j<=M;j++) {
			for(int k=0;k<3;k++) {
				DP[1][j][k] = arr[1][j];
			}
		}
		//초기 값 세팅
		
		
		for(int i=2;i<=N;i++) {
			for(int j=1;j<=M;j++) {
				int val = arr[i][j];
				//현재 위치 값
				
				for(int a =0;a<3;a++) {
					int mn = Integer.MAX_VALUE;
					//최소값 저장 될 것
					
					//왼 중 오를 전부 본다.
					int qx = i + dx[a];
					int qy = j + dy[a];
					if(out(qx,qy)) continue;
					//나갔다면 SKIP
					for(int b =0;b<3;b++) {
						//이전 DP배열에서 지금까지 지나왔던 길을 보고
						if(a == b) continue;
						//연속으로 같은 곳을 갈 수 없다.
						mn = Math.min(mn, DP[qx][qy][b]);
						//모든 방향에서 가장 작은 값 구한다.
					}
					DP[i][j][a] = val + mn;
					//a의 방향을 선택했을 때 최적의 값 저장
				}
			}
		}
		
		for(int j=1;j<=M;j++) {
			for(int k =0;k<3;k++) {
				ans = Math.min(ans, DP[N][j][k]);
			}
		}
		
		System.out.println(ans);
		
		
	}

	

}