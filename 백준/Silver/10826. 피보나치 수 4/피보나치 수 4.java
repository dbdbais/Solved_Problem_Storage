import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.BigInteger;

public class Main {
	static BigInteger[] dp;
	static int N;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	public static void main(String[] args) throws NumberFormatException, IOException {
		N = Integer.parseInt(in.readLine());
		dp = new BigInteger[10003];
		dp[0] = new BigInteger("0");
		dp[1] = new BigInteger("1");
		for(int i =2;i<= N;i++) {
			dp[i] = dp[i-1].add(dp[i-2]);
		}
		
		System.out.println(dp[N]);
	}
}