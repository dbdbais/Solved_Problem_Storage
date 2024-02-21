import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main{
	
	static StringTokenizer st;
	static int N;
	static int[][] arr;
	static String ans="";
	
	static boolean check(int x,int y,int n) {
		int val = arr[x][y];
		
		for(int i=x;i<x+n;i++) {
			for(int j= y;j<y+n;j++) {
				if(val != arr[i][j]) return false;
			}
		}
		return true;
	}
	
	static void DFS(int x,int y,int n) {
		if(n == 1) {
			ans += arr[x][y];
			return;
		}

		if(check(x,y,n)) {
			ans+= arr[x][y];
		}
		else {
			ans += "(";
			DFS(x,y,n/2);
			DFS(x,y+n/2,n/2);
			DFS(x+n/2,y,n/2);
			DFS(x+n/2,y+n/2,n/2);
			ans += ")";
		}
	
	}
	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(in.readLine());
		arr = new int[N][N];	//할당
		String s;
		for(int i=0;i<N;i++) {
			s = in.readLine();
			char[] c = s.toCharArray();
			for(int j=0;j<N;j++) {
				arr[i][j] = c[j]-'0';
			}
		}
		
//		for(int i=0;i<N;i++) {
//			for(int j=0;j<N;j++) {
//				System.out.print(arr[i][j] +" ");
//			}
//			System.out.println();
//		}
		DFS(0,0,N);
		
		System.out.println(ans);
		
		
	}

}
