import java.util.*;
import java.io.*;
import java.awt.*;

public class Main {

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static HashSet<String> set;
	static int N;
	
	public static void main(String[] args) throws Exception {
		
		set = new HashSet<>();
		
		N = Integer.parseInt(in.readLine());
		
		for(int i=0;i<N;i++) {
			String s = in.readLine();
			ArrayList<Character> lst = new ArrayList<>();
			for(int j=0;j<s.length();j++) {
				lst.add(s.charAt(j));
			}
			Collections.sort(lst);
			StringBuilder sb= new StringBuilder();
			for(char c : lst) {
				sb.append(c);
			}
			//System.out.println(sb);
			set.add(sb.toString());
		}
		
		System.out.println(set.size());
		
	}
}