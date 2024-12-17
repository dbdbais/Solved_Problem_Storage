import java.util.*;
import java.io.*;
import java.awt.*;

public class Main {

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder fsb = new StringBuilder();
	static final String answer = "WOW";
	static int Q;
	
	
	public static void main(String[] args) throws Exception {
		Q = Integer.parseInt(in.readLine());
		for(int i=0;i<Q;i++) {
			String s = in.readLine();
			int len = s.length();
		
			if(len < 3) {
				fsb.append(0+"\n");
				continue;
			}
			
			int wowCnt = 0;
			StringBuilder sb = new StringBuilder();
			for(int j=0;j<3;j++) {
				sb.append(s.charAt(j));
			}
			//System.out.println(sb);
			if(sb.toString().equals(answer)) {
				wowCnt++;
			}
			for(int j = 3; j<len;j++) {
				sb.deleteCharAt(0);
				sb.append(s.charAt(j));
				//System.out.println(sb);
				if(sb.toString().equals(answer)) {
					wowCnt++;
				}
			}
			fsb.append(wowCnt+"\n");
		}
		System.out.println(fsb);
		
	}
	
}