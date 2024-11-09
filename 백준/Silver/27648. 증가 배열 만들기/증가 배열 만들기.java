import java.util.*;
import java.io.*;

class Main {

	static StringTokenizer st;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int N, M, K;

	static void print() {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				sb.append((i+j+1) + " ");
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}

	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(in.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());


		if (N + M >= K + 2) {
			System.out.println("NO");
		} else {
			System.out.println("YES");
			print();
		}

	}
}