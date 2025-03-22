import java.util.*;
import java.io.*;

public class Main {

	static public class Cord{
		long x;
		long y;
		
		public Cord(long x,long y) {
			this.x = x;
			this.y = y;
		}
		
		
		public String toString() {
			return this.x +":" + this.y;
		}
		
	}
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static ArrayList<Cord> lst;
	static int N;
	static double ans;

	public static void main(String[] args) throws Exception {
		lst = new ArrayList<>();
		
		N = Integer.parseInt(in.readLine());
		
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(in.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			
			lst.add(new Cord(x,y));
		}
		
		lst.add(new Cord(lst.get(0).x,lst.get(0).y));
		
		double ansX;
		double ansY;
		
		ansX = ansY = 0.0;
		
		for(int i=0;i<N;i++) {
			ansX += lst.get(i).x * lst.get(i+1).y;
			ansY += lst.get(i+1).x * lst.get(i).y;
	
		}
		if (ansX > ansY) {
			ans = (ansX - ansY) * 0.5;
		}
		else {
			ans = (ansY - ansX) * 0.5;
		}
		
		System.out.printf("%.1f",ans);
		
	}

}


