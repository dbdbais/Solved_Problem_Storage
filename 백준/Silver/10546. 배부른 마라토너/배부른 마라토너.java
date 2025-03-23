import java.util.*;
import java.io.*;

public class Main {

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N;
	static Map<String,Integer> mp;

	public static void main(String[] args) throws Exception {
		
		mp = new HashMap<>();
		
		N = Integer.parseInt(in.readLine());
		
		for(int i=0;i<N;i++) {
			String s = in.readLine();
			if(mp.containsKey(s)) {
				int val = mp.get(s);
				mp.replace(s, val+1);
			}
			else {
				mp.put(s, 1);
			}
		}
		
		for(int i=0;i<N-1;i++) {
			String s = in.readLine();
			int left = mp.get(s);
			if(left==1) {
				mp.remove(s);
			}
			else {
				mp.replace(s, left-1);
			}
		}
		
		for(String s : mp.keySet()) {
			System.out.println(s);
		}
		
		
	}

}


