import java.util.*;
import java.awt.*;
import java.io.*;


public class Main {
	static class answer implements Comparable<answer>{
		int no;
		int depth;
		
		public answer(int no,int depth) {
			this.no = no;
			this.depth = depth;
		}
		
		public int compareTo(answer o) {
			return Integer.compare(depth,o.depth);
		}

		@Override
		public String toString() {
			return "answer [no=" + no + ", depth=" + depth + "]";
		}
		
		
	}
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int ans = Integer.MAX_VALUE;
	static ArrayList<Integer>[] adj;
	static boolean [] visited;
	static ArrayList<answer> avec = new ArrayList<>();
	static int N,a,b,cnt;
	
	
	static void solve() {
		Queue<Point> q = new ArrayDeque<>();
		for(int i=1;i<=N;i++) {
			Arrays.fill(visited, false);
			visited[i] = true;
			q.add(new Point(i,0));
			int fdpt = 0;
			//첫 시작점 넣는다.
			
			while(!q.isEmpty()) {
				Point cur = q.poll();
				int x = cur.x;
				int dpt = cur.y;
				if(fdpt < dpt) fdpt = dpt;
				for(int ad : adj[x]) {
					if(visited[ad]) continue;
					q.add(new Point(ad,dpt+1));
					visited[ad] = true;
				}
			}
			ans = Math.min(ans, fdpt);
			
			avec.add(new answer(i,fdpt));
		}
		
		System.out.print(ans+" ");
		
		for(answer a : avec) {
			if(a.depth == ans) {
				cnt++;
				sb.append(a.no+" ");
			}
		}
		System.out.println(cnt);
		
		System.out.println(sb);
		
	}
	
	public static void main(String[] args) throws IOException {
		N = Integer.parseInt(in.readLine());
		
		adj = new ArrayList[N+1];
		visited = new boolean[N+1];
		
		for(int i=1;i<=N;i++) {
			adj[i] = new ArrayList<>();
		}
		
		
		while(true) {
			st = new StringTokenizer(in.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			if(a == -1 && b == -1) break;
			
			adj[a].add(b);
			adj[b].add(a);
		}
		
		solve();
		
		/*
		for(int i=1;i<=N;i++) {
			System.out.print(i+" : ");
			for(int elem : adj[i]) {
				System.out.print(elem +" ");
			}
			System.out.println();
		}
		*/
		
	}
}