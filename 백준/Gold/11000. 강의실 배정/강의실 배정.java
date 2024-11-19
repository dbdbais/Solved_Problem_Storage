import java.util.*;
import java.awt.*;
import java.io.*;

public class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static class Study implements Comparable<Study>{
		long start;
		long end;
		
		public Study(long start, long end) {
			this.start = start;
			this.end = end;
		}
		public int compareTo(Study o) {
			if(start == o.start) {
				return Long.compare(end, o.end);
			}
			return Long.compare(start, o.start);
		}
		@Override
		public String toString() {
			return "Study [start=" + start + ", end=" + end + "]";
		}
		
		
	}
	static PriorityQueue<Long> pq;
	static int N;
	static Study studies[];
	
	public static void main(String[] args) throws Exception {
		pq = new PriorityQueue<Long>();
		N = Integer.parseInt(in.readLine());
		studies = new Study[N];
		
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(in.readLine());
			long a = Long.parseLong(st.nextToken());
			long b = Long.parseLong(st.nextToken());
			studies[i] = new Study(a, b);
		}
		Arrays.sort(studies);
		
		pq.add(studies[0].end);
		for(int i=1;i<N;i++) {
			//System.out.println(studies[i]);
			long start = studies[i].start;
			long end = studies[i].end;
			if(pq.peek() <= start) {
				//pq의 맨 앞에 있는게 start보다 작다면
				pq.poll();
				//그거 뺴고ㅓ
				pq.add(end);
			}
			else {
				//그렇지 않다면
				pq.add(end);
				//새로운 회의실을 쓰고 끝나는 시간 넣어 놓는다.
				
			}
		}
		System.out.println(pq.size());

	}
}
