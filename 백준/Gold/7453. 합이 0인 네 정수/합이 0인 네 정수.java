import java.util.*;
import java.util.List;
import java.awt.*;
import javax.print.attribute.IntegerSyntax;

import java.io.*;

public class Main {
	static StringBuilder sb;
	static StringTokenizer st;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int N;
	static long ans;
	static int[] A, B, C, D, CD, AB;

	public static void main(String[] args) throws Exception {

		N = Integer.parseInt(in.readLine());
		A = new int[N];
		B = new int[N];
		C = new int[N];
		D = new int[N];
		AB = new int [N * N];
		CD = new int[N * N];
		

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(in.readLine());
			A[i] = Integer.parseInt(st.nextToken());
			B[i] = Integer.parseInt(st.nextToken());
			C[i] = Integer.parseInt(st.nextToken());
			D[i] = Integer.parseInt(st.nextToken());
		}
		
		int idx =0;
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				CD[idx++] = C[i] + D[j];
			}
		}
		
		idx =0;
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				AB[idx++] = A[i] + B[j];
			}
		}
		
		Arrays.sort(CD);
		Arrays.sort(AB);
		
		int left = 0;
		int right = N*N-1;
		// 투 포인터
		
		while(left < N*N && right >=0) {
			long sm = AB[left] + CD[right];
			if (sm < 0) {
				left++;
			}
			else if(sm > 0) {
				right--;
			}
			else {
				long leftCount = 0, rightCount = 0;
				int abVal = AB[left];
				int cdVal = CD[right];
				
				while(left < N*N && AB[left] == abVal) {
					leftCount++;
					left++;
				}
				
				while(right >= 0 && CD[right] == cdVal) {
					rightCount++;
					right--;
				}
				
				ans += leftCount * rightCount;
			}
			
		}
		
		
		
		System.out.println(ans);
		
		

	}
}
