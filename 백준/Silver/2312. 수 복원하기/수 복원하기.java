import java.util.*;
import java.io.*;

public class Main {
	
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static boolean [] isPrime;
	static TreeMap<Integer, Integer> map;
	static int T,N;
	
	static void init() {
		isPrime= new boolean[N+1];
		Arrays.fill(isPrime, true);
		isPrime[0] = isPrime[1] = false;
		
		for(int i=2;i<=Math.sqrt(N);i++) {
			if(isPrime[i]) {
				for(int j= i+i;j<=N;j += i) {
					isPrime[j] = false;
				}
				
			}
		}
		
	}
	
	static void solve() {
		map = new TreeMap<>();
		int tempN = N;
		int num = 2;
		while(tempN>1) {
			
			if(isPrime[num]) {
				int cnt =0;
				while(tempN % num == 0) {
					cnt++;
					//횟수
					tempN /= num;
					// 실제로 나눠버림
				}
				if(cnt > 0) {
					map.put(num, cnt);
				}
			}
			
			if(++num > N) break;
		}
		
		for(int key : map.keySet()) {
			System.out.println(key+" "+ map.get(key));
		}
		
		
		
	}
	public static void main(String[] args) throws Exception {
		T = Integer.parseInt(in.readLine());
		
		for(int i=0;i<T;i++) {
			N = Integer.parseInt(in.readLine());
			init();
			solve();
			
			
		}
		
	}
	
	
}