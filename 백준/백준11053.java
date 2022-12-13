import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 백준11053 {

	static int dp[];
	static int arr[];
	static int count = 0;

	
	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		
		arr = new int[N];
		dp = new int[N];
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		for(int i = 0; i<N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		for(int i = 0; i < N; i++) {
			dp[i] = 1;
			for(int j = 0; j < i; j++) {
				if(arr[j] < arr[i] && dp[i] < dp[j]+1) {
					dp[i] = dp[j]+1;
				}
			}
		}
		for(int i = 0; i < N; i++) {
			if(dp[i] > count) count = dp[i];
		}
		System.out.print(count);
	}

}
