import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	private static StringBuilder sb = new StringBuilder();
	private static StringTokenizer st;
	
//	static boolean[] che = new boolean[100000004];
//	
//	static void era(int num) {
//		che[1] = true;	//1은 소수가 아니다
//		for(int i=2;i<= num; i++) {
//			if(che[i]) continue; 	//체가 이미 거쳐갔을 경우  SKIP
//			for(int j = 2*i;j<=num;j+=i) {
//				che[j] = true;	//j만큼씩 더해가며 소수가 아닌것을 제낀다.
//			}
//		}	
//	}
//	
	static boolean isPrime(int num) {
		if(num <=1) return false;
		if(num == 2) return true;	//소수
		if(num % 2 == 0) return false;	//소수아님
		for(int i=3;i*i <= num;i++) {
			if(num % i == 0) return false;
		}
		return true;
		
	}
	
	static int N;
	
	static void print(int num) {
		int digit = num;
		int n =0;
		while(digit != 0) {
			digit /=10;
			n++;
		}
		
		if(n == N) {
			System.out.println(num);
			return;
		}
		int temp;
		for(int i=0;i<=9;i++) {
			temp = num*10 + i;
			if(isPrime(temp)) {	//소수라면
				print(temp);	//다음으로 넘긴다.
			}
			
		}
	}
	
	
	public static void main(String[] args) throws Exception {
		/**
		 * 0. 입력파일 읽어들이기
		 */
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(in.readLine());
		int[] prime = {2,3,5,7};
		for(int i=0;i<4;i++) {
			print(prime[i]);
		}
	
		
		
		
		
	}
}