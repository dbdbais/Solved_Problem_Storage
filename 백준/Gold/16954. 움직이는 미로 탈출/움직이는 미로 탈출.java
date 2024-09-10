import java.awt.Point;
import java.io.*;
import java.util.*;


class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static StringBuilder sb = new StringBuilder();
	static int[][] arr = new int[8][8];
	static boolean[][] walls = new boolean[8][8];
	static int[][] simul = new int[8][8];
	static boolean found = false;
	static Queue<Point> wall = new ArrayDeque<>();
	static Queue<Point> people = new ArrayDeque<>();
	
	static final int[] dx = {1,-1,0,0,1,1,-1,-1,0};
	static final int[] dy = {0,0,-1,1,1,-1,1,-1,0};
	
	static boolean out(int x,int y) {
		return x < 0 || y < 0 || x >= 8 || y >= 8;
	}
	
	static void print() {
		System.out.println("=============");
		for(int i=0;i<8;i++) {
			for(int j=0;j<8;j++) {
				System.out.print(walls[i][j]+" ");
			}
			System.out.println();
		}
		System.out.println("=============");
	}
	
	public static void solve() {
		while(!people.isEmpty()) {
			int qSize = people.size();
			
			for(int i=0;i<qSize;i++) {
				//people 수 만큼 돌린다.
				Point cur = people.poll();
				int x = cur.x;
				int y = cur.y;
				
				
				if(walls[x][y]) continue;
				
				//int val = simul[x][y];
				//이미 벽이라면 SKIP
				if(x == 0 && y == 7) {
					found = true;
					break;
				}
				for(int j=0;j<9;j++) {
					int qx = x + dx[j];
					int qy = y + dy[j];
					if (out(qx,qy) || walls[qx][qy]) continue;
					//나갔으면 SKIP
					people.add(new Point(qx,qy));
					//simul[qx][qy] = Math.max( simul[qx][qy],val+1);
					//새로운 곳에 추가
				}
			}
			//print();
			if(found) break;
			
			int wSize = wall.size();
			
			for(int i=0;i<wSize;i++) {
				Point w = wall.poll();
				
				walls[w.x][w.y] = false;
				//	이전 벽 허물고
				int wx = w.x + dx[0];
				int wy = w.y + dy[0];
				if(out(wx,wy)) continue;
				
				walls[wx][wy] = true;
				wall.add(new Point(wx,wy));
				//다음을 위해 추가
			}
			//print();
			
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		
		people.add(new Point(7,0));
		ArrayList<Point> lst = new ArrayList<>();
		
		for(int i=0;i<8;i++) {
			String st = in.readLine();
			for(int j=0;j<8;j++) {
				if(st.charAt(j) != '.') {
					walls[i][j] = true; 
					lst.add(new Point(i,j));
				}
			}
		}
		Collections.reverse(lst);
		
		for(Point p : lst) {
			wall.add(new Point(p));
		}
		
		solve();
		
		if(found) {
			System.out.println(1);
		}
		else {
			System.out.println(0);
		}
	}

	

}