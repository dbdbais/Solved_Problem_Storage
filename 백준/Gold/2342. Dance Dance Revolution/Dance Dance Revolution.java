import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	static int answer = Integer.MAX_VALUE;

	static int[][][] dp;
	static int cnt = 1;

	static int move(int position, int dest) {
		if (position == dest)
			return 1;
		// 같은 지점일 경우
		if (position == 0) {
			return 2;
			// 증앙
		} else if (position == 1) {
			if (dest == 2 || dest == 4) {
				return 3;
			} else {
				return 4;
			}

		} else if (position == 2) {
			if (dest == 1 || dest == 3) {
				return 3;
			} else {
				return 4;
			}
		} else if (position == 3) {
			if (dest == 2 || dest == 4) {
				return 3;
			} else {
				return 4;
			}
		} else {
			if (dest == 1 || dest == 3) {
				return 3;
			} else {
				return 4;
			}
		}
	}

	public static void main(String[] args) throws IOException {

		dp = new int[5][5][100001];
		// 새로운 DP 배열 할당
		// 현재 수열 수, 왼쪽 오른쪽 발 움직인 경우

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 100001; k++) {
					dp[i][j][k] = 9999999;
				}
			}
		}

		st = new StringTokenizer(in.readLine());
		dp[0][0][0] = 0;
		int prev = 0;
		while (st.hasMoreTokens()) {
			int op = Integer.parseInt(st.nextToken());
			// 다음 위치
			if (op != 0) {
				prev = op;
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 5; j++) {
						dp[i][op][cnt] = Math.min(dp[i][op][cnt], dp[i][j][cnt - 1] + move(j, op));
						// j에서 op로 이동할 경우

						dp[op][j][cnt] = Math.min(dp[op][j][cnt], dp[i][j][cnt - 1] + move(i, op));
					}
				}

			} else {
				for (int i = 0; i < 5; i++) {
					answer = Math.min(answer, dp[prev][i][cnt-1]);
					answer = Math.min(answer, dp[i][prev][cnt-1]);
				}
				break;
			}
			cnt++;
		}

		System.out.println(answer);

	}

}