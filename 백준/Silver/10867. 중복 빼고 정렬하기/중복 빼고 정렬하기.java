import java.util.*;
import java.io.*;
import java.awt.*;

public class Main {
	
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N;
	static HashSet<Integer> set = new HashSet<>();

	public static void main(String[] args) throws IOException {
		N = Integer.parseInt(in.readLine());
		st = new StringTokenizer(in.readLine());
		for(int i=0;i<N;i++) {
			set.add(Integer.parseInt(st.nextToken()));
		}
		ArrayList<Integer> arrayList = new ArrayList<>(set);
		Collections.sort(arrayList);
		
		for(int e : arrayList) {
			System.out.print(e+" ");
		}
		System.out.println();
		
	}
	
}