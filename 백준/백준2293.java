import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 백준2293 {

	public static void main(String[] args) throws IOException{
			
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			StringTokenizer st = new StringTokenizer(br.readLine()," ");
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			
			int[] arr = new int[N+1];
			int[] dp = new int[M+1];
			
			dp[0] = 1;
			
			for(int i = 1; i<=N; i++) {
				arr[i] = Integer.parseInt(br.readLine());
				for(int j = arr[i]; j<= M; j++) {
					dp[j] += dp[j-arr[i]];
				}
			}
		System.out.print(dp[M]);
	}

}
