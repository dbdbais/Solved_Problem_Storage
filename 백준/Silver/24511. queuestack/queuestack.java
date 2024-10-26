import java.io.*;
import java.util.*;

/**
 * 첫째 줄에 queuestack을 구성하는 자료구조 개수 N
 * N의 타입이 주어진다. 0 이면 스택 1이면 큐
 * 셋째 줄 i번 자료구조에 들어있는 원소
 * 삽입할 수열의 길이 M
 * M개의 C가 주어진다.
 */
public class Main {
	static StringTokenizer st;
	static StringBuilder sb;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int N,M;
	static Deque<Integer> dq;
	static boolean [] isStack;
	//현재 번호가 몇번에 있는지ㄴ

	public static void main(String[] args) throws Exception {

		N = Integer.parseInt(in.readLine());
		sb = new StringBuilder();
		
		isStack = new boolean[N];
		st = new StringTokenizer(in.readLine());
		for(int i=0;i<N;i++) {
			if(Integer.parseInt(st.nextToken()) == 1) {
				isStack[i] = true;
			}
		}
		dq = new ArrayDeque<>();
		
		st = new StringTokenizer(in.readLine());
		int cnt =0;
		for(int i=0;i<N;i++) {
			int elem = Integer.parseInt(st.nextToken());
			if(!isStack[i]) {
				dq.addLast(elem);
			}
		}
		
		M = Integer.parseInt(in.readLine());
		st = new StringTokenizer(in.readLine());
		for(int i=0;i<M;i++) {
			int elem = Integer.parseInt(st.nextToken());
			dq.addFirst(elem);
			sb.append(dq.pollLast()+" ");
			
		}
		
		System.out.println(sb);
		

	}

}