import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 백준10830 {

	static int arr[][];
	static int P = 1000;
	static int N;
	public static void main(String[] args)throws IOException {
 
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		N = Integer.parseInt(st.nextToken());
		Long B = Long.parseLong(st.nextToken());
		
		arr = new int[N][N];
		
		for(int i = 0; i<N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for(int j = 0; j<N; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken()) % P;
			}
		}
		
		int[][] result = solution(B);
		
		for(int i = 0; i<N; i++) {
			for(int j = 0; j<N; j++) {
				sb.append(result[i][j]).append(" ");
			}
			sb.append('\n');
		}
		System.out.print(sb);
	}
	static int[][] solution(Long count) {
		if(count == 1) {
			return arr;
		}
		int[][] result = solution(count / 2);
		
		if(count%2 == 0) {
			return calculate(result,result);
		}
		else {
			int[][] result2 = calculate(result, arr);
			return calculate(result, result2);
		}
	}
	static int[][] calculate(int[][] arr, int[][] B){
		int[][] tmp = new int[N][N];
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j<N; j++) {
				for(int k = 0; k<N; k++) {
					tmp[i][j] += (arr[i][k] * B[k][j]) % P;
				}
				tmp[i][j] %= P;
			}
		}
		return tmp;
	}
}

