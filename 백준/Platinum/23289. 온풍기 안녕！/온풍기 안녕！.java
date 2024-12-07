import java.util.*;
import java.io.*;
import java.awt.*;

public class Main {

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int R, C, K, W, chocolate;

	static final int[] dx = { 0, 0, -1, 1 };
	static final int[] dy = { 1, -1, 0, 0 };
	// 우좌상하

	static final int[][] fdx = { { -1, 0, 1 }, { -1, 0, 1 }, { -1, -1, -1 }, { 1, 1, 1 } };
	// 우좌상하 [4][3]
	static final int[][] fdy = { { 1, 1, 1 }, { -1, -1, -1 }, { -1, 0, 1 }, { -1, 0, 1 } };
	// 우좌상하

	static boolean out(int x, int y) {
		return x < 0 || y < 0 || x >= R || y >= C;
	}

	static class Cord {
		int x;
		int y;
		int val;

		public Cord(int x, int y, int val) {
			this.x = x;
			this.y = y;
			this.val = val;
		}

		@Override
		public String toString() {
			return "Cord [x=" + x + ", y=" + y + ", val=" + val + "]";
		}

	}

	static int[][] arr;
	static int[][] temper;
	static boolean[][][] wall;
	static boolean[][] visited;
	static ArrayList<Point> five;
	static ArrayList<Point>[] fan;

	static void print() {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				System.out.print(temper[i][j] + " ");
			}
			System.out.println();
		}
	}

	public static void blow() {
		for (int i = 0; i < 4; i++) {
			for (Point fCord : fan[i]) {
				// 선풍기의 좌표 꺼내서
				int startX = fCord.x + dx[i];
				int startY = fCord.y + dy[i];
				if (out(startX, startY))
					continue;
				// 나갔다면 그냥 끝냄
				Queue<Cord> q = new ArrayDeque<>();
				visited = new boolean[R][C];

				q.add(new Cord(startX, startY, 5));
				visited[startX][startY] = true;
				temper[startX][startY] += 5;
				while (!q.isEmpty()) {
					Cord cur = q.poll();
					if (cur.val <= 1)
						continue;
					// 1이라면 더이상 진행 X
					for (int a = 0; a < 3; a++) {
						int qx = cur.x + fdx[i][a];
						int qy = cur.y + fdy[i][a];

						if (out(qx, qy) || visited[qx][qy])
							continue;

						int sideDir;
						// 온풍기 이동을 위한 방향

						if (a == 0 || a == 2) {
							if (i <= 1) {
								// 좌우 라면

								if (a == 0) {
									sideDir = 2;
								} else {
									sideDir = 3;
								}
								if (wall[qx][cur.y][i] || wall[cur.x][cur.y][sideDir])
									continue;
							} else {
								// 상하 라면

								if (a == 0) {
									sideDir = 1;
								} else {
									sideDir = 0;
								}

								if (wall[cur.x][qy][i] || wall[cur.x][cur.y][sideDir])
									continue;
							}
						} else {
							if (wall[cur.x][cur.y][i])
								continue;
						}

						visited[qx][qy] = true;
						int val = cur.val - 1;
						temper[qx][qy] += val;
						q.add(new Cord(qx, qy, val));
						// 다음 좌표로 넘김
					}
				}

			}
		}
	}

	public static void tempControl() {
		int[][] newTemp = new int[R][C];

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {

				// 온도를 나눠줄게 있다면
				int totalTemp = temper[i][j];
				// 나눠줄 온도
				for (int a = 0; a < 4; a++) {

					int qx = i + dx[a];
					int qy = j + dy[a];

					if (out(qx, qy) || wall[i][j][a])
						continue;
					// 나갔거나, 벽이 쳐져있으면 SKIP
					if (temper[i][j] <= temper[qx][qy])
						continue;
					// 옆의 온도가 더 크거나 같으면 SKIP
					int minusTemp = (temper[i][j] - temper[qx][qy]) / 4;
					// 차에서 4 나눈것
					newTemp[qx][qy] += minusTemp;

					totalTemp -= minusTemp;

				}
				// 남은 것 배열에 반영
				newTemp[i][j] += totalTemp;

			}
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				temper[i][j] = newTemp[i][j];
			}
		}
	}
	
	static boolean rotate(int x,int y) {
		int [] tx = {0,1,0,-1};
		int [] ty = {1,0,-1,0};
		//우하좌상
		ArrayList<Point> ways = new ArrayList<>();
		
		boolean found = false;
		
		int sx = x;
		int sy = y;
		
		int dir = 0;
		
		do {
			int qx = sx + tx[dir];
			int qy = sy + ty[dir];
			
			//System.out.println(qx +","+qy);
			
			if(out(qx,qy)|| visited[qx][qy]) {
				dir++;
				continue;
			}
			
			sx = qx;
			sy = qy;
			
			ways.add(new Point(sx,sy));
			//경로를 전부 기록
			
			if(temper[sx][sy] > 0) {
				found = true;
			}
			
			visited[sx][sy] = true;
			//방문 처리
			
		}while(sx!= x || sy != y);
		//우하좌상
		
		if(found) {
			for(Point cur : ways) {
				int val = temper[cur.x][cur.y];
				if(val > 0) {
					temper[cur.x][cur.y] = val-1;
				}
			}
		}
		
//		for(Point cur : ways) {
//			System.out.println(cur);
//		}
		
		return found;
		
	}
	
	static void minus() {
		visited = new boolean[R][C];
		
		for(int i=0;i<Math.min(R/2, C/2);i++) {
			if(rotate(i, i) == true) {
				break;
			}
		}
		
	}
	
	static boolean check() {
		for(Point f : five) {
			if(temper[f.x][f.y] < K) {
				return false;
			}
		}
		return true;
	}
	
	static void solve() {
		while(chocolate <= 100) {
			blow();
			tempControl();
			minus();
			//print();
			chocolate++;
			
			if(check()) break;
		}
		
		System.out.println(chocolate);
		
	}

	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(in.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		arr = new int[R][C];
		temper = new int[R][C];
		wall = new boolean[R][C][4];
		five = new ArrayList<>();
		fan = new ArrayList[4];
		// 4개의 선풍기 위치 생성
		for (int i = 0; i < 4; i++) {
			fan[i] = new ArrayList<>();
		}

		for (int i = 0; i < R; i++) {
			st = new StringTokenizer(in.readLine());
			for (int j = 0; j < C; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());

				if (arr[i][j] > 0) {
					if (arr[i][j] == 5) {
						five.add(new Point(i, j));
						// 5라면 해당 좌표 추가한다.
					} else {
						fan[arr[i][j] - 1].add(new Point(i, j));
						// 해당하는 선풍기에 전달
					}
				}
			}
		}

		W = Integer.parseInt(in.readLine());

		int x, y, t;

		for (int i = 0; i < W; i++) {
			st = new StringTokenizer(in.readLine());
			x = Integer.parseInt(st.nextToken());
			y = Integer.parseInt(st.nextToken());
			t = Integer.parseInt(st.nextToken());

			if (t == 0) {
				wall[x - 1][y - 1][2] = true;
				wall[x - 2][y - 1][3] = true;
			} else {
				wall[x - 1][y - 1][0] = true;
				// 우에 벽이 있음
				wall[x - 1][y][1] = true;
				// 좌에 벽이 있음
			}
		}
		
		solve();

	
	}
}