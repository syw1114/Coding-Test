import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 백준10844 {

	static Long dp[][];
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		
		dp = new Long[N+1][10]; 
		
		for(int i = 1; i<=9; i++) {
			dp[1][i] = 1L;
		}
		
		dp[1][0] = 0L;
		
		for(int i = 2; i<=N; i++) {
			for(int j = 0; j<=9; j++) {
				if( j == 0) {
					dp[i][j] = dp[i-1][j+1] % 1000000000 ; 
				}else if( j == 9) {
					dp[i][j] = dp[i-1][j-1] % 1000000000;
				}else {
					dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])  % 1000000000;
				}
			}
		}
		Long result = 0L;
		
		for(int i = 0; i<=9; i++) {
			result += dp[N][i];
		}
		System.out.print(result % 1000000000);
	}
	
}
