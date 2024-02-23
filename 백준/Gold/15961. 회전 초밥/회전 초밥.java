import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static StringBuilder sb = new StringBuilder();
	static int N,d,k,c,ans;
	static int [] belt;
	static int[] selected;
	static StringTokenizer st;
	static BufferedReader in = new  BufferedReader(new InputStreamReader(System.in));
	
	
	
	static void solve() {
		Deque<Integer> deque = new ArrayDeque<>();
		int cnt =1;
		selected[c]++;
		for(int i=0;i<k;i++) {	//첫번째 3개가 들어감
			deque.addLast(belt[i]);
			if(selected[belt[i]]==0) {	//선택되어 있지 않았다면
				cnt++;
			}
			selected[belt[i]]++;	//현재 덱의 선택요소 증가			
		}
		
//		for(int i : deque) {
//			System.out.print(i+" ");
//		}
//		System.out.println();
//		System.out.println(cnt);
//		for(int k=1;k<d+1;k++) {
//			System.out.print(selected[k]+" ");
//		}
//		System.out.println();
		
		ans = Math.max(ans,cnt);	//max값 갱신하고
		
		for(int i=k;i<N+k-1;i++) {	//i를 start로
			
			if(ans == k+1) break;	//최대 종류를 이미 찾았다면 break
			int prev = deque.pollFirst();	//이전꺼 빼고
			int next = belt[i];
			selected[prev]--;	//덱에서 빠짐을 반영
			
			if(selected[prev]== 0) cnt--;	//덱에 하나도 없다면 종류 감소
			
			deque.addLast(next);	//다음 꺼 넣는다.
			
			if(selected[next] ==0) {	//증가시킴
				cnt++;	
			}
			selected[next]++;
			
//			for(int elem : deque) {
//				System.out.print(elem+" ");
//			}
//			
//			System.out.println();
//			
//			for(int k=1;k<d+1;k++) {
//				System.out.print(selected[k]+" ");
//			}
//			System.out.println();
//			
//			System.out.println(cnt);
			
			
			
			ans = Math.max(ans, cnt);
			
		}
	}
	
	
	
	public static void main(String[] args) throws Exception {
		
		st = new StringTokenizer(in.readLine());
		
		
		N = Integer.parseInt(st.nextToken());
		d = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		
		belt = new int[N+k-1];
		selected = new int[d+1];
	
		for(int i=0;i<N;i++) {
			belt[i] = Integer.parseInt(in.readLine());
		}
		
		for(int i=N;i<N+k-1;i++) {	//뒤에 추가
			belt[i] = belt[i-N];
		}
		
		
		solve();
		
		System.out.println(ans);
		

		
		

	}
}
