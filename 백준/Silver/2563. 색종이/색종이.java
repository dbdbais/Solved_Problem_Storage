import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	private static StringBuilder sb = new StringBuilder();
	private static StringTokenizer st;
	
	static int N;
	static boolean [][] arr = new boolean[100][100];
	
	
	
	static void black(int x,int y) {
		for(int i=x;i<x+10;i++) {
			for(int j=y;j<y+10;j++) {
			arr[i][j] = true;	
			}
		}
	}
	
	static int check() {
		int sm = 0;
		for(int i=0;i<100;i++) {
			for(int j=0;j<100;j++) {
				if(arr[i][j]) sm++;
			}
		}
		return sm;
	}
	
	public static void main(String[] args) throws Exception {
		/**
		 * 0. 입력파일 읽어들이기
		 */
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		N = Integer.parseInt(in.readLine());
		int a,b;
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(in.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			black(a,b);
		}
		
		System.out.println(check());
	}
}