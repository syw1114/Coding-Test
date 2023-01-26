import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 백준11049 {

	static int[][] arr;
	static int[][] dp;
	
	public static void main(String[] args) throws Exception {
		
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        
        arr = new int[N][2];
        dp = new int[N][N];
        
        StringTokenizer st;
        for(int i = 0; i<N; i++) {
        	st = new StringTokenizer(br.readLine(), " ");
        	int x = Integer.parseInt(st.nextToken());
        	int y = Integer.parseInt(st.nextToken());
        	
        	arr[i][0] = x;
        	arr[i][1] = y;
        }
        for(int i = 0; i<N; i++) {
        	for(int j = 0; j<N; j++) {
        		if(i == j) {
        			dp[i][j] = 0;
        		}else {
        			dp[i][j] = Integer.MAX_VALUE;
        		}
        	}
        }
        for(int i = 1; i<N; i++) {
        	for(int j = 0; j+i<N; j++) {
        		solution(j,j+i);
        	}
        }
       System.out.print(dp[0][N-1]);
	}
	static void solution(int start,int end) {
    	for(int i = start; i<end; i++) {
    		dp[start][end] = Math.min(dp[start][end], dp[start][i] + dp[i+1][end] + arr[start][0] * arr[i][1] * arr[end][1]);
    	}
    }

}
