import java.util.*;
import java.io.*;

public class Main {
	static StringBuilder sb;
	static StringTokenizer st;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int N,M,K;
	static long [] tree,arr;
	static final long MOD = 1000000007;
	
	static long init(int node,int start,int end) {
		
		if(start == end) {
			return tree[node] = arr[start] % MOD;
		}
		int mid = (start+end) /2;
		
		return tree[node] = (init(node*2,start,mid) * init(node*2+1,mid+1,end)) % MOD ;
		
	}
	
	static void update(int node, int start, int end, int idx,long val) {
		
		if(idx < start || idx > end) {
			return;
		}
		
		if(start == end) {
			tree[node] = val % MOD;
			//리프노드에 값을 넣고 리턴
			return;
		}
		
		int mid = (start + end) / 2;
		update(node*2,start,mid,idx,val);
		update(node*2+1,mid+1,end,idx,val);
		
		tree[node] = (tree[node*2] * tree[node*2+1])% MOD;
		//리프노드 이후 연산 수행
		
	}
	
	static long pMul(int node,int start,int end,int left,int right) {
		
		if(left > end || right < start) return 1;
		
		if(left <= start && end <= right) {
			return tree[node];
		}
		int mid = (start + end) / 2;
		
		return (pMul(node*2, start, mid, left, right) * pMul(node*2+1, mid+1, end, left, right)) % MOD;

		
	}
	
	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		arr = new long [N+1];
		tree = new long[4*N];
		
		for(int i=1;i<=N;i++) {
			arr[i] = Integer.parseInt(in.readLine());
		}
		
		init(1,1,N);
		//트리 만들고
		
		sb = new StringBuilder();
		
		int a,b;
		long c;
		
		for(int i=0;i<M+K;i++) {
			st = new StringTokenizer(in.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Long.parseLong(st.nextToken());
			
			if(a == 1) {
				// 변경
				update(1, 1, N, b, c);
			}
			else {
				// 계산
				sb.append(pMul(1, 1, N, b, (int)c)+"\n");
			}
		}
		System.out.println(sb.toString());
		
	}
}
