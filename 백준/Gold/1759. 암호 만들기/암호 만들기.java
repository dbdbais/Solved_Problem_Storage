import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	private static StringBuilder sb = new StringBuilder();
	private static StringTokenizer st;

	static int L,C;
	static char[] alpha;
	static boolean[] found;
	static void solve(int idx, String ans) {
		if(ans.length() == L && check(ans) ) {
			System.out.println(ans);
			return;
		}
		for(int i=idx+1;i<C;i++) {
			solve(i,ans+alpha[i]);
		}

	}
	static boolean check(String s) {
		int v = 0;	//모음
		int e = 0;	//자음
		for(int i=0;i<L;i++) {
			if(s.charAt(i) =='a' || s.charAt(i)=='e'||s.charAt(i)=='i'||s.charAt(i)=='o'||s.charAt(i)=='u') {
				v++;
			}
			else {
				e++;
			}
			if(v>=1 && e>=2) {
				return true;
			}
		}
		return false;

	}

	public static void main(String[] args) throws Exception {
		/**
		 * 0. 입력파일 읽어들이기
		 */
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		st = new StringTokenizer(in.readLine());

		L = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		alpha = new char[C];
		found = new boolean[C];

		st = new StringTokenizer(in.readLine());

		for(int i=0;i<C;i++) {
			alpha[i] = st.nextToken().charAt(0);
		}
		Arrays.sort(alpha);

		solve(-1,"");
		//		for(char c : alpha) {
		//			System.out.print(c+" ");
		//		}





		System.out.println(sb);
	}
}