import java.io.*;
import java.util.*;

/**
 * 사토리는 가로로 긴 1 * 4 블럭과, 세로로 긴 4 * 1 블럭을 쌓는 놀이를 하고 있다. 블럭이 떨어질 위치를
 * 고르면 이 블럭은 그대로 수직 방향으로 떨어진다. 떨어지는 도중 블럭의 아래쪽 면의 일부분이 다른 블럭의 윗면 또는 바닥과 닿는다면,
 * 블럭은 떨어지는 것을 멈춘다. 이때 좌우로 인접한 블럭끼리는 스쳐 지나갈 수 있다.
 * 사토리를 위해, 여러분은 다음 쿼리를 처리하는 프로그램을 작성해야 한다.
 */
public class Main {
	static StringTokenizer st;
	static StringBuilder sb;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int Q;
	//static final int diff = 1000000000;
	static HashMap<Integer,Stack<Integer>> mp;
	public static void main(String[] args) throws Exception {
		Q = Integer.parseInt(in.readLine());
		
		mp = new HashMap<>();
		sb = new StringBuilder();
		for(int i=0;i<Q;i++) {
			st = new StringTokenizer(in.readLine());
			
			int cmd = Integer.parseInt(st.nextToken());
			int num = Integer.parseInt(st.nextToken());
			
			//System.out.println(cmd + ":" + num);
			if(cmd == 1) {
				int mxHeight = 0;
				for(int j = num;j<num+4;j++) {
					if(mp.containsKey(j)) {
						int height = mp.get(j).peek();
						mxHeight = Math.max(mxHeight, height);
						
					}
				}
				for(int j = num;j<num+4;j++) {
					if(mp.containsKey(j)) {
						//위에다 그냥 넣는다.
						mp.get(j).push(mxHeight+1);
					}
					else {
						//새로운 키 매핑
						Stack<Integer> stk = new Stack<>();
						stk.push(mxHeight+1);
						mp.put(j,stk);
					}
				}
			}
			else if(cmd == 2) {
				if(mp.containsKey(num)) {
					int height = mp.get(num).peek();
					mp.get(num).push(height+4);
				}
				else {
					Stack<Integer> stk = new Stack<>();
					stk.push(4);
					mp.put(num,stk);
				}
				
			}
			else {
				if(mp.containsKey(num)) {
					sb.append(mp.get(num).peek()+"\n");
				}
				else {
					sb.append(0+"\n");
				}
				
			}
			
		}
		System.out.println(sb);
		
		
		

	}

}