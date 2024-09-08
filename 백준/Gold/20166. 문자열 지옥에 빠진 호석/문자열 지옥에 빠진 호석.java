import java.io.*;
import java.util.*;

import javax.security.sasl.SaslException;

class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	
	static int N, M, K;

	static char[][] arr;
	static String[] ipt;
	static int[] count;
	static final int[] dx = {0,0,-1,1,1,1,-1,-1};
	static final int[] dy = {-1,1,0,0,1,-1,1,-1};
	static HashMap<String,Integer> mp;
	
	static void DFS(int x,int y,int cnt,int idx) {
		int sz = ipt[idx].length()-1;
		//최대 갈 수 있는 길이
		if(cnt > sz) {
			return;
		}
		//끊어 버린다.
		char exp = ipt[idx].charAt(cnt);
		//지금 나와야 할 단어
		char cur = arr[x][y];
		//일치한다면
		if(exp == cur) {
			if(cnt == sz) {
				//마지막이라면
				count[idx]++;
				//방법을 하나 찾았으므로 증가시킨다.
			}
			else {
				//마지막은 아니므로 다음 탐색하러 떠난다.
				for(int i=0;i<8;i++) {
					int qx = ((x - 1 + dx[i] + N) % N) + 1;
					int qy = ((y - 1 + dy[i] + M) % M) + 1;
					//좌표 제한
					
					DFS(qx,qy,cnt+1,idx);
					//다음 탐색 시작
				}
				
			}
			
			return;
		}
		else {
			return;
		}
		
		
	}

	static void solve(int idx) {

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				DFS(i,j,0,idx);
				//까본다
			}
		}
		mp.put(ipt[idx],count[idx]);
		//매핑한다.
		sb.append(count[idx] + "\n");
		
	}

	public static void main(String[] args) throws IOException {

		st = new StringTokenizer(in.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		mp = new HashMap<>();
		arr = new char[N + 1][M + 1];
		ipt = new String[K];
		count = new int[K];
		for (int i = 1; i <= N; i++) {
			String s = in.readLine();
			for (int j = 1; j <= M; j++) {
				arr[i][j] = s.charAt(j - 1);
			}
		}
		for (int i = 0; i < K; i++) {
			ipt[i] = in.readLine();
		}
		
		for (int i = 0; i < K; i++) {
			if(mp.containsKey(ipt[i])) continue;
			solve(i);
			//해당하는 문자열 개수 찾으러 떠난다.
		}
		System.out.println(sb);

	}

}