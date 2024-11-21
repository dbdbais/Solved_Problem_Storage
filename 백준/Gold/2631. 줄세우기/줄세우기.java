import java.util.*;
import java.awt.*;
import java.io.*;

public class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static ArrayList<Integer> lst;
	static int [] arr;
	static int N, mxLen;
	
	static int binarySearch(int num) {
		int idx = Collections.binarySearch(lst, num);
		
		if(idx < 0) {
			return idx * -1 -1; 
		}
		else {
			return idx;
		}	
	}
	
	static void print() {
		for(int elem : lst) {
			System.out.print(elem +" ");
		}
		System.out.println();
	}
	
	public static void main(String[] args) throws Exception {
		N = Integer.parseInt(in.readLine());
		arr = new int[N];
		lst = new ArrayList<Integer>();
		
		for(int i=0;i<N;i++) {
			arr[i] = Integer.parseInt(in.readLine());
		}
		
		for(int i=0;i<N;i++) {
			
			if(lst.isEmpty() || lst.get(lst.size()-1) < arr[i]) {
				//System.out.println("ADD NEW");
				lst.add(arr[i]);
				//비어 있거나, 맨 뒤에 보다 배열의 값이 크다면 뒤에 추가
			}
			else {
				//System.out.println("SWITCH");
				lst.set(binarySearch(arr[i]), arr[i]);
				//해당하는 곳 바꿈
			}
			//print();
		}
		System.out.println(N - lst.size());
		
	}
}