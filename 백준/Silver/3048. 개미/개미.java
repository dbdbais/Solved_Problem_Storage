import java.io.*;
import java.util.*;


class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N1,N2,T;
	static ArrayList<Character> lst;
	static ArrayList<Integer> ant;
	static boolean [] visited;
	
	static void print() {
		for(char c : lst) {
			System.out.print(c);
		}
		System.out.println();
		
//		for(int e : ant) {
//			System.out.print(e);
//		}
//		System.out.println();
	}
	
	public static void main(String[] args) throws IOException {
		
		lst = new ArrayList<>();
		ant = new ArrayList<>();
		
		st = new StringTokenizer(in.readLine());
		
		N1 = Integer.parseInt(st.nextToken());
		N2 = Integer.parseInt(st.nextToken());
		
		visited= new boolean[N1+N2];
		
		String s1 = in.readLine();
		
		for(int i=N1-1;i>=0;i--) {
			char c = s1.charAt(i);
			lst.add(c);
			ant.add(1);
		}
		
		String s2 = in.readLine();
		
		for(int i=0;i<N2;i++) {
			char c = s2.charAt(i);
			lst.add(c);
			ant.add(2);
		}
		
		T = Integer.parseInt(in.readLine());
		while(T-- > 0) {
			for(int i=0;i<lst.size()-1;i++) {
				int cur = ant.get(i);
				int next = ant.get(i+1);
				
				if(!visited[i] && (cur== 1 && cur != next)) {
					Collections.swap(ant, i, i+1);
					Collections.swap(lst, i, i+1);
					visited[i] = true;
					visited[i+1] = true;
				}
			}
	
			//print();
			Arrays.fill(visited,false);
		}
		
		print();
	}

	

}