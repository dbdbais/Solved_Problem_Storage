import java.io.*;
import java.util.*;
import java.awt.*;

public class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int M,N;
	static int [][] arr;
	static int [][] dp;
	
	static final int [] dx = {0,0,-1,1};
	static final int [] dy = {-1,1,0,0};
	
	static boolean out(int x,int y) {
		return x < 0 || y < 0 || x >= M || y >=N;
	}
	
	private static int DFS(int x, int y) {
		
		if(x == M-1 && y == N-1) return 1;
		
		int val = 0;
		//현재 값
		if(dp[x][y] != -1) {
			return dp[x][y];
		}
		else {
			
			for(int i=0;i<4;i++) {
				
				int qx = x + dx[i];
				int qy = y + dy[i];
				
				if(out(qx,qy)) continue;
				boolean isBig = arr[qx][qy] >= arr[x][y];
				if(!isBig) {
					val += DFS(qx,qy);
					//분할정복 메모제이션
				}
				
			}
			dp[x][y] = val;
			
			return dp[x][y];
		}
	}
	
	static void print() {
		for(int i=0;i<M;i++) {
			for(int j=0;j<N;j++) {
				System.out.print(dp[i][j]+" ");
			}
			System.out.println();
		}
	}
	
	public static void main(String[] args) throws IOException {	
		st = new StringTokenizer(in.readLine());
		
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		arr = new int[M][N];
		dp = new int[M][N];
		
		for(int i=0;i<M;i++) {
			Arrays.fill(dp[i], -1);
		}
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(in.readLine());
			for(int j=0;j<N;j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		System.out.println(DFS(0,0));
		//print();
		
	}



}