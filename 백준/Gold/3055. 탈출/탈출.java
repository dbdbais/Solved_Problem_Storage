import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	static int R, C;
	static ArrayList<Point> wlst = new ArrayList<>();
	static char[][] arr;
	static int[][] visited;
	static int[][] flood;
	static final int[] dx = { 0, 0, -1, 1 };
	static final int[] dy = { -1, 1, 0, 0 };
	static int startX, startY, endX, endY;

	static boolean out(int x, int y) { // 장외처리
		return x < 0 || y < 0 || x >= R || y >= C;
	}

	static void print() {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (flood[i][j] == Integer.MAX_VALUE) {
					System.out.print("I ");
				} else {
					System.out.print(flood[i][j] + " ");
				}
			}
			System.out.println();
		}

		System.out.println();

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (visited[i][j] == Integer.MAX_VALUE) {
					System.out.print("I ");
				} else {
					System.out.print(visited[i][j] + " ");
				}
			}
			System.out.println();
		}
	}

	static void WBFS(int fx,int fy) {

		Queue<Point> q = new ArrayDeque<>();

		int cnt = 1;
		flood[fx][fy] = cnt;
		q.add(new Point(fx, fy));
		while (!q.isEmpty()) {
			cnt++;
			int qSize = q.size();

			for (int i = 0; i < qSize; i++) {
				Point cur = q.poll();
				int x = cur.x;
				int y = cur.y;
				// System.out.println(x +" : " + y);
				for (int a = 0; a < 4; a++) {
					int qx = x + dx[a];
					int qy = y + dy[a];
					if (out(qx, qy) || arr[qx][qy] == 'D' || arr[qx][qy] == 'X') continue;
					if(flood[qx][qy] > cnt) {
						flood[qx][qy] = cnt;
						q.add(new Point(qx, qy));
					}
				}
			}
		}
	}

	static boolean safe;
	static int safeTime;

	static void BFS() {

		Queue<Point> q = new ArrayDeque<>();

		int cnt = 1;
		visited[startX][startY] = cnt;
		q.add(new Point(startX, startY));

		while (!q.isEmpty()) {
			cnt++;
			int qSize = q.size();

			for (int i = 0; i < qSize; i++) {
				Point cur = q.poll();
				int x = cur.x;
				int y = cur.y;
				// System.out.println(x +" : " + y);
				for (int a = 0; a < 4; a++) {
					int qx = x + dx[a];
					int qy = y + dy[a];
					if (out(qx, qy) || flood[qx][qy] <= cnt || arr[qx][qy] == 'X' || visited[qx][qy] != 0)
						continue;
					// 나갔거나 물이 더 빠르거나 방문했다면 SKIP
					visited[qx][qy] = cnt;
					q.add(new Point(qx, qy));
				}
				if (safe)
					break;
			}
		}

	}

	public static void main(String[] args) throws IOException {

		st = new StringTokenizer(in.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		arr = new char[R][C];
		visited = new int[R][C];
		flood = new int[R][C];

		String s;
		for (int i = 0; i < R; i++) {
			s = in.readLine();
			for (int j = 0; j < C; j++) {
				arr[i][j] = s.charAt(j); // 문자 하나씩 쪼개서 집어넣는다.
				if (arr[i][j] == 'S') {
					startX = i;
					startY = j;
				} else if (arr[i][j] == '*') {
					wlst.add(new Point(i,j));
				} else if (arr[i][j] == 'D') {
					flood[i][j] = Integer.MAX_VALUE;
					endX = i;
					endY = j;
				}
			}
		}
		for(int i=0;i<R;i++) {
			Arrays.fill(flood[i],Integer.MAX_VALUE);
		}
		
		for(Point p : wlst) {
			WBFS(p.x,p.y);
		}
		BFS();
		//print();

		if(visited[endX][endY] > 0) {
			System.out.println(visited[endX][endY]-1);
		}
		else {
			System.out.println("KAKTUS");
		}
	}

}