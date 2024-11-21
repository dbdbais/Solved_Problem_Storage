import java.util.*;
import java.awt.*;
import java.io.*;

public class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int [] arr;
	static int N,mxLen = 1;

	
	
	public static void main(String[] args) throws Exception {
		N = Integer.parseInt(in.readLine());
		arr = new int[N+1];
		st = new StringTokenizer(in.readLine());
		for(int i=1;i<=N;i++) {
			arr[Integer.parseInt(st.nextToken())] = i;
		}
//		for(int i=1;i<=N;i++) {
//			System.out.print(arr[i]+ " ");
//		}
//		System.out.println();
		
		int mcnt = 0;
		for(int i=1;i<=N;i++) {
			//System.out.println(i+":"+mcnt);
			if(arr[i] > arr[i-1]) {
				mcnt++;
			}
			else {
				mxLen = Math.max(mcnt, mxLen);
				mcnt =1;
			}
		}
		mxLen = Math.max(mcnt, mxLen);
		//System.out.println(mxLen);
		System.out.println(N - mxLen);
		
	}
}