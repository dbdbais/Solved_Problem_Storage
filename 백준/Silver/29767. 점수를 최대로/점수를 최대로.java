import java.util.*;
import java.io.*;

public class Main {
	
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N,K;
	static long [] arr;
	static long [] psum;
	static long ans;
	static boolean [] checked;
	
	static class Dummy implements Comparable<Dummy>{
		int index;
		long val;
		
		public Dummy(int index, long val) {
			this.index = index;
			this.val = val;
		}
		
		public int compareTo(Dummy o) {
			return Long.compare(val, o.val)* -1;
		}

		@Override
		public String toString() {
			return "Dummy [index=" + index + ", val=" + val + "]";
		}
		
		
	}
	
	static void print() {
		for(int i=1;i<=N;i++) {
			System.out.print(arr[i]+" ");
		}
		System.out.println();
		for(int i=1;i<=N;i++) {
			System.out.print(psum[i]+" ");
		}
		System.out.println();
	}
	
	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(in.readLine());
		
		PriorityQueue<Dummy> pq = new PriorityQueue<>();
		
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		arr = new long[N+1];
		psum = new long[N+1];
		checked = new boolean[N+1];
		
		st = new StringTokenizer(in.readLine());
		
		for(int i=1;i<=N;i++) {
			arr[i] = Long.parseLong(st.nextToken());
			psum[i] = psum[i-1] + arr[i];
			pq.add(new Dummy(i,psum[i]));
		}
		
		//print();
		
		for(int i=0;i<K;i++) {
			Dummy cur = pq.poll();
			checked[cur.index] = true;
		}
		
		int remainStudent = K;
		
		for(int i=1;i<=N;i++) {
			if(remainStudent == 0) break;
			ans += arr[i]* remainStudent;
			if(checked[i]) remainStudent--;
		}
		
		System.out.println(ans);
		
	}
}