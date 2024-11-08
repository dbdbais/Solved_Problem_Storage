import java.util.*;
import java.io.*;
import java.awt.*;
class Main {
	
	static StringTokenizer st;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int N,M,len;
	static String ans;
	static StringBuilder sb;
	static char [][] arr;
	static boolean found;
	
	static final int[] dx = {0,0,-1,1,1,1,-1,-1};
	static final int[] dy = {-1,1,0,0,1,-1,1,-1};
	
	static class Cord{
		int x;
		int y;
		int dir;
		int cnt;
	}
	static boolean out(int x,int y) {
		return x < 0 || y <0 || x >= N || y >=M;
	}
	static void DFS(int x,int y,int dir,String sts) {
		if(found) return;
		
		if(sts.length() == len) {
			StringBuilder sb = new StringBuilder(sts);
		
			if(ans.equals(sb.toString()) || ans.equals(sb.reverse().toString())) {
				//System.out.println(sb.toString());
				found = true;
			}
			return;
		}
		
		int qx = x + dx[dir];
		int qy = y + dy[dir];
		
		if(out(qx,qy)) return;
		DFS(qx,qy,dir,sts+arr[qx][qy]);
		
		return;
		
	} 
	
	public static void main(String[] args) throws Exception {
		ans = in.readLine();
		st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		arr = new char[N][M];
		
		for(int i=0;i<N;i++) {
			String s = in.readLine();
			for(int j=0;j<M;j++) {
				arr[i][j] = s.charAt(j);
			}
		}
		len = ans.length();
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				//System.out.println(i+":"+j);
				StringBuilder sb = new StringBuilder();
				sb.append(arr[i][j]);
				for(int k=0;k<8;k++) {
					DFS(i,j,k,sb.toString());
					if(found) break;
				}
				if(found) break;
			}
			if(found) break;
			//System.out.println();
		}
		if(found) {
			System.out.println(1);
		}
		else {
			System.out.println(0);
		}
		
	}
}