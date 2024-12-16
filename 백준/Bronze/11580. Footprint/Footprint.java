import java.util.*;
import java.io.*;
import java.awt.*;

public class Main {

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N;
	static String s;
	static Point point;
	static HashSet<Point> set;
	
	public static void main(String[] args) throws Exception {
		
		N = Integer.parseInt(in.readLine());
		
		s = in.readLine();
		set = new HashSet<>();
		
		point = new Point(0,0);
		set.add(new Point(point));
		
		for(int i=0;i<N;i++) {
			char op = s.charAt(i);
			if(op == 'E') {
				point.x += 1;
			}
			else if(op == 'W') {
				point.x -= 1;
			}
			else if(op == 'S') {
				point.y -= 1;
			}
			else {
				point.y += 1;
			}
			set.add(new Point(point));
		}
		
//		for(Point p : set) {
//			System.out.println(p);
//		}
		
		System.out.println(set.size());
		
		
	}
}