import java.util.*;
import java.io.*;

public class Main {
	
	static StringTokenizer st;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int height, N,M,K, tree_size;
	static StringBuilder sb;
	static long[] tree;
	static long[] arr;
	static long[] lazy;
	//지연 갱신 표시 할 배열
	
	static int getTreeSize(int n) {
		// 로그 기반으로 트리 높이를 계산하고, 필요한 노드 수를 2^(h+1)-1 로 구함
		int h = (int)Math.ceil(Math.log(n)/Math.log(2))+1;
		return (int)Math.pow(2, h)-1;
	}
	
	static long init(int node,int start, int end) {
		if(start == end) {
			//  리프 노드에 해당하는 경우 : 실제 배열 값 그대로 저장
			return tree[node] = arr[start];
		}
		else {
			//리프 노드가 아닌 경우: 왼쪽 자식과 오른쪽 자식을 재귀적으로 저장
			int mid = (start + end)/2;
			
			return tree[node]=  init(node*2,start,mid) + init(node*2+1,mid+1,end);
			// 좌 우 서브트리 값을 저장
		}
	}
	
	static void propagate(int node,int start, int end) {
		if(lazy[node] != 0) {
			int childNode = end - start +1;
			tree[node] += childNode * lazy[node];
			if(start != end) {
				lazy[node*2] += lazy[node];
				lazy[node*2 +1] += lazy[node];
				// 왼쪽, 오른 쪽 자식 노드에게 전파
			}
			lazy[node] = 0;
			//지연 노드 초기화
		}
	}
	
	static void rangeUpdate(int node, int start,int end, int left, int right,long val) {
		//구간 left 부터 right 까지 val만큼 더하는 update
		propagate(node, start, end);
		// 업데이트 전에  이전 lazy 반영
		
		if(right < start || end <left) return;
		
		if(left <= start && end <= right) {
			//완전히 겹치는 경우
			lazy[node] += val;
			propagate(node, start, end);
			return;
		}
		int mid = (start + end) / 2;
		rangeUpdate(node*2, start, mid, left, right, val);
		// 왼쪽 자식 갱신
		rangeUpdate(node*2+1, mid+1, end, left, right, val);
		// 오른쪽 자식 갱신
		tree[node] = tree[node*2] + tree[node*2+1];
		//지연갱신 작업이 끝나고 자식들의 값으로 부모 노드 다시 갱신
		
		
	}
	
	static long rangeSum(int node, int start, int end, int left, int right) {
		
		propagate(node, start, end);
		// 구간 [l, r] 합을 조회
		if(left > end || right < start) return 0;
		// 범위 벗어나면 이런식으로...
		
		// 현재 노드의 구간이 쿼리 구간에 완전히 포함되는 경우
		if(left <= start && end <= right) {
			return tree[node];
			// 정확히 범위 안에 있다면
		}
		
		// 그 외의 경우: 구간이 일부만 겹치는 경우 -> 좌우 자식 노드를 탐색
		int mid = (start+end) / 2;
		
		long lsum = rangeSum(node*2, start, mid, left, right);	// 왼쪽 자식 노드 부분 합
		long rsum = rangeSum(node*2+1, mid+1, end ,left, right);	// 오른쪽 자식 노드 부분 합
		
		return  lsum + rsum;
	}
	
	static void update(int start, int end, int node, int idx, long diff) {
		//idx는 0부터 시작
		if(start <= idx && idx <= end) {
			tree[node] += diff;
			//아래로 내려 가면서 하나씩 편차를 더함
		}
		else return;
		
		if(start == end) return;
		//리프 노드일 경우 더이상 내려갈 필요가 없음
		
		int mid = (start + end) / 2;
		update(start,mid,node*2,idx,diff);
		update(mid+1,end,node*2+1,idx,diff);
		
	}
	
	static void printTree() {
	    System.out.println("== 현재 트리 상태 ==");
	    for (int i = 1; i < tree.length; i++) {
	        System.out.println("node[" + i + "] = " + tree[i]);
	    }
	    System.out.println("===================");
	}
	
	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		sb = new StringBuilder();
		
		arr = new long[N+1];
		tree_size = getTreeSize(N);
		// 트리 사이즈 계싼
		tree = new long[tree_size+1];
		lazy = new long[tree_size+1];
		
		
		for(int i=1;i<=N;i++) {
			arr[i] = Long.parseLong(in.readLine());
		}
		init(1, 1, N);
		//printTree();
		
		int idx =0;
		while(idx < M+K ) {
			st = new StringTokenizer(in.readLine());
			long a,b,c,d;
			
			a = Long.parseLong(st.nextToken());
			b = Long.parseLong(st.nextToken());
			c = Long.parseLong(st.nextToken());
			
			
			if(a==1) {
				// 구간 업데이트
				// 바꾸고
				d = Long.parseLong(st.nextToken());
				//long diff = c - arr[(int)b];
				//System.out.println(b +"번째 : "+ arr[b] + ":" + diff);
				//update(1, N, 1, (int)b, diff);
				//arr[(int)b] +=diff;
				//System.out.println(b +"번째 : "+ arr[b]);
				rangeUpdate(1, 1, N,(int)b, (int)c, d);
			}
			else{
				// b에서 c번째 수의 합을 구하여 출력
				sb.append(rangeSum(1, 1, N,(int)b,(int)c)+"\n");
			}
			
			idx++;
			//System.out.println("idx : "+idx);
			//printTree();
		}
		
		System.out.println(sb.toString());
		
	}
}
