import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 백준11054 {
	
	static int arr[];
	static int dp[];
	static int dp2[];
	static int count = 0;
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		
		
		arr = new int[N];
		dp = new int[N];
		dp2 = new int[N];
		
		
		for(int i = 0; i<N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		for(int i = 0; i<N; i++) {
			dp[i] = 1;
			for(int j = 0; j<i; j++) {
				if(arr[i] > arr[j] && dp[i] < dp[j]+1) {
					dp[i] = dp[j]+1;
				}
			}
		}
		for(int i = N-1; i>=0; i--) {
			dp2[i] = 1;
			for(int j = i; j<N; j++) {
				if(arr[i] > arr[j] && dp2[i] < dp2[j]+1) {
					dp2[i] = dp2[j]+1;
				}
			}
		}
		for(int i = 0; i<N; i++) {
			dp[i] = (dp[i] + dp2[i])-1;
			if(dp[i] > count) {
				count = dp[i];
			}
		}
		System.out.print(count);
			
	}

}
