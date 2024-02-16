import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	private static StringBuilder sb = new StringBuilder();
	private static StringTokenizer st;
	static int [][] arr;
	static int cnt;
	static int ans;
	static int N,M,D;
	static List<Point> killed = new ArrayList<>();
	static class Point implements Comparable<Point>{
		int x;
		int y;
		int distance;
		public Point(int x, int y,int distance) {
			this.x = x;
			this.y = y;
			this.distance = distance;
		}

		@Override
		public int compareTo(Point o) {
			if(this.distance == o.distance) {
				return this.y - o.y;
			}
			return this.distance- o.distance;
		}
	}

	static int getDistance(int x1,int y1,int x2,int y2) {
		return Math.abs(x1-x2) + Math.abs(y1 - y2);
	}

	static void attack(int x,int y) {
		List<Point> lst = new ArrayList<>();

		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(arr[i][j]==1 &&(D >= getDistance(x, y, i, j))) {
					lst.add(new Point(i,j,getDistance(x, y, i, j)));
				}

			}
		}

		//		for(Point p : lst) {
		//			System.out.println("["+p.x +" ,"+p.y+"]"+ "  D: "+ p.distance);
		//		}
		if(lst.isEmpty()) {
			return;
		}
		else {
			Collections.sort(lst);
			killed.add(lst.get(0));	//죽일 놈 추가
		}
	}
	static void kill() {
		for(Point elem : killed) {
			if(arr[elem.x][elem.y] == 1) {
				cnt++;	//점수 증가
				arr[elem.x][elem.y] = 0;
			}
			//이미 죽였다면 점수 없음
		}
		killed.clear();	//초기화
	}

	static void print() {
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				System.out.print(arr[i][j]+" ");
			}
			System.out.println();
		}
		System.out.println();
	}


	static void move() {	//적이 밑으로 내려온다.
		for(int i =N-1;i>=0;i--) {
			for(int j=0;j<M;j++) {
				if(i==0) {
					arr[i][j] = 0;
				}
				else {
					arr[i][j] = arr[i-1][j];
				}
			}
		}
	}
	static boolean check() {	//모든적이 제거되었으면 t 반환
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(arr[i][j] == 1) return false;
			}
		}
		return true;

	}

	public static void main(String[] args) throws Exception {
		/**
		 * 0. 입력파일 읽어들이기
		 */
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		st= new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());

		arr = new int[N+1][M];
		
		for(int i=0;i<N;i++) {
			st= new StringTokenizer(in.readLine());
			for(int j=0;j<M;j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		int[][] temp = new int[N+1][M];
		for(int i=0;i<arr.length;i++) {
			temp[i] = arr[i].clone();
		}
		
		for(int i=0;i<M;i++) {
			for(int j=i+1;j<M;j++) {
				for(int k= j+1;k<M;k++) {
					for(int a=0;a<temp.length;a++) {
						arr[a] = temp[a].clone();
					}
					//System.out.println(i +" : "+ j + " : "+ k);
					while(!check()) {
						//print();
						attack(N,i);
						attack(N,j);
						attack(N,k);
						kill();
						//print();
						move();
					}
					
					ans = Math.max(ans, cnt);
					cnt =0;
				}
			}
		}
	

		System.out.println(ans);

	}
}