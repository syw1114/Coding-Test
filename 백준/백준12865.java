import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 백준12865 {
	
	static int dp[];
	static int arr[];
	static int arr2[];
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		
		dp = new int[K+1];
		arr = new int[N];
		arr2 = new int[N];
		
		for(int i = 0; i<N; i++) {
			st = new StringTokenizer(br.readLine()," ");
			
			arr[i] = Integer.parseInt(st.nextToken());
			arr2[i] = Integer.parseInt(st.nextToken());
	
		}
		
		for(int i = 0; i<N; i++) {
			for(int j = K; j - arr[i]>=0; j--) {
				dp[j] = Math.max(dp[j], dp[j - arr[i]] + arr2[i]);
			}
		}
		System.out.println(dp[K]);
	}

}
