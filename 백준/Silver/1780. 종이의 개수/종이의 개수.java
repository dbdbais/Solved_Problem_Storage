import java.io.*;
import java.util.*;
import java.awt.*;

class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuffer sb = new StringBuffer();
	static int N,zero,mone,one;
	static int[][] arr;
	
	static void input() throws IOException {
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(in.readLine());
			for(int j=0;j<N;j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
	}
	
	static boolean check(int x,int y,int n) {
		int elem = arr[x][y];
		for(int i= x;i< x + n;i++) {
			for(int j=y;j<y+n;j++) {
				if(elem != arr[i][j]) return false;
			}
		}
		return true;
	}
	static void inc(int val) {
		if(val == -1) {
			mone++;
		}
		else if(val == 0) {
			zero++;
		}
		else {
			one++;
		}
	}
	static void output() {
		System.out.println(mone);
		System.out.println(zero);
		System.out.println(one);
	}
	
	static void solve(int x,int y,int n) {
		if(check(x,y,n)) {
			//System.out.println(x+" "+y+" "+n+" :done");
			inc(arr[x][y]);

			return;
		}
		else {
			for(int i=0;i<n;i+=n/3) {
				for(int j=0;j<n;j+= n/3) {
					//System.out.println((x+i)+", "+ (y+j));
					solve(x+i,y+j,n/3);
				}
			}
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		
		N = Integer.parseInt(in.readLine());
		arr = new int[N][N];
		input();
		solve(0,0,N);
		output();
	
	}
}