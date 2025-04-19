import java.util.*;
import java.awt.Point;
import java.io.*;

public class Main {

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb;
	static int T, N, M;


	public static void main(String[] args) throws Exception {
		T = Integer.parseInt(in.readLine());

		sb = new StringBuilder();
		for(int i=0;i<T;i++) {
			st = new StringTokenizer(in.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			for(int j=0;j<M;j++) {
				String s = in.readLine();
			}
			sb.append(N-1+"\n");
		}
		System.out.println(sb);
	
	}

}
