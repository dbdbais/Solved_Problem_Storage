import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
private static StringBuilder sb = new StringBuilder();
private static StringTokenizer st;

static int dx[] = {0,1,1};	//우, 우하, 하
static int dy[] = {1,1,0};
static int curDir;	// 가로 0, 대각선 1, 세로 2
static int N,cnt;
static int [][] arr;
static boolean [][] visited;
static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
static void input() throws IOException {
	for(int i=1;i<=N;i++) {
		st = new StringTokenizer(in.readLine());
		for(int j=1;j<=N;j++) {
			arr[i][j] = Integer.parseInt(st.nextToken());
		}
	}
}

static void print() {
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			if(visited[i][j]) System.out.print("T ");
			else System.out.print("F ");
		}
		System.out.println();
	}
	System.out.println();
}

static boolean out(int x,int y) {
	return x<1 || y<1 || x>N || y >N;
}

static void DFS(int x,int y,int dir) {
//	print();
//	System.out.println("dir: "+ dir);
	if(x == N && y == N) {
//		System.out.println("found");
		cnt++;
		return;
	}
	
	if(dir == 0) {	//가로라면
		
		for(int i=0;i<=1;i++) {
			int qx = x + dx[i];
			int qy = y + dy[i];
			if(out(qx,qy)|| visited[qx][qy]||arr[qx][qy]==1) continue;	//나갔거나 방문했다면
			
			if(i == 0) {	//우로 가면
				visited[qx][qy] = true;
				DFS(qx,qy,0);
				visited[qx][qy] = false; //원복
			}
			else {	//우하로 가면
				if(arr[qx-1][qy] == 1||arr[qx][qy-1]==1) continue;	//자리 있다면
				visited[qx][qy] = true;
				DFS(qx,qy,1);
				visited[qx][qy] = false; //원복
			}
		}
	}
	else if(dir == 1) {	//대각선이라면
		for(int i=0;i<=2;i++) {
			int qx = x + dx[i];
			int qy = y + dy[i];
			if(out(qx,qy)|| visited[qx][qy]||arr[qx][qy]==1) continue;	//나갔거나 방문했다면
			
			if(i == 1) {	//우하로 가면
				if(arr[qx-1][qy] == 1||arr[qx][qy-1]==1) continue;	//자리 있다면
				visited[qx][qy] = true;
				DFS(qx,qy,dir);
				visited[qx][qy] = false; //원복	
			}
			else if(i == 0) {	//우로 가면
				visited[qx][qy] = true;
				DFS(qx,qy,0);
				visited[qx][qy] = false; //원복
			}
			else {	//하로 가면
				visited[qx][qy] = true;
				DFS(qx,qy,2);
				visited[qx][qy] = false; //원복
			}
		}	
	}
	else if(dir == 2) {
		for(int i=1;i<=2;i++) {
			int qx = x + dx[i];
			int qy = y + dy[i];
			if(out(qx,qy)|| visited[qx][qy]||arr[qx][qy]==1) continue;	//나갔거나 방문했다면
			
			if(i == 2) {	//하로 가면
				visited[qx][qy] = true;
				DFS(qx,qy,2);
				visited[qx][qy] = false; //원복
			}
			else {	//우하로 가면
				if(arr[qx-1][qy] == 1||arr[qx][qy-1]==1) continue;	//자리 있다면
				visited[qx][qy] = true;
				DFS(qx,qy,1);
				visited[qx][qy] = false; //원복
			}
		}
		
	}
	
}




public static void main(String[] args) throws Exception {
	/**
	 * 0. 입력파일 읽어들이기
	 */
	
	N = Integer.parseInt(in.readLine());
	arr = new int[N+1][N+1];
	visited = new boolean[N+1][N+1];
	
	visited[1][1] = true;
	visited[1][2] = true;
	curDir = 0;
	input();
	
	DFS(1,2,curDir);
	
	
	System.out.println(cnt);
	
	
	
	
	//print();
	

}
}