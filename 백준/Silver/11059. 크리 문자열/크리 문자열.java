import java.util.*;
import java.io.*;

public class Main {
	
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static String s, answer;
	static int mxLen = -1;
	
	public static void main(String[] args) throws Exception {
		s = in.readLine();
		int slen = s.length();
		for(int i=0;i<slen-1;i++) {
			for(int j=i+1;j<slen;j++) {
				int diff = j-i + 1;
				//차를 구함
				//System.out.println(i+":"+j+":"+diff);
				
				if(diff < mxLen) continue;
				
				if( diff % 2 == 0) {
					int fsum = 0;
					int esum = 0;
					
					int mid = i + (diff/2) ; 
					//가운데 계산
					
					for(int a = i;a < mid; a++ ) {
						fsum += s.charAt(a)-'0';
					}
					for(int a = mid; a<= j; a++) {
						esum += s.charAt(a) - '0';
					}
					
					//System.out.println("fsum : "+ fsum +" esum : "+ esum);
					
					if(fsum == esum) {
						mxLen = diff;
					}
				}
				
			}
		}
		
		System.out.println(mxLen);
		
		
	}
	
	
}