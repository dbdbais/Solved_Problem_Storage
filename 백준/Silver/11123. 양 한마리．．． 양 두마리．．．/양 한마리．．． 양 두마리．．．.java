import java.util.*;
import java.io.*;
import java.awt.*;
class Main {
	
	static StringTokenizer st;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int T,N,H,W;
	static char [][] arr;
	static StringBuilder sb;
	static int [] dx = {0,0,-1,1};
	static int [] dy = {-1,1,0,0};
	
	static boolean out(int x,int y) {
		return x <0 || y <0 || x >= H || y >= W;
	}
	
	static void BFS(int x,int y) {
		Queue<Point> q = new ArrayDeque<>();
		arr[x][y] ='.';
		q.add(new Point(x,y));
		
		while(!q.isEmpty()) {
			Point cur = q.poll();
			
			for(int i=0;i<4;i++) {
				int qx = cur.x + dx[i];
				int qy = cur.y + dy[i];
				
				if(out(qx,qy)|| arr[qx][qy] =='.') continue;
				
				arr[qx][qy] = '.';
				q.add(new Point(qx,qy));
			}
			
		}
		
	}
	
	public static void main(String[] args) throws Exception {
		T = Integer.parseInt(in.readLine());
		sb = new StringBuilder();
		for(int i=0;i<T;i++) {
			st = new StringTokenizer(in.readLine());
			H = Integer.parseInt(st.nextToken());
			W = Integer.parseInt(st.nextToken());
			
			arr = new char[H][W];
			
			for(int j=0;j<H;j++) {
				String s = in.readLine();
				for(int k=0;k<W;k++) {
					arr[j][k] = s.charAt(k);
				}
			}
			int cnt =0;
			for(int j=0;j<H;j++) {
				for(int k=0;k<W;k++) {
					if(arr[j][k] == '#') {
						BFS(j,k);
						cnt++;
					}
				}
			}
			sb.append(cnt+"\n");
		}

		
		System.out.println(sb);
	}
}