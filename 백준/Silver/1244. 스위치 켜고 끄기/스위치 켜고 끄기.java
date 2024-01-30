import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {


	static int[] sweetch = new int[101];	

	static void solve(int gender, int number) {
		if(gender == 1) {	//남자일 떄
			
			for(int i=1;i<=T;i++) {
				if(i%number == 0) {
					sweetch[i] ^= 1;
				}
				
			}

		}
		else {	//여자일 때
			int search = 1;
			sweetch[number] ^=1;
			while(true) {

				if(out(number - search) || out(number + search)) break;	//구간 벗어나면 break

				if(sweetch[number+search] != sweetch[number-search] ) break; 

					sweetch[number+search] ^= 1;
					sweetch[number-search] ^= 1;



				search++;	
			}
		}
	}
	static int T;

	static boolean out(int x) {
		return x<1 || x>T;
	}

	public static void main(String[] args) throws Exception {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		// 결과를 한 번에 출력하기 위한 StringBuilder


		int M;
		T = Integer.parseInt(in.readLine());	//스위치의 개수

		st = new StringTokenizer(in.readLine());
		for(int i=1;i<=T;i++) {
			sweetch[i] = Integer.parseInt(st.nextToken());
		}

		M = Integer.parseInt(in.readLine());
		int gender,number;
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(in.readLine());
			gender = Integer.parseInt(st.nextToken());
			number = Integer.parseInt(st.nextToken());
			solve(gender,number);
		}

		for(int i=1; i<=T; i++) {
			System.out.print(sweetch[i] + " ");
			if((i) % 20 == 0)
				System.out.println();
		}


		}



	}
