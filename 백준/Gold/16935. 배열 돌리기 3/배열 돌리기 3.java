import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
	private static StringBuilder sb = new StringBuilder();
	private static StringTokenizer st;
	static int N, M, R;
	static int [][] arr;
	static int [] oper;

	static void op1() {
		int n = arr.length;
		int m = arr[0].length;
		for(int i=0;i<m;i++) {
			Stack<Integer> stk = new Stack<>();
			for(int j=0;j<n;j++) {	//한 줄 입력받고
				stk.add(arr[j][i]);
			}
			for(int j =0 ;j<n;j++) {
				arr[j][i] = stk.pop();
			}
		}
	}
	static void op2() {
		int n = arr.length;
		int m = arr[0].length;
		for(int i=0;i<n;i++) {
			Stack<Integer> stk = new Stack<>();
			for(int j=0;j<m;j++) {	//한 줄 입력받고
				stk.add(arr[i][j]);
			}
			for(int j =0 ;j<m;j++) {
				arr[i][j] = stk.pop();
			}
		}
	}
	
	static void op3() {
		int [][] temp;
		int n = arr.length;	//행의 수
		int m = arr[0].length;	//열의 수
		
		temp = new int[m][n];	//바꿀 배열

		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++) {
				temp[i][j]= arr[n-1-j][i];
			}
		}
		arr = temp;
	}
	
	static void op4() {
		int [][] temp;
		int n = arr.length;	//행의 수
		int m = arr[0].length;	//열의 수
		
		temp = new int[m][n];	//바꿀 배열

		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++) {
				temp[i][j]= arr[j][m-1-i];
			}
		}
		arr = temp;
	}
	static void op5() {
		int n = arr.length;	//행의 수
		int m = arr[0].length;	//열의 수
		int xx = n/2;	//행/2
		int yy = m/2;	//열/2
		int [][] first = new int[n/2][m/2];
		int [][] second = new int[n/2][m/2];
		int [][] third = new int[n/2][m/2];
		int [][] fourth = new int[n/2][m/2];
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(i < xx && j <yy) {	//1사분면
					first[i][j] = arr[i][j];
				}
				else if(i<xx && j >=yy) {	//2사분면
					second[i][j-yy] = arr[i][j];
				}
				else if(i>=xx && j <yy) {	//3사분면
					third[i-xx][j] = arr[i][j];
				}
				else {		//4사분면
					fourth[i-xx][j-yy] = arr[i][j];
				}
			}
		}
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(i < xx && j <yy) {	//1사분면
					arr[i][j] = third[i][j];
				}
				else if(i<xx && j >=yy) {	//2사분면
					arr[i][j] = first[i][j-yy];
				}
				else if(i>=xx && j <yy) {	//3사분면
					arr[i][j] = fourth[i-xx][j];
				}
				else {		//4사분면
					arr[i][j] = second[i-xx][j-yy];
				}
			}
		}
		
	
		
		
		
	}
	
	static void op6() {
		int n = arr.length;	//행의 수
		int m = arr[0].length;	//열의 수
		int xx = n/2;	//행/2
		int yy = m/2;	//열/2
		int [][] first = new int[n/2][m/2];
		int [][] second = new int[n/2][m/2];
		int [][] third = new int[n/2][m/2];
		int [][] fourth = new int[n/2][m/2];
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(i < xx && j <yy) {	//1사분면
					first[i][j] = arr[i][j];
				}
				else if(i<xx && j >=yy) {	//2사분면
					second[i][j-yy] = arr[i][j];
				}
				else if(i>=xx && j <yy) {	//3사분면
					third[i-xx][j] = arr[i][j];
				}
				else {		//4사분면
					fourth[i-xx][j-yy] = arr[i][j];
				}
			}
		}
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(i < xx && j <yy) {	//1사분면
					arr[i][j] = second[i][j];
				}
				else if(i<xx && j >=yy) {	//2사분면
					arr[i][j] = fourth[i][j-yy];
				}
				else if(i>=xx && j <yy) {	//3사분면
					arr[i][j] = first[i-xx][j];
				}
				else {		//4사분면
					arr[i][j] = third[i-xx][j-yy];
				}
			}
		}
		
	}
	
	
	static void print() {
		for(int i=0;i<arr.length;i++) {
			for(int j=0;j<arr[0].length;j++) {
				System.out.print(arr[i][j]+" ");
			}
			System.out.println();
		}
	}


	public static void main(String[] args) throws Exception {
		/**
		 * 0. 입력파일 읽어들이기
		 */
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		arr = new int[N][M];
		oper = new int[R];
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(in.readLine());
			for(int j=0;j<M;j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());	
			}
		}

		st = new StringTokenizer(in.readLine());
		for(int i=0;i<R;i++) {	//연산 개수 입력 받음
			oper[i] = Integer.parseInt(st.nextToken());
		}
		
		for(int i : oper) {
			switch(i) {
			case 1:
				op1();
				break;
			case 2:
				op2();
				break;
			case 3:
				op3();
				break;
			case 4:
				op4();
				break;
			case 5:
				op5();
				break;
			case 6:
				op6();
				break;
			}
		}
		
		print();



	}
}