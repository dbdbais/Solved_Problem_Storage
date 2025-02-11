import java.util.*;
import java.io.*;

public class Main {
	
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N,M,ans;
	static int [][] arr;
	static int [][] visited;
	//사이클 확인할 방문 배열
	
	static final int [] dx = {0,0,-1,1};
	static final int [] dy = {-1,1,0,0};
	//좌우상하
	
	static boolean out(int x,int y) {
		return x < 0 || y <0 || x >=N || y >=M;
	}
	
	static void DFS(int x,int y) {
		visited[x][y] = 1;
		//현재 방문 처리
		
		//System.out.println(x+":"+y);
		int dir = arr[x][y];
		//가리키고 있는 방향
		int qx = x + dx[dir];
		int qy = y + dy[dir];
		
		if(visited[qx][qy] == 1) ans++;
		
		else if(visited[qx][qy] == 0) DFS(qx,qy);
		
		visited[x][y] = 2;
		//한번 싸이클 생성한 것으로 표현
	}
	
	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		arr = new int[N][M];
		visited = new int[N][M];
		
		for(int i=0;i<N;i++) {
			String s = in.readLine();
			for(int j=0;j<M;j++) {
				Character c = s.charAt(j);
				int dir = -1;
				//좌우상하 0123
				if(c == 'D') {
					dir = 3;
				}
				else if(c == 'L') {
					dir = 0;
				}
				else if(c == 'R') {
					dir = 1;
				}
				else {
					dir = 2;
				}
				
				arr[i][j] = dir;
				
			}
		}
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(visited[i][j] != 0) continue;
				//하나 증가하고
				
				//System.out.println(i+":"+j);
				DFS(i,j);
			}
			//print();
		}
		System.out.println(ans);
		
		
		
		
	}
	
	
}