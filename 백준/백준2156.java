import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 백준2156 {

	static int dp[];
	static int arr[];
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		dp = new int[10001];
		arr = new int[10001];
		
		for(int i = 1; i<=N; i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}
		dp[1] = arr[1];
		dp[2] = arr[1] + arr[2];
		
		for(int i = 3; i<=N; i++) {
			dp[i] = Math.max(dp[i-3] + arr[i-1] + arr[i], dp[i-2]+arr[i]);
			dp[i] = Math.max(dp[i-1], dp[i]);
		}
		System.out.print(dp[N]);
	}
	
}
