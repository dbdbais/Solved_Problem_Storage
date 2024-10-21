import java.io.*;
import java.util.*;

/**
 * 주원이는 방탈 출 중 미로에 도착했다. 미로는 일렬로 놓인 N개의 방으로 이루어져 있으며, i번 방과 i + 1번 방은 서로 인접해 있다.
 * 또한, 각 방에 스위가 하나씩 있어, 주원이는 입구가 있는 S번 방에서 출발하여 모든 스위치를 누루고 출구가 있는 방으로 탈출해야한다.
 * 2가지 방법 사용가능 => 0만큼의 비용을 소모해 인접한 방으로 이동 or 1만큼의 비용을 소모해 1번 또는 N번 방으로 순간이동
 * 두 이동 방법 매번 1만큼 소모된다. 시위치를 누르는건 0만큼의 시간이 소요
 * 방 탈출에서 탈출하기 위해선 시간 관리를 잘 해야 하므로 최대한 빠르게 미로를 탈출하는 방법을 찾으러 한다. 
 */
public class Main {
	static StringTokenizer st;
	static StringBuilder sb;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int T,N,S,E;

	public static void main(String[] args) throws Exception {
		T = Integer.parseInt(in.readLine());
		sb = new StringBuilder();
		for(int i =0;i<T;i++) {
			st =new StringTokenizer(in.readLine());
			N = Integer.parseInt(st.nextToken());
			S = Integer.parseInt(st.nextToken());
			E = Integer.parseInt(st.nextToken());
			
			if( (S == 1 && E == N) || (S == N && E == 1)) {
				sb.append(0+"\n");
				//시작과 끝 or 끝과 시작에 위치한다면
			}
			else if(1 < S && S < N) {
				//시작이 중간에 있을 경우
				if(Math.abs(E-S) == 1) {
					//바로 앞뒤에 있는 경우
					sb.append(1+"\n");
				}
				else {
					//S와 E 사이에 어떤 숫자가 있다면 순간이동을 한번 더해야함
					sb.append(2+"\n");
				}
			}
			else {
				//시작이 1 아니면 N에 있는 경우 무조건 한번의 순간이동 필요
				sb.append(1+"\n");
			}
			
		}
		System.out.println(sb);
		

	}

}