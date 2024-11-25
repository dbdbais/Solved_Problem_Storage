import java.util.*;
import java.awt.*;
import java.io.*;

public class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int T;
	static int[] cnt;
	static int[][] arr;
	static boolean [][] visited;
	static final int[] pxarr = {0,0,0,1,2,2,2,1};
	static final int[] pyarr= {0,1,2,2,2,1,0,0};
	static StringBuilder sb;
	
	static final int[] dx = {0,0,-1,1};
	static final int[] dy = {-1,1,0,0};
	
	static boolean out(int x,int y) {
		return x < 0 || y < 0 || x >= 3 || y >= 3;
	}
	
	static void print() {
		for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++) {
				System.out.print(visited[i][j]+" ");
			}
			System.out.println();
		}
	}
	
	static int BFS(int x,int y) {
		int cnt = 1;
		Queue<Point> q = new ArrayDeque<>();
		
		q.add(new Point(x,y));
		visited[x][y] = true;
		while(!q.isEmpty()) {
			Point cur = q.poll();
			for(int i=0;i<4;i++) {
				int qx = cur.x + dx[i];
				int qy = cur.y + dy[i];
				
				if(out(qx,qy)|| visited[qx][qy]|| arr[qx][qy] == 0) continue;
				
				cnt++;
				visited[qx][qy] = true;
				q.add(new Point(qx,qy));
				
			}
		}
	
		return cnt;
	}
	
	static boolean solve() throws Exception {
		arr = new int[3][3];
		visited = new boolean[3][3];
		visited[1][1] = true;
		cnt = new int[10];
		
		for(int i=0;i<3;i++) {
			String s = in.readLine();
			for(int j=0;j<3;j++) {
				char c = s.charAt(j);
				if(c == 'O') {
					arr[i][j] = 1;
				}
			}
		}
		
		st = new StringTokenizer(in.readLine());
		
		int num = Integer.parseInt(st.nextToken());
		
		for(int i=0;i<num;i++) {
			cnt[Integer.parseInt(st.nextToken())]++;
		}
		
		for(int i=0;i<8;i++) {
			int x = pxarr[i];
			int y = pyarr[i];
			
			if(visited[x][y] || arr[x][y] == 0)continue;
			
			int tcnt = BFS(x,y);
			
			//System.out.println(x+":"+y +"="+tcnt);
			
			cnt[tcnt]--;
			//해딩하는 카운트 뺀다.
			
		}
		
		
		for(int i=1;i<=9;i++) {
			if(cnt[i] != 0) return false;
		}
		return true;
		
		
		
		
	}
	
	public static void main(String[] args) throws Exception {
		
		T = Integer.parseInt(in.readLine());
		sb = new StringBuilder();
		
		for(int i=0;i<T;i++) {
			if(solve()) {
				sb.append(1+"\n");
			}
			else {
				sb.append(0+"\n");
			}
		}
		
		System.out.println(sb);
		
	
		
	}
}