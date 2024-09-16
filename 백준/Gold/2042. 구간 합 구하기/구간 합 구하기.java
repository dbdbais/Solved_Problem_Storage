import java.io.*;
import java.util.*;


class Main {
	
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N,M,K,tHeight,len,tSize;
	static long[] tree;
	static StringBuilder sb = new StringBuilder();
	
	static void setTree(int idx) {
		while(idx != 1) {
			tree[idx/2] += tree[idx];
			idx--;
		}
		//누적합 계산해버림
	}
	
	static void print() {
		System.out.println("================");
		for(int i=0;i<=tSize;i++) {
			System.out.print(i+" ");
		}
		System.out.println();
		for(int i=0;i<=tSize;i++) {
			System.out.print(tree[i]+" ");
		}
		System.out.println();
		System.out.println("================");
	}
	
	private static void change(int idx, long val) {
		//System.out.println("cIdx : "+idx);
		long diff = val - tree[idx];
		//이전에 비해 바뀌는 값
		while(idx >0 ) {
			tree[idx] = tree[idx] + diff ;
			idx/= 2;
			//위로 타고가면서 해당하는 값들만 수정
		}
	}
	

	private static long getPartialSum(int start, int end) {
		
		long partSum =0;
		
		while(start<= end) {
			if(start % 2 == 1) {
				//오른쪽 자식
				//상위 부모 노드의 부분합에 포함되어 있지 않을 경우
				partSum = partSum + tree[start];
				start++;
				//이후 부모로 이동
			}
			
			if(end % 2 == 0) {
				//왼쪽 자식
				//상위 부모 노드의 부분합에 포함되어 있지 않을 경우
				partSum = partSum + tree[end];
				end--;
				//이전 부모로 이동
			}
			
			start /= 2;
			end /= 2;
		}
		return partSum;
	}

	
	public static void main(String[] args) throws IOException {
		
		st = new StringTokenizer(in.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		len = N;
		
		while(len != 0) {
			len /=2;
			tHeight++;
			//2로 나눠가며 tHeight 승할 지 구함
		}
		
		tSize =  (int) Math.pow(2, tHeight+1);
		int sIdx = tSize / 2 -1 ; //리프노드 보정 인덱스
		
		tree = new long[tSize+1];
		//전체 트리 할당
		
		for(int i=sIdx+1;i<=sIdx+N;i++) {
			tree[i] = Long.parseLong(in.readLine());
		}
		//자식 노드 전부 입력한다.
		
		setTree(tSize-1);
		//세그먼트 트리로 구성한다.
		
		
		
		long a,b,c;
		//print();
		for(int i=0;i<M+K;i++) {
			st = new StringTokenizer(in.readLine());
			a = Long.parseLong(st.nextToken());
			b = Long.parseLong(st.nextToken());
			c = Long.parseLong(st.nextToken());
			
			if(a == 1) {
				change(sIdx+(int)b ,c);
			}
			else if (a == 2) {
				int start = (int) (b + sIdx);
				int end = (int) (c + sIdx);
				sb.append(getPartialSum(start, end)+"\n");
			}

			//print();
		}
		System.out.println(sb.toString());
	}



	

}