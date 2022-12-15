import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class 백준2565 {

	static int[][] arr;
	static int[] dp;
	static int count = 0;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		
		arr = new int[N][2];
		dp = new int[N];
		StringTokenizer st;
		
		for(int i = 0; i<N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			
			arr[i][0] = Integer.parseInt(st.nextToken());
			arr[i][1] = Integer.parseInt(st.nextToken());
			
		}
		//B 전봇대만 비교하기위해 A는 오름차순 정렬
		Arrays.sort(arr, new Comparator<int[]>() {
			public int compare(int[] o1, int[] o2) {
				return o1[0]-o2[0];
			}
		});
		
		for(int i = 0; i<N; i++) {
			dp[i] = 1;
			for(int j = 0; j<i; j++) {
				if((arr[i][1] > arr[j][1])) {
					dp[i] = Math.max(dp[i], dp[j]+1);
				}
			}
		}
		
		for(int i = 0; i<N; i++) {
			if(dp[i] > count) count = dp[i];
		}
		System.out.print(N-count);
	}

}
