import java.util.*;
import java.io.*;
import java.awt.*;

public class Main {

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N,M,cnt;
	static boolean[][] visited;
	static int [][] arr;
	static int [] dx = {0,0,1,-1};
	static int [] dy = {-1,1,0,0};
	
	static boolean out(int x,int y) {
		return x < 0 || y < 0 || x >= N || y >= M;
	}
	
	static void print() {
		for(int i=0;i<N;i++) {
			for(int j=0; j< M ; j++) {
				System.out.print(visited[i][j]+"");
			}
			System.out.println();
		}
		System.out.println();
	}
	
	static void BFS(int x,int y) {
		Queue<Point> q = new ArrayDeque<>();
		
		cnt++;
		
		q.add(new Point(x,y));
		visited[x][y] = true;
		int val = arr[x][y];
		
		while(!q.isEmpty()) {
			
			Point cur = q.poll();
			
			if(val == 1) {
				
				for(int i=0;i<2;i++) {
					int qx = cur.x + dx[i];
					int qy = cur.y + dy[i];
					if(out(qx,qy) || visited[qx][qy] || arr[qx][qy] != val) continue;
					
					q.add(new Point(qx,qy));
					visited[qx][qy] = true;
					
				}
				
			}
			else {
				for(int i=2;i<4;i++) {
					int qx = cur.x + dx[i];
					int qy = cur.y + dy[i];
					if(out(qx,qy) || visited[qx][qy] || arr[qx][qy] != val) continue;
					
					q.add(new Point(qx,qy));
					visited[qx][qy] = true;
					
				}
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		visited = new boolean[N][M];
		arr = new int[N][M];
		
		for(int i=0;i<N;i++) {
			String s = in.readLine();
			for(int j=0;j<M;j++) {
				if(s.charAt(j) == '-'){
					arr[i][j] = 1;
				}
				else {
					arr[i][j] = 2;
				}
			}
		}
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(visited[i][j]) continue;
				
				BFS(i,j);
				//print();
			}
		}
		
		System.out.println(cnt);
		
	}
	
}