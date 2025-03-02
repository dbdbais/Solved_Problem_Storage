import java.util.*;
import java.io.*;

public class Main {
	
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int T,N,M;
	static long ans;
	static int [] nArr, mArr;
	static int [] npArr, mpArr;
	static ArrayList<Integer> lst1,lst2;
	
	static ArrayList<Integer> getAllPatitalList(int[] arr){
		ArrayList<Integer> lst = new ArrayList<Integer>();
		int alen = arr.length-1;
		//System.out.println("alen : "+ alen);
		for(int i=0;i<=alen;i++) {
			for(int j=i+1;j<=alen;j++) {
				int psum = arr[j] - arr[i];
				lst.add(psum);
			}
		}
		return lst;
	}
	
	public static void main(String[] args) throws Exception {
		T = Integer.parseInt(in.readLine());
		N = Integer.parseInt(in.readLine());
		nArr = new int[N+1];
		npArr = new int[N+1];
		st = new StringTokenizer(in.readLine());
		
		for(int i=1;i<=N;i++) {
			nArr[i] = Integer.parseInt(st.nextToken());
			npArr[i] = npArr[i-1] + nArr[i];
			//누적 합
		}
		M = Integer.parseInt(in.readLine());
		mArr = new int[M+1];
		mpArr = new int[M+1];

		st = new StringTokenizer(in.readLine());
		
		for(int i=1;i<=M;i++) {
			mArr[i] = Integer.parseInt(st.nextToken());
			mpArr[i] = mpArr[i-1] + mArr[i];
			// 누적 합
		}
		
		lst1 = getAllPatitalList(npArr);
		lst2 = getAllPatitalList(mpArr);
		
		Collections.sort(lst1);
		Collections.sort(lst2);
		
//		for(int elem : lst1) {
//			System.out.print(elem +" ");
//		}
//		System.out.println();
//		
//		for(int elem : lst2) {
//			System.out.print(elem +" ");
//		}
//		System.out.println();
		
		//정렬하고
		int lend = lst1.size();
		int rend = lst2.size();
		int lidx = 0;
		int ridx = rend-1;
		while(lidx < lend && ridx >=0) {
			//둘 중에 하나롸도 나가면 끝냄
			int lval = lst1.get(lidx);
			int rval = lst2.get(ridx);
			int tsum = lval + rval;
			//System.out.println("lidx : "+ lidx +" ridx : "+ridx);
			
			if(tsum == T) {
				//System.out.println("FOUND! lidx : "+lidx +" ridx : "+ ridx);
				//T값이라면
				long lcnt = 0;
				long rcnt = 0;
				while(lidx< lend) {
					//끝까지 가기 전까지만
					if(lst1.get(lidx) == lval) {
						lcnt++;
						lidx++;
					}
					else {
						break;
					}
				}
				
				while(ridx >= 0) {
					//끝까지 가기 전까지만
					if(lst2.get(ridx) == rval) {
						rcnt++;
						ridx--;
					}
					else {
						break;
					}
				}
				//System.out.println(lcnt+":"+rcnt);
				//System.out.println("GOT : " +(lcnt+rcnt));
				ans += (lcnt*rcnt);
				//중복한거 올림
			}
			else if(tsum > T) {
				//크다면 
				ridx--;
				//우측 하나 감소
			}
			else {
				//작다면
				lidx++;
				//좌측 하나 증가
			}
		}
		
		System.out.println(ans);
		
		
		
	}
	
}