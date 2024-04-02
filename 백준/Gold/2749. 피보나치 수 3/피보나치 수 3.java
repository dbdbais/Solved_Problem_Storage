import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static long N;
	static long[][] ans = {{1,0},{0,1}};	//단위 행렬
	static long[][] init = {{1,1},{1,0}};
	static long mod = 1000000;
	
	static long[][] mul(long [][] a,long [][] b) {
		
		long[][] res = new long[2][2];
		
		for(int i=0;i<2;i++) {
			for(int j=0;j<2;j++) {
				long sm = 0;
				for(int k=0;k<2;k++) {
					sm += (a[i][k] * b[k][j])% mod;
					sm %= mod;
				}
				res[i][j] = sm;	//정답 배열 갱신
			}
		}
		
		return res;
	}
	
	static void pow(long[][] a,long n) {
		if(n == 0) {
			return;
		}
		
		if(n % 2 == 1) {
			ans = mul(ans,a);
		}
		long[][] sq = mul(a,a);	//제곱을 찾아
		pow(sq,n/2);
	}
	
	public static void print() {
		for(int i=0;i<2;i++) {
			for(int j=0;j<2;j++) {
				System.out.print(ans[i][j]+" ");
			}
			System.out.println();
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		N = Long.parseLong(in.readLine());

		pow(init,N-1);
		System.out.println(ans[0][0]);
		
		
		
		
	}
}