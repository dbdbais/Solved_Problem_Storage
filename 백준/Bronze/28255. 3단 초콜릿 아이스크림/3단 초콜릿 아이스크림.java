import java.util.*;
import java.io.*;
import java.awt.*;
class Main {
	
	static StringTokenizer st;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int T;
	
	static String first(String s) {
		StringBuilder sb = new StringBuilder(s);
		sb.reverse();
		return s + sb.toString() + s;
	}
	
	static String second(String s) {
		StringBuilder sb1 = new StringBuilder(s);
		sb1.reverse();
		sb1.deleteCharAt(0);
		return s + sb1.toString()+ s;
	}
	static String third(String s) {
		StringBuilder sb1 = new StringBuilder(s);
		StringBuilder sb2 = new StringBuilder(s);
		sb1.reverse();
		sb2.deleteCharAt(0);
		return s + sb1.toString()+ sb2.toString();
	}
	static String fourth(String s) {
		StringBuilder sb1 = new StringBuilder(s);
		StringBuilder sb2 = new StringBuilder(s);

		sb1.reverse();
		sb1.deleteCharAt(0);
		sb2.deleteCharAt(0);
		
		return s + sb1.toString()+ sb2.toString();
	}
	
	public static void main(String[] args) throws Exception {
		T = Integer.parseInt(in.readLine());
		StringBuilder sb = new StringBuilder();
		for(int i=0;i<T;i++) {
			String temp = in.readLine();
			int idx = temp.length()/3;
			if(temp.length() % 3 != 0) {
				idx++;
			}
			String s = temp.substring(0, idx);
			//System.out.println("S : " + s );
			String fs = first(s);
			String ss = second(s);
			String ts = third(s);
			String ffs = fourth(s);
			
//			System.out.println(fs);
//			System.out.println(ss);
//			System.out.println(ts);
//			System.out.println(ffs);
			if(temp.equals(fs) || temp.equals(ss) || temp.equals(ts) || temp.equals(ffs)) {
				sb.append(1+"\n");
			}
			else {
				sb.append(0+"\n");
			}
		}
		
		System.out.println(sb);
	}
}