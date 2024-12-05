import java.util.*;
import java.io.*;
import java.awt.*;

public class Main {
	
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int R,C,N;
	
	static final int[] dx = {0,0,-1,1};
	static final int[] dy = {-1,1,0,0};
	
	static char[][] arr;
	static int[][] timer;
	
	static void print() {
		for(int i=0;i<R;i++) {
			for(int j=0;j<C;j++) {
				System.out.print(arr[i][j]);
			}
			System.out.println();
		}
		System.out.println();
	}
	
	static boolean out(int x,int y) {
		return x < 0 || y < 0 || x >= R || y >= C;
	}
	
	static void install(int curTime) {
		for(int i=0;i<R;i++) {
			for(int j=0;j<C;j++) {
				if(arr[i][j] == '.' ) {
					arr[i][j] = 'O';
					timer[i][j] = curTime+3;
				}
			}
		}
		
	}
	
	static void explode(int curTime) {
		Queue<Point> q = new ArrayDeque<>();
		for(int i=0;i<R;i++) {
			for(int j=0;j<C;j++) {
				if(timer[i][j] == curTime) {
					q.add(new Point(i,j));
					//해당하는 좌표 추가
				}
			}
		}
		
		while(!q.isEmpty()) {
			Point bomb = q.poll();
			timer[bomb.x][bomb.y] = 0;
			arr[bomb.x][bomb.y] = '.';
			for(int i=0;i<4;i++) {
				int qx = bomb.x + dx[i];
				int qy = bomb.y + dy[i];
				
				if(out(qx,qy)) continue;
				arr[qx][qy] = '.';
				timer[qx][qy] = 0;
			}
			//십자 다 터뜨리고
		}
	}
	

	
	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(in.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		
		arr = new char[R][C];
		timer = new int[R][C];
		
		for(int i=0;i<R;i++) {
			String s = in.readLine();
			for(int j=0;j<C;j++) {
				arr[i][j] = s.charAt(j);
				if(arr[i][j] == 'O') {
					timer[i][j] = 3;
				}
			}
		}
		if(N<2) {
			print();
		}
		else {
			boolean install = true;
			for(int i=2;i<=N;i++) {
				if(install) {
					install(i);
					install = false;
				}
				else {
					explode(i);
					install = true;
				}
				
			}
			print();
			
		}
		
		
		
		
		
	}
}