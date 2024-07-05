import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static int N,K;
    static int [][] DP;
    static final int mod = 1000000003;
    static void print(){
        for(int i=0;i<=N;i++){
            for(int j=1;j<=i;j++){
                System.out.print(DP[i][j]+" ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(in.readLine());
        K = Integer.parseInt(in.readLine());
        DP = new int[N + 3][N + 3];
        //N행 N/2열 DP 배열 생성

        DP[1][1] = 1;
        DP[2][1] = 2;
        DP[3][1] = 3;


        for(int i=4;i<=N;i++){
            // i행
            for(int j=1;j<=(i/2);j++){
                // j열

                //  처음이라면
                if(j == 1){
                    DP[i][j] = i;
                }
                //  끝이라면
                else if((j == i/2) && (i % 2 == 0)){
                    DP[i][j] = 2;
                }
                else{
                    //도중이라면
                    DP[i][j] = (DP[i-1][j] + DP[i-2][j-1]) %mod;
                }
            }
        }
        //print();

        System.out.println(DP[N][K]);
    }
}