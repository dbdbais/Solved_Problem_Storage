import java.io.*;
import java.util.*;

/**
 * 자료구조는 정말 최고야
 * 스택을 배운 뒤, 사랑에 빠짐
 * N권의 교과서를 방 구석에 M개의 더미로 아무렇게나 쌓아 두었다.
 * 중간고사가 다가오자 나머지 교과서를 정리하고 번호순으로 나열한다.
 * 1..N까지의 번호가 메겨져 있다. 찬우는 각 더미의 맨 위에 있는 교과서만 꺼낼 수 이씅며 순서대로 나열하기 때문에 1 ~ N 순으로 꺼낸다. 
 */
public class Main {
	static StringTokenizer st;
	static StringBuilder sb;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static Stack<Integer> [] stks;
	static HashMap<Integer,Integer> stkTop;
	//현재 번호가 몇번에 있는지
	static int N, M, nxt, k;
	
	static boolean canGo(int num) {
		
		if(stkTop.containsKey(num)) {
			//num이란게 Top에 있다면
			int idx = stkTop.get(num);
			//스택 인덱스 빼서
			stks[idx].pop();
			
			if(!stks[idx].isEmpty()) {
				int nxtTop = stks[idx].peek();
				
				stkTop.remove(num);
				//현재 꺼 지워줌
				stkTop.put(nxtTop, idx);
				//새로운 인덱스 넣어준다.
			}
			
			return true;
		}
		else {
			return false;
		}

	}
	
	static void print() {
		for(int i=0;i<M;i++) {
			for(int elem : stks[i]) {
				System.out.print(elem +" ");
			}
			System.out.println();
		}
	
	}

	public static void main(String[] args) throws Exception {
		
		st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		stks = new Stack[M];
		stkTop = new HashMap<>();
		
		for(int i=0;i<M;i++) {
			k = Integer.parseInt(in.readLine());
			st = new StringTokenizer(in.readLine());
			stks[i] = new Stack<>();
			for(int j=0;j<k;j++) {
				int elem = Integer.parseInt(st.nextToken());
				stks[i].add(elem);
				if(j == k-1) {
					//맨 위라면
					stkTop.put(elem,i);
					//매핑
				}
			}
		}
		sb = new StringBuilder();
		
		int nxt = 1;
		boolean fail = false;
		//print();
		while(N-- > 0) {
			if(!canGo(nxt++)) {
				//갈 수 없다면
				fail = true;
				break;
			}
			//print();
		
		}
		
		if(fail) {
			sb.append("No");
		}
		else {
			sb.append("Yes");
		}
		
		System.out.println(sb);

	}

}