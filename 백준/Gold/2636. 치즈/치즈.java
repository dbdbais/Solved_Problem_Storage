import java.awt.Point;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	private static StringBuilder sb = new StringBuilder();
	private static StringTokenizer st;

	static int [][] arr;
	static boolean[][] visited;
	static boolean[][] melt;
	static int N,M;
	static final int [] dx= {0,0,-1,1};
	static final int [] dy= {-1,1,0,0};

	static boolean check() {
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(arr[i][j]!=0) return false;
			}
		}
		return true;
	}

	static boolean out(int x,int y) {
		return x<0 || x >=N || y<0 || y >=M;
	}

	static void BFS(int x,int y) {
		Queue<Point> q = new ArrayDeque<>();
		q.add(new Point(x,y));
		visited[x][y] = true;
		while (!q.isEmpty()) {
			Point cur = q.poll();
			x = cur.x;
			y = cur.y;


			for(int i=0;i<4;i++) {
				int qx = x + dx[i];
				int qy = y + dy[i];
				if(out(qx,qy)||visited[qx][qy]) continue;

				if(arr[qx][qy] == 1) {
					melt[qx][qy] = true;

				}
				else {
					q.add(new Point(qx,qy));
				}
				visited[qx][qy] = true;

			}




		}

	}
	static void print() {
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				System.out.print(arr[i][j]+" ");
			}
			System.out.println();
		}

		System.out.println();

		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				System.out.print(visited[i][j]+" ");
			}
			System.out.println();
		}

		System.out.println();

		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				System.out.print(melt[i][j]+" ");
			}
			System.out.println();
		}
		System.out.println();
	}
	
	static void reset() {
		for(int i=0;i<N;i++) {
			Arrays.fill(visited[i], false);
		}
		for(int i=0;i<N;i++) {
			Arrays.fill(melt[i], false);
		}
	}
	static void doMelt() {
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(melt[i][j]) {
					arr[i][j]=0;
				}
			}

		}
	}
	
	static int count() {
		int cnt =0;
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(arr[i][j] == 1) cnt++;
			}

		}
		return cnt;
	}

	static void solve() {
		int T=0;
		int cnt=0;
		while(!check()) {
			T++;
			BFS(0,0);
			//print();
			cnt = count();
			doMelt();
			reset();
		}
		System.out.println(T);
		System.out.println(cnt);

	}

	public static void main(String[] args) throws Exception {
		/**
		 * 0. 입력파일 읽어들이기
		 */
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		arr = new int[N][M];
		visited = new boolean[N][M];
		melt = new boolean[N][M];
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(in.readLine());
			for(int j=0;j<M;j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		solve();

		
	}
}