import java.util.*;
import java.io.*;

public class Main {
	static StringBuilder sb;
	static StringTokenizer st;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int N,M;
	static int[] arr,tree;
	
	static int init(int node, int start, int end) {
		if(start == end) {
			return tree[node] = arr[start];
		}
		int mid = (start + end) / 2;
		
		return tree[node] = Math.min (init(node*2,start,mid),init(node*2+1,mid+1,end));
	}
	
	static int search(int node,int start, int end,int left,int right) {
		
		if(left > end || right < start) return Integer.MAX_VALUE;
		
		if(left <= start && end <= right) {
			return tree[node];
		}
		
		int mid = (start + end) / 2;
		
		return Math.min(search(node*2, start, mid, left, right), search(node*2+1, mid+1, end, left, right));
		
	}
	
	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		arr = new int[N+1];
		tree = new int[4*N];
		
		for(int i=1;i<=N;i++) {
			arr[i] = Integer.parseInt(in.readLine());
		}
		
		int a,b;
		
		init(1,1,N);
		//Tree로 변환
		sb = new StringBuilder();
		
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(in.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			
			sb.append(search(1, 1, N, a, b)+"\n");
		}
		
		System.out.println(sb.toString());
		
	}
}
