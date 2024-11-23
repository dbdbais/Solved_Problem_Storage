import java.util.*;
import java.io.*;

class Main {

	static StringTokenizer st;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static Long N,P,Q;
	static HashMap<Long,Long> map;

	
	static Long solve(Long num) {
		//System.out.println(num +" called");
		if(!map.containsKey(num)) {
			Long val = solve(Math.floorDiv(num, P)) + solve(Math.floorDiv(num, Q)) ;
			map.put(num,val);
		}
		return map.get(num);
	}

	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(in.readLine());
		
		map = new HashMap<>();
		map.put(0L,1L);

		N = Long.parseLong(st.nextToken());
		P = Long.parseLong(st.nextToken());
		Q = Long.parseLong(st.nextToken());
		
		solve(N);

		System.out.println(map.get(N));
		

	}
}