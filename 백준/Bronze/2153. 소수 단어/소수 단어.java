import java.io.*;
import java.util.*;


class Main {
	
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int cnt;
	static StringBuilder sb = new StringBuilder();
	
	static boolean isPrime(int num) {
		for(int i=2;i<=(int)Math.sqrt(num);i++) {
			if(num % i == 0) {
				return false;
			}
		}
		return true;
		
	}
	
	public static void main(String[] args) throws IOException {
		String s = in.readLine();
		
		for(int i=0;i<s.length();i++) {
			char c = s.charAt(i);
			int e = 0;

			if(Character.isUpperCase(c)) {
				e = (c-'A')+ 26;
			}
			else if(Character.isLowerCase(c)) {
				e = c -'a';
			}
			else {
				continue;
			}
			cnt += (e+1);
		}
		
		
		//System.out.println(cnt);
		
		if(cnt == 1 || isPrime(cnt)) {
			System.out.println("It is a prime word.");
		}
		else {
			System.out.println("It is not a prime word.");
		}
		
	
	}
}