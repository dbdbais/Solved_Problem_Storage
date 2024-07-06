import java.io.*;
import java.util.*;
import java.awt.*;

public class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int N;
	static int[] DP;
	public static void main(String[] args) throws IOException {
		N = Integer.parseInt(in.readLine());
		DP = new int[N+3];
		DP[0] = 1;
		DP[2] = 3;
		for(int i=4;i<=N;i++) {
			if(i % 2 == 1) continue;
			//홀수면 제낌
			DP[i] = DP[i-2] * 3;
			//이전에서 3 곱한 경우
			for(int j=i-4;j >=0 ;j-=2) {
			DP[i] += DP[j] * 2;
			//4부터 짝수마다 고유의 모양 2개씩 가지는거 반영해서 더해준다.
			}
		}
		System.out.println(DP[N]);
		
	}
}