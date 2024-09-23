import java.io.*;
import java.util.*;


class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static String A,B;
	static StringBuilder w,x,y,z,k;
	
	
	public static void main(String[] args) throws IOException {
		
		w= new StringBuilder();
		x = new StringBuilder();
		y = new StringBuilder();
		z = new StringBuilder();
		k = new StringBuilder();
		
		A = in.readLine();
		B = in.readLine();
		
		for(int i=0;i<A.length();i++) {
			int a = A.charAt(i)-'0';
			int b = B.charAt(i)-'0';
			
			w.append(a&b);
			x.append(a|b);
			y.append(a^b);
			z.append(~a+2);
			k.append(~b+2);
		}
		
		System.out.println(w.toString());
		System.out.println(x.toString());
		System.out.println(y.toString());
		System.out.println(z.toString());
		System.out.println(k.toString());
		
	}

	

}