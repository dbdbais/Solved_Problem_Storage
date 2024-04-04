import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int ans = Integer.MAX_VALUE;
	static int [][] paper = new int[10][10];
	static ArrayList<Point> cord = new ArrayList<>();
	static int [] paperCnt = new int[6];
	static boolean out(int x,int y) {
		return x <0 || y <0 || x >= 10 || y >= 10;
	}
	static void print() {
		for(int i=0;i<10;i++) {
			for(int j=0;j<10;j++) {
				System.out.print(paper[i][j] +" ");
			}
			System.out.println();
		}
	}
	
	static boolean check() {
		for(int i=0;i<10;i++) {
			for(int j=0;j<10;j++) {
				if(paper[i][j] == 1) return false;
			}
		}
		return true;
	}
	
	static boolean cover(int x,int y, int n) {
		for(int i= x;i<x+n;i++) {
			for(int j=y;j<y+n;j++) {
				if(out(i,j) || paper[i][j] != 1) return false;
			}
		}
		
		for(int i= x;i<x+n;i++) {
			for(int j=y;j<y+n;j++) {
				paper[i][j] = 0;
			}
		}
		return true;
	}
	
	static void uncover(int x,int y, int n) {
		for(int i= x;i<x+n;i++) {
			for(int j=y;j<y+n;j++) {
				paper[i][j] = 1;
			}
		}
	}
	
	static int paperUse() {
		int sm =0;
		for(int i=1;i<=5;i++) {
			sm += (5 - paperCnt[i]);
		}
		return sm;
		
	}
	
	static void DFS(int cnt) {	
		//System.out.println("cnt : "+cnt);
		//print();
		if(cnt == cord.size() ){	//맨 마지막 도달 시 다른 경우 찾아 떠남
			if(check()) {	//모든 경우가 꺼졌다면
				//System.out.println("갱신");
				ans = Math.min(ans,paperUse()); //최소값 갱신
			}
			return;
		}
		Point cur = cord.get(cnt);	//현재 위치의 좌표 꺼내온다.
		int x = cur.x;
		int y = cur.y;
		
		if(paper[x][y] == 0) {
			DFS(cnt+1);
		}
		
		
	
		for(int i=5;i>=1;i--) {
			if(paperCnt[i] == 0) continue;	//색종이가 없다면
			if(cover(x,y,i)) {	//색종이로 커버 가능하다면
				paperCnt[i]--;
				DFS(cnt+1);
				paperCnt[i]++;
				uncover(x, y, i);	//원복
			}
		}
	}
	

	
	public static void main(String[] args) throws IOException {
		
		for(int i=1;i<=5;i++) {
			paperCnt[i] = 5;
		}
		
		for(int i=0;i<10;i++) {
			st = new StringTokenizer(in.readLine());
			for(int j=0;j<10;j++) {
				paper[i][j] = Integer.parseInt(st.nextToken());
				
				if(paper[i][j] == 1) {	//1로 표시된 좌표 전부 집어넣는다.
					cord.add(new Point(i,j));
				}
			}
		}
		DFS(0);
		if(ans == Integer.MAX_VALUE) ans = -1;
		System.out.println(ans);
	}

}