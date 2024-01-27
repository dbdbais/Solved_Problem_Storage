import java.awt.Point;
import java.io.*;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int m;
	static int n;
	static int ans;
	
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int [][] arr = new int[1004][1004];
	static int[] dx = {0,0,-1,1};
	static int[] dy = {-1,1,0,0};
	static Queue<Point> q = new LinkedList<Point>();

	static boolean check() {
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(ans < arr[i][j]) ans = arr[i][j];	//최대 값 갱신 
				if(arr[i][j] == Integer.MAX_VALUE) return false;
			}
		}
		return true;
	}
	
	static boolean out(int x,int y) {
		return x <0 || x >= n || y < 0 || y >=m;
	}
	static void print() {
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				 System.out.print(arr[i][j]+" ");
			}
			System.out.println();
		}
	}
	
	static void solve() {
		int x,y;
		while(!q.isEmpty()) {
			x = q.peek().x;
			y = q.peek().y;
			q.poll();
			
			for(int i=0;i<4;i++) {
				
				int qx = x + dx[i];
				int qy = y + dy[i];
				if(out(qx,qy) || arr[qx][qy] == -1) continue;
				if(arr[qx][qy] > arr[x][y]+1) {
					arr[qx][qy] = arr[x][y]+1;
					q.add(new Point(qx,qy));
				}
				
				
			}
		}
		
		
	}
	
	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(in.readLine());
		m = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());
		
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(in.readLine());
			for(int j=0;j<m;j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if(arr[i][j] == 1) 	q.add(new Point(i,j));
				else if(arr[i][j] == 0) arr[i][j] = Integer.MAX_VALUE;
				
			}	
		}
		solve();
		
		if(check()) {
			System.out.println(ans-1);
		}
		else {
			System.out.println(-1);
		}
		
		//print();
		
	}
}