import java.util.*;
import java.io.*;
public class Main {
	
	static StringTokenizer st;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static String s;
	static ArrayList<String> lst;
	static StringBuilder sb;

	public static void main(String[] args) throws Exception {
		s = in.readLine();
		
		lst = new ArrayList<>();
		
		for(int i=0;i<s.length();i++) {
			String temp = s.substring(i);
			lst.add(temp);
		}
		Collections.sort(lst);
		
		sb = new StringBuilder();
		
		for(String elem : lst) {
			sb.append(elem+"\n");
		}
		
		System.out.println(sb);
	}
}