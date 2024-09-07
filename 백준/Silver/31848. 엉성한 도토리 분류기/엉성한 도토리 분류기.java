import java.io.*;
import java.util.*;

class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int N, Q;
	static int[] lst,ipt;

	public static int lowerBound(int target) {
		int begin = 1;
		int end = N;

		while (begin < end) {
			int mid = (begin + end) / 2;

			if (lst[mid] >= target) {
				end = mid;
				// 범위를 밑으로 줄임

			} else {
				begin = mid + 1;
				// 범위를 위로 올림
			}
		}
		return end;
	}

	public static void main(String[] args) throws IOException {

		st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		lst = new int[N+1];


		st = new StringTokenizer(in.readLine());
		for (int i = 1; i <= N; i++) {
			int ip = Integer.parseInt(st.nextToken());
			lst[i] = Math.max(lst[i-1], ip+i-1);
			//이전과 비교해서 큰값만 누적
			//System.out.println(lst[i]);
		}
		st = new StringTokenizer(in.readLine());
		Q = Integer.parseInt(st.nextToken());
		ipt = new int[Q+1];
		
		st = new StringTokenizer(in.readLine());
		for (int i = 1; i <= Q; i++) {
			ipt[i] =Integer.parseInt(st.nextToken());
			//이전과 비교해서 큰값만 누적
		}
		for (int i = 1; i <= Q; i++) {
			sb.append(lowerBound(ipt[i]));
			if(i < Q) {
				sb.append(" ");
			}
		}
		System.out.println(sb);

	}

}