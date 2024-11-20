import java.util.*;
import java.awt.*;
import java.io.*;

public class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N,V;
	static int[] arr;
	static int ans = Integer.MAX_VALUE;
	
	static void DFS(int idx,int cnt,int mn,int mx) {
		
		if(idx > N) return;
		if(ans <= cnt) return;
		
		mx =Math.max(arr[idx], mx);
		mn = Math.min(arr[idx], mn);
		
		if(mx -mn >= V) {
			ans = Math.min(ans,cnt);
		}
		DFS(idx+1,cnt+1,mn,mx);
		DFS(idx+2,cnt+1,mn,mx);
		
	}
	
	public static void main(String[] args) throws Exception {
		
		st = new StringTokenizer(in.readLine());
		
		N = Integer.parseInt(st.nextToken());
		V = Integer.parseInt(st.nextToken());
		
		
		arr = new int[N+1];
		
		st = new StringTokenizer(in.readLine());
		int tmx = 0;
		int tmn = Integer.MAX_VALUE;
		for(int i=1;i<=N;i++) {
			arr[i] = Integer.parseInt(st.nextToken());
			if(tmx < arr[i]) tmx = arr[i];
			if(tmn > arr[i] ) tmn = arr[i];
		}
		if(tmx -tmn >= V) {
			DFS(1,1,Integer.MAX_VALUE,0);
		}
		else {
			ans = N;
		}

		System.out.println(ans);
	}
}