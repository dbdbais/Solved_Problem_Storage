import java.util.*;
import java.awt.Point;
import java.io.*;


public class Main {
	
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N,ans=1;
	static int[] arr;
	static int [] cnt = new int[10];
	//과일 카운트 배열
	public static int getCount() {
		int c =0;
		for(int i=1;i<=9;i++) {
			if(cnt[i] > 0) c++;
		}
		return c;
	}
	public static void pCnt() {
		for(int i=1;i<=9;i++) {
			System.out.print(cnt[i]+" ");
		}
		System.out.println();
	}
	
	public static void solve() {
		int _left = 0;
		int _right = 0;
		int tcnt = 1;
		//맨 처음거 증가
		cnt[arr[_left]]++;
		
		while(_right < N-1) {
			//종류가 2개 초과 라면
		
			//System.out.println("left : "+_left + " right : "+_right + " tcnt : "+ tcnt);
			if(tcnt > 2) {
				cnt[arr[_left]]--;
				if(cnt[arr[_left]] == 0) {
					tcnt--;
					//종류 하나 감소
				}
				_left++;
				//증가
			}
			else {
				_right++;
				if(cnt[arr[_right]] == 0) {
					tcnt++;
					//종류 증가
				}
				
				int _len = _right -_left+1;
				if(tcnt <= 2 && ans < _len ) {
					ans = _len;
				}
				cnt[arr[_right]]++;
				//우측 증가
			}
		}
			
	}
	
	public static void main(String[] args) throws IOException {
		N = Integer.parseInt(in.readLine());
		st = new StringTokenizer(in.readLine());
		arr = new int[N];
		for(int i=0;i<N;i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		solve();
		
		System.out.println(ans);
		
		
	}
}