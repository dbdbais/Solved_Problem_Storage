import java.io.*;
import java.util.*;
import java.awt.*;

class Main {
	
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N,M;
	static ArrayList<Integer>[] lst;
	static HashSet<Integer> set;
	static int[][] compressedNums;
	public static void main(String[] args) throws IOException {
		
		st = new StringTokenizer(in.readLine());
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		lst = new ArrayList[M];
		
		int [][] arr = new int[M][N];
		
		for(int i=0;i<M;i++) {
			set = new HashSet<>();
			st = new StringTokenizer(in.readLine());
			
			for(int j=0;j<N;j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				set.add(arr[i][j]);
			}
			
			lst[i]= new ArrayList<>(set);
			//새로운 리스트
			Collections.sort(lst[i]);
			//정렬
		}
		
		compressedNums = new int[M][N];
		
		for(int i=0;i<M;i++) {
			//System.out.println(lst[i].toString());
			for(int j=0;j<N;j++) {
				compressedNums[i][j] = Collections.binarySearch(lst[i], arr[i][j]);
				//System.out.print(compressedNums[i][j]+" ");
			}
			//System.out.println();
		}
		
		int cnt = 0;
		
		for(int i=0;i<M;i++) {
			for(int j=i+1;j<M;j++) {
				if(Arrays.equals(compressedNums[i],compressedNums[j])) cnt++;
			}
		}
		
		System.out.println(cnt);
		
	}
}