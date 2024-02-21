import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	private static StringBuilder sb = new StringBuilder();
	private static StringTokenizer st;
	static boolean ans = false;
	static int N,M;
	static ArrayList<Integer> relation[];
	//static boolean[][] relation;
	static boolean[] found; 


	static void search(int idx,int cnt) {

		if(ans) return;

		if(cnt==4) {
			ans = true;
			return;
		}
		
		for( int i : relation[idx]) {
			if(found[i]) continue;
			
			found[i] = true;
			search(i,cnt+1);
			found[i] = false;
		}
	}


	static void solve() {
	
		for(int i=0;i<N;i++) {
			found = new boolean[N];
			found[i] = true;
			search(i,0);
			if(ans) break;
		}

	}

	public static void main(String[] args) throws Exception {
		/**
		 * 0. 입력파일 읽어들이기
		 */
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		st = new StringTokenizer(in.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		relation = new ArrayList[N];
		for (int i=0; i<N; i++) {
			relation[i] = new ArrayList<Integer>();
		}

		int a,b;
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(in.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			relation[a].add(b);
			relation[b].add(a);
		}
		//print();

		solve();

		if(ans) {
			System.out.println(1);
		}
		else {
			System.out.println(0);
		}



	}
}