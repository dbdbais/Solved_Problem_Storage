import java.awt.Point;
import java.io.*;
import java.util.*;


class Main {
	
	static class Serial implements Comparable<Serial>{
		String ste;
		int sz;
		int sm;
		public Serial(String ste) {
			this.ste = ste;
			this.sz = ste.length();
			
			int t = 0;
			for(int i=0;i<sz;i++) {
				char c = ste.charAt(i);
				if(Character.isDigit(c)) t += (c-'0');
			}
			this.sm = t;
		}

		@Override
		public int compareTo(Serial o) {
			if(sz == o.sz) {
				if(sm == o.sm) {
					return ste.compareTo(o.ste);
				}
				return Integer.compare(sm, o.sm);
			}
			else {
				return Integer.compare(sz, o.sz);
			}
		}
	}
	
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int N;
	static ArrayList<Serial> lst;
	public static void main(String[] args) throws IOException {
		
		N = Integer.parseInt(in.readLine());
		lst = new ArrayList<>();
		
		for(int i=0;i<N;i++) {
			String s = in.readLine();
			lst.add(new Serial(s));
		}
		
		Collections.sort(lst);
		
		for(Serial s : lst) {
			sb.append(s.ste+"\n");
		}
		
		System.out.println(sb);
	
		
	}

	

}