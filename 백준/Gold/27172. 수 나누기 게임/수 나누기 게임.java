import java.io.*;
import java.util.*;

/**
 */
public class Main {
	static StringTokenizer st;
	static StringBuilder sb;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	//현재 번호가 몇번에 있는지
	static int N,mx;
	static boolean [] barr;
	static int [] arr = new int[1000001];
	static ArrayList<Integer> lst = new ArrayList<>();
	static Queue<Integer> q = new ArrayDeque<>();

	public static void main(String[] args) throws Exception {

		N = Integer.parseInt(in.readLine());
		st = new StringTokenizer(in.readLine());
		for(int i=0;i<N;i++) {
			int ipt = Integer.parseInt(st.nextToken());
			mx = Math.max(mx, ipt);
			lst.add(ipt);
			q.add(ipt);
		}
		Collections.sort(lst);
		barr = new boolean[mx+1];
		
		for(int elem : lst) {
			barr[elem] = true;
		}
		
		//정렬
		
		for(int elem : lst) {
			//System.out.println(elem);
			for(int i=elem*2;i<=mx;i+=elem) {
				//System.out.println(i);
				if(barr[i]) {
					//System.out.println("divided");
					arr[elem] +=1;
					arr[i]-=1;
				}
			}
		}
		
		sb= new StringBuilder();
		while(!q.isEmpty()) {
			sb.append(arr[q.poll()]+" ");
		}
		
		System.out.println(sb);
		

	}

}