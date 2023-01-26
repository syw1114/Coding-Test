import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 백준11066 {

	public static void main(String[] args) throws Exception {
		
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st;
        
        int t = Integer.parseInt(br.readLine());
        
        for(int i = 0; i<t; i++) {
        	int k = Integer.parseInt(br.readLine());
        	int[] arr = new int[k]; // 입력 배열 저장.
        	
        	st = new StringTokenizer(br.readLine(), " ");
        	
        	for(int j = 0; j<k; j++) {
        		arr[j] = Integer.parseInt(st.nextToken());
        	}
        	int[] sum = new int[k]; // a ~ 합계 저장.
        	
        	sum[0] = arr[0];
        	
        	for(int j = 1; j<k; j++) {
        		sum[j] = sum[j-1] + arr[j];
        	}
        	System.out.println(solution(arr,sum));
        }
	}
	static int solution(int[] arr, int[] sum) {
		int[][] dp = new int[arr.length][arr.length];
		
		for(int i = 0; i<arr.length-1; i++) {
			dp[i][i+1] = arr[i] + arr[i+1];
		}
		
		for(int i = 2; i<dp.length; i++) {
			for(int j = 0; i+j<dp.length; j++ ) {
				 for(int k = j; k<i+j; k++) {
					 if(dp[j][i+j] == 0) {
						 
					 dp[j][i+j] = dp[j][k] + dp[k+1][i+j] + divide(sum,j,j+i);
					 
					 } else {
						 dp[j][i+j] = Math.min(dp[j][i+j], dp[j][k] + dp[k+1][j+i] + divide(sum, j, j+i));
					 }
				 }
			}
		}
		return dp[0][dp.length-1];
	}
	static int divide(int[] sum, int start, int end) {
		if(start == 0) {
			return sum[end];
		}
		
		return sum[end] - sum[start-1];
	}

}
