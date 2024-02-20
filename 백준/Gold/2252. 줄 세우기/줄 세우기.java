import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;


public class Main {
private static StringBuilder sb = new StringBuilder();
private static StringTokenizer st;
static int N,M;
static ArrayList<Integer> [] list;
static int[] cnt = new int[32001];
public static void main(String[] args) throws Exception {
	/**
	 * 0. 입력파일 읽어들이기
	 */
	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	st= new StringTokenizer(in.readLine());
	N = Integer.parseInt(st.nextToken());
	M = Integer.parseInt(st.nextToken());
	int a,b;
	list = new ArrayList[N+1];
	for(int i=0;i<=N;i++) {
		list[i] = new ArrayList<>();
	}
	for(int i=0;i<M;i++) {
		st= new StringTokenizer(in.readLine());
		a = Integer.parseInt(st.nextToken());
		b = Integer.parseInt(st.nextToken());
		list[a].add(b);
		cnt[b]++;
	}
	Queue<Integer> q = new ArrayDeque<>();
	
	while(q.size() != N) {
		for(int i=1;i<=N;i++) {
			if(cnt[i] == 0) {
				q.add(i);
				for(int adj : list[i]) {
					cnt[adj]--;	//감소
				}
				cnt[i]= -1;
			}
		}
		
	}
	while(!q.isEmpty()) {
		System.out.print(q.poll()+" ");
	}
	
}
}