import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;




public class Main{

	
	static int N,M;
	private static boolean[] isSelected;	//현재 뽑은 수 flag 배열
	private static int[] numbers;			//현재까지 뽑은 수를 저장하는 배열
	
	static void print(int t) {
		for(int i=0;i<t;i++) {
			System.out.print(numbers[i]+" ");
		}
		System.out.println();
	}
	
	private static void permutation(int cnt) {
		
		//기저 부분
		if(cnt == M) {
			print(cnt);
			return;
		}
		
		
		//유도 부분
		for(int i=1;i<=N;i++) {	//가능한 모든 수 시도		[1~N] 까지 숫자를 뽑는다.
			
			if(isSelected[i]) {
				continue;
			}
			numbers[cnt] = i;
			isSelected[i] = true;
			permutation(cnt+1);		//다음 숫자 뽑으러 가기
			isSelected[i] = false;	//하나의 경우의 수를 구한 후 돌아 왔을 때 원복
			
		}
	}
	
	public static void main(String[] args) throws Exception, IOException {
		// TODO Auto-generated method stub
		

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st= new StringTokenizer(in.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		numbers = new int[N];
		isSelected = new boolean[N+1];
		
		permutation(0);
		
		
		
	}

}
