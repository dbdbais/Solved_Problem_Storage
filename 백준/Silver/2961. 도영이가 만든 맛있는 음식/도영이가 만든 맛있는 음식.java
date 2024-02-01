import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	private static StringBuilder sb = new StringBuilder();
	private static StringTokenizer st;

	static int[] sour = new int[11];
	static int[] bitter = new int[11];
	static int ans = 1000000000;
	static boolean [] isSelected = new boolean[11];
	static List<Integer> slist = new ArrayList<>();	//신 음식들이 들어갈 리스트
	static List<Integer> blist = new ArrayList<>();	//쓴 음식이 들어갈 리스트
	static int N;
	public static void main(String[] args) throws Exception {
		/**
		 * 0. 입력파일 읽어들이기
		 */
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));


		N = Integer.parseInt(in.readLine());

		for(int i=0;i<N;i++) {
			st= new StringTokenizer(in.readLine());
			sour[i] = Integer.parseInt(st.nextToken());
			bitter[i] = Integer.parseInt(st.nextToken());
		}


		generateSubset(0);

//		for(int i : slist) {
//			System.out.print(i+" ");
//		}
//		System.out.println();
//		for(int i : blist) {
//			System.out.print(i+" ");
//		}


		for(int i=0;i<slist.size();i++) {
			int tmp = Math.abs(slist.get(i)-blist.get(i));

			if(ans > tmp) ans = tmp;
		}

		System.out.println(ans);

	}

	private static void generateSubset(int cnt) {

		if(cnt == N) {
			boolean found= false;
			for(int i=0;i<N;i++) {
				if(isSelected[i]) {
					found = true;
				}
			}
			if(!found) return;	//아예 아무것도 없는 경우 제낌
			
			int sm;

			sm = 1;
			for(int i=0;i<N;i++) {
				if(isSelected[i]) {	//선택되었다면 출력
					sm *= sour[i];
				}
			}
			
				slist.add(sm);	//추가
			sm = 0;
			for(int i=0;i<N;i++) {
				if(isSelected[i]) {	//선택되었다면 출력
					sm += bitter[i];
				}
			}
				blist.add(sm);	//추가
			
			return;
		}


		isSelected[cnt] = true;	//선택되었음
		generateSubset(cnt+1);	//다음 경우의 수 찾아 떠남
		isSelected[cnt] = false;	//선택 해제한다.
		generateSubset(cnt+1);	//해제한 후 다음 경우의 수 찾아 떠난다.

	}
}