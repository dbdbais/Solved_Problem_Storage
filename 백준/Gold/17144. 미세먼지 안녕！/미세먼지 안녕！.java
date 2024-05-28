import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	static int R, C, T;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int arr[][];
	static Point uAir, dAir;
	static final int[] dx = { -1, 0, 1, 0 };	//상 우 하 좌
	static final int[] dy = { 0, 1, 0, -1 };
	
	
	static final int[] tx = { 1, 0, -1, 0 };	//하 우 상 좌
	static final int[] ty = { 0, 1, 0, -1 };
	

	static boolean out(int x, int y) {
		return x < 1 || y < 1 || x > R || y > C;
	}

	static void input() throws IOException {
		
		uAir = new Point();
		dAir = new Point();
		int cnt = 0;
		for (int i = 1; i <= R; i++) {
			st = new StringTokenizer(in.readLine());
			for (int j = 1; j <= C; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if (arr[i][j] == -1) {
					if (cnt == 0) {
						uAir.x = i;
						uAir.y = j;
						cnt++;
					} else {
						dAir.x = i;
						dAir.y = j;
					}
				}
			}
		}
	}
	
	static void print() {
		for(int i=1;i<=R;i++) {
			for(int j=1;j<=C;j++) {
				System.out.print(arr[i][j]+" ");
			}
			System.out.println();
		}
		System.out.println();
	}

	static void wind() {
		int[][] res = new int[R+1][C+1]; // 결과가 저장될 배열

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (arr[i][j] != 0) { // 미세먼지가 있다면

					int partial = arr[i][j] / 5; // 확산되는 양
					if (partial > 0) {
						int subCnt = 0;
						for (int k = 0; k < 4; k++) {
							int qx = i + dx[k];
							int qy = j + dy[k];
							if(out(qx,qy)|| (qx == uAir.x && qy == uAir.y) || (qx == dAir.x && qy == dAir.y)) continue;
							res[qx][qy] += partial;
							subCnt++;
						}
						res[i][j] += arr[i][j] - (partial * subCnt);
					}
					else {
						res[i][j] += arr[i][j];
					}

				}
			}
		}
		
		arr = res;	//배열 바꿔치기
	}
	static void airRefresh() {
		List<Point> ulst = new ArrayList<>();
		List<Point> dlst = new ArrayList<>();
		
		int ux = uAir.x;
		int uy = uAir.y;
		int udir =0;
		//System.out.println(ux + " , " + uy);
		while(true) {
			
			int qx = ux + dx[udir];
			int qy = uy + dy[udir];
			//System.out.println("qx : "+ qx + " qy : "+qy);
			
			if(qx == uAir.x && qy == uAir.y) {	//원점으로 돌아오면
				//System.out.println("도착");
				break;
			}
			
			if(out(qx,qy)|| qx> uAir.x) {	
				//System.out.println("방향 바뀜");
				udir++;	//방향 바꾼다
				continue;
			}
			ulst.add(new Point(qx,qy));
			ux = qx;
			uy = qy;
		}
		
		for(int i=0;i<ulst.size()-1;i++) {
			int px = ulst.get(i).x;
			int py = ulst.get(i).y;
			int nx = ulst.get(i+1).x;
			int ny = ulst.get(i+1).y;
			
			arr[px][py] = arr[nx][ny];
		}
		arr[uAir.x][uAir.y+1] = 0;
		
		
		int ax = dAir.x;
		int ay = dAir.y;
		int ddir =0;
		//System.out.println(ax + " , " + ay);
		while(true) {
			
			int qx = ax + tx[ddir];
			int qy = ay + ty[ddir];
			//System.out.println("qx : "+ qx + " qy : "+qy);
			
			if(qx == dAir.x && qy == dAir.y) {	//원점으로 돌아오면
				//System.out.println("도착");
				break;
			}
			
			if(out(qx,qy)|| qx< dAir.x) {	
				//System.out.println("방향 바뀜");
				ddir++;	//방향 바꾼다
				continue;
			}
			dlst.add(new Point(qx,qy));
			ax = qx;
			ay = qy;
		}
		
		for(int i=0;i<dlst.size()-1;i++) {
			int px = dlst.get(i).x;
			int py = dlst.get(i).y;
			int nx = dlst.get(i+1).x;
			int ny = dlst.get(i+1).y;
			
			arr[px][py] = arr[nx][ny];
		}
		arr[dAir.x][dAir.y+1] = 0;
	}
	static int count() {
		int sm = 0;
		for(int i=1;i<=R;i++) {
			for(int j=1;j<=C;j++) {
				if(arr[i][j]> 0) sm += arr[i][j];
			}
		}
		return sm;
	}

	public static void main(String[] args) throws IOException {

		st = new StringTokenizer(in.readLine());

		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		T = Integer.parseInt(st.nextToken());

		arr = new int[R + 1][C + 1];

		input();
	
		while(T !=0) {
			wind();
			airRefresh();
			T--;
		}
		System.out.println(count());
	}

}