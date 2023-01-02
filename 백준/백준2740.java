import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 백준2740 {

	static int arr[][];
	static int arr2[][];
	
	public static void main(String[] args) throws IOException {
 
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		arr = new int[N][M];
		
		for(int i = 0; i<N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for(int j = 0; j<M; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		st = new StringTokenizer(br.readLine(), " ");

		st.nextToken();
		int K = Integer.parseInt(st.nextToken());
		arr2 = new int[M][K];
		
		for(int i = 0; i<M; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for(int j = 0; j<K; j++) {
				arr2[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		for(int i = 0; i<N; i++) {
			for(int j = 0; j<K; j++) {
				int sum = 0;
				for(int k = 0; k<M; k++) {
					sum += arr[i][k] * arr2[k][j];
				}
				sb.append(sum).append(' ');
			}
			sb.append('\n');
		}
		System.out.println(sb);
	}
}
