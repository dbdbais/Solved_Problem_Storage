import java.util.*;
import java.io.*;

public class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static ArrayList<Long> lst = new ArrayList<>();
	static int N,a,b,c;
	static long dist = Long.MAX_VALUE;
	
	public static void main(String[] args) throws IOException {
		N = Integer.parseInt(in.readLine());
		
		st = new StringTokenizer(in.readLine());
		for(int i=0;i<N;i++) {
			lst.add(Long.parseLong(st.nextToken()));
		}
		Collections.sort(lst);
		

		for(int mid = 0;mid<N-2;mid++) {
			int left = mid+1;
			int right = lst.size()-1;
			while(left < right) {
				
				//System.out.println(lst.get(mid) + " : " + lst.get(left) + " : " + lst.get(right));
				
				long sm = lst.get(mid) + lst.get(left) + lst.get(right);
				//System.out.println(sm);
				if(Math.abs(sm) < dist) {
					
					dist = Math.abs(sm);
					a = mid;
					b = left;
					c = right;
				}
				
				if(sm < 0) {
					left++;
				}
				else {
					right--;
				}
				
			}
						
		}
		
		System.out.println(lst.get(a)+" "+lst.get(b) +" "+lst.get(c));
		
		
	}
	
	
	
}