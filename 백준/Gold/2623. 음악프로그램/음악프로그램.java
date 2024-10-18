import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N, M;
	static boolean cycle;
	static int[] cnt;
	static boolean[] visited;
	static ArrayList<Integer>[] lst;
	static StringBuilder sb;

	static boolean isCycle(int num, int target) {
		boolean ret = false;
		// System.out.println(num+":"+ target);
		for (int adj : lst[num]) {
			if (visited[adj])
				continue;
			// 이미 방문한 곳이라면 컨티뉴
			if (adj == target) {
				ret = true;
				break;
			} else {
				visited[adj] = true;
				if (isCycle(adj, target)) {
					ret = true;
					break;
				}
				visited[adj] = false;
			}
		}
		return ret;
	}

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		lst = new ArrayList[N + 1];

		for (int i = 1; i <= N; i++) {
			lst[i] = new ArrayList<>();
		}

		cnt = new int[N + 1];
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(in.readLine());
			int num = Integer.parseInt(st.nextToken());
			int prev = Integer.parseInt(st.nextToken());
			for (int j = 0; j <= num - 2; j++) {
				int cur = Integer.parseInt(st.nextToken());
				lst[prev].add(cur);
				// 내가 바라보는 노드 추가
				cnt[cur]++;

				// 차수 늘려주고
				prev = cur;
			}

		}

//		for(int i=1;i<=N;i++) {
//			visited = new boolean[N+1];
//			//할때마다 초기화
//			//System.out.println("cycle check:"+i);
//			if(isCycle(i, i)) {
//				cycle = true;
//				break;
//			}
//	
//		}

		// System.out.println(cycle);

//		for(int i=1;i<=N;i++) {
//			System.out.println(i + ":" + cnt[i]);
//		}

		Queue<Integer> q = new ArrayDeque<>();

		sb = new StringBuilder();
		ArrayList<Integer> ansLst = new ArrayList<>();
		for(int i=1;i<=N;i++) {
			if(cnt[i] == 0) q.add(i);
		}
		
		while (!q.isEmpty()) {
			int zero = q.poll();
			
			ansLst.add(zero);
			
			for(int adj : lst[zero]) {
				cnt[adj]--;
				if(cnt[adj] == 0) q.add(adj);
			}
		}
		if(ansLst.size()!= N) {
			sb.append(0);
		}
		else {
			for(int elem : ansLst) {
				sb.append(elem+"\n");
			}
		}

		System.out.println(sb);


	}

}