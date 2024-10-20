import java.io.*;
import java.util.*;

/**
 * 첫째 줄에 직사각형 빙고판의 크기를 뜻하는 n(1 ≤ n ≤ 500)과 m(1 ≤ m ≤ 500)이 주어진다. 
 * 다음 줄부터 n개의 줄에 걸쳐 각 줄마다 m개의 숫자들이 주어진다. 이는 크기가 n×m인 짝꿍의 빙고판의 상태를 나타내며, 
 * 빙고판에는 10,000 이하의 음이 아닌 정수가 적힌다.
 */
public class Main {
	static StringTokenizer st;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int N,M,totalCnt,mxCnt;
	static int [][] arr;
	
	static void getRow() {
		
		for(int i=0;i<N;i++) {
			int tmp =0;
			for(int j =0;j<M;j++) {
				tmp += arr[i][j];
			}
			mxCnt = Math.max(mxCnt, tmp);
		}
		
	}
	
	static void getCol() {
		for(int i=0;i<M;i++) {
			int tmp =0;
			for(int j =0;j<N;j++) {
				tmp += arr[j][i];
			}
			mxCnt = Math.max(mxCnt, tmp);
		}
	}
	
	public static void main(String[] args) throws Exception {
		
		st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		arr = new int[N][M];
		
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(in.readLine());
			for(int j=0;j<M;j++) {
				int cnt = 0;
				String s = st.nextToken();
				for(int k =0;k<s.length();k++) {
					int elem = s.charAt(k)-'0';
					if(elem == 9) cnt++;
				}
				arr[i][j] = cnt;
				totalCnt += cnt;
			}
		}
		
		getRow();
		getCol();
		
		
		System.out.println(totalCnt - mxCnt);
		
		
		
	}
	
}