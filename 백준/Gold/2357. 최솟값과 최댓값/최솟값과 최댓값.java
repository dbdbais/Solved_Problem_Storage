import java.util.*;
import java.io.*;

public class Main {
	static StringBuilder sb;
	static StringTokenizer st;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int N,M;
	
	static int [] arr;
	static int [] mxTree;
	static int [] mnTree;
	
	static int mnInit(int node,int start, int end) {
		if(start == end) {
			return mnTree[node] = arr[start];
		}
		int mid = (start+end)/2;
		return mnTree[node] = Math.min(mnInit(node*2, start, mid), mnInit(node*2+1, mid+1, end));
		
	}
	static int mxInit(int node,int start, int end) {
		if(start == end) {
			return mxTree[node] = arr[start];
		}
		int mid = (start+end)/2;
		return mxTree[node] = Math.max(mxInit(node*2, start, mid), mxInit(node*2+1, mid+1, end));
		
	}
	
	static int mnFind(int start,int end, int node, int left, int right) {
		
		if(right < start || left > end) {
			return Integer.MAX_VALUE;
		}
		
		if(left <= start && end <= right) {
			//범위가 완전히 겹친다면
			return mnTree[node];
		}
		int mid = (start + end) / 2;
		
		// 아니라면 구간 별
		return Math.min(mnFind(start, mid, node*2, left, right), mnFind(mid+1, end, node*2+1, left, right));
	}
	
	static int mxFind(int start,int end, int node, int left, int right) {
		
		if(right < start || left > end) {
			return Integer.MIN_VALUE;
		}
		
		if(left <= start && end <= right) {
			return mxTree[node];
			//범위가 완전히 겹친다면
		}
		int mid = (start + end) / 2;
		// 아니라면 구간 별
		return Math.max(mxFind(start, mid, node*2, left, right), mxFind(mid+1, end, node*2+1, left, right));
	}
	
	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(in.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		arr = new int[N+1];
		mxTree = new int[4*N];
		mnTree = new int[4*N];
		
		for(int i=1;i<=N;i++) {
			arr[i] = Integer.parseInt(in.readLine());
		}
		
		mxInit(1, 1, N);
		mnInit(1, 1, N);
		//최대 세그, 최소 세그 구성
		
		sb = new StringBuilder();
		
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(in.readLine());
			int a,b;
			
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			
			sb.append(mnFind(1, N, 1, a, b)+" ");
			sb.append(mxFind(1, N, 1, a, b)+"\n");
		}
		
		System.out.println(sb.toString());
		
		

	}
}
