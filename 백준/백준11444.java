import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 백준11444 {

	static long[][] arr = {{1,1}, {1,0}};
	static long P = 1000000007;
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		Long N = Long.parseLong(br.readLine());
		
		System.out.print(solution(arr,N-1)[0][0]);
	}
	static long[][] solution(long[][] arr, Long N) {
		if(N <= 1) {
			return arr;
		}
		
		long[][] result = solution(arr, N/2);
		
		result = calculate(result,result);
		
		if(N % 2 == 1L) {
			result = calculate(result,arr);
		}
		return result;
	}
	
	static long[][] calculate(long[][] A, long[][] B){
		long[][] result = new long[2][2];
		
		for(int i = 0; i<2; i++) {
			for(int j = 0; j<2; j++) {
				for(int k = 0; k<2; k++) {
					result[i][j] += (A[i][k] * B[k][j]) % P;
					result[i][j] %= P;
				}
			}
		}
		return result;
	}
}
