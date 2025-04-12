import java.util.*;

import java.io.*;

public class Main {

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb;
	static int N, ans = Integer.MAX_VALUE;
	static String cur, want;
	static int[] arr;

	static void swtch(int idx) {
		if (idx == 0) {
			arr[idx] ^= 1;
			arr[idx + 1] ^= 1;
		} else if (idx == (N - 1)) {
			arr[idx] ^= 1;
			arr[idx - 1] ^= 1;
		} else {
			arr[idx + 1] ^= 1;
			arr[idx] ^= 1;
			arr[idx - 1] ^= 1;
		}
	}

	static boolean check() {
		for (int i = 0; i < N; i++) {
			if (want.charAt(i) - '0' != arr[i])
				return false;
		}
		return true;
	}

	static void init() {

		for (int i = 0; i < N; i++) {
			arr[i] = cur.charAt(i) - '0';
		}

	}

	public static void main(String[] args) throws Exception {
		N = Integer.parseInt(in.readLine());
		cur = in.readLine();
		want = in.readLine();

		arr = new int[N];

		init();

		// 스위치를 안누른 경우
		int cnt = 0;
		for (int i = 1; i < N; i++) {
			if (arr[i - 1] != want.charAt(i - 1) - '0') {
				// 내가 원하는 형상과 다를 경우 스위치 누른다.
				// System.out.println(i+"스위치 클릭 - 안");
				swtch(i);
				cnt++;
			}
		}
		if (check())
			ans = Math.min(ans, cnt);

		init();

		swtch(0);
		cnt = 1;
		// 첫번쨰 누른 경우

		for (int i = 1; i < N; i++) {
			if (arr[i - 1] != want.charAt(i - 1) - '0') {
				// 내가 원하는 형상과 다를 경우 스위치 누른다.
				// System.out.println(i+"스위치 클릭 - 누");
				swtch(i);
				cnt++;
			}
		}
		if (check())
			ans = Math.min(ans, cnt);

		if (ans == Integer.MAX_VALUE)
			ans = -1;

		System.out.println(ans);
	}

}
