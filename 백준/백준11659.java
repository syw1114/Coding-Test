import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 백준11659 {
	
	static int arr[];

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		// 시간 초
//		arr = new int[N+1];
//		st = new StringTokenizer(br.readLine(), " ");
//		for(int i = 1; i<=N; i++) {
//			arr[i] = Integer.parseInt(st.nextToken());
//		}
//		for(int i = 0; i<M; i++) {
//			st = new StringTokenizer(br.readLine(), " ");
//			int a = Integer.parseInt(st.nextToken());
//			int b = Integer.parseInt(st.nextToken());
//			
//			int sum = 0;
//			for(int j = a; j<=b; j++) {
//				sum += arr[j];
//			}
//			System.out.println(sum);
//		}
//	}
		arr = new int[N+1];
		st = new StringTokenizer(br.readLine(), " ");
		for(int i = 1; i<=N; i++) {
			//누적합 구하
			arr[i] = arr[i-1] + Integer.parseInt(st.nextToken());
		}
		for(int i = 0; i<M; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			//b-(a-1) 하면 a-b까지의 합이 구해짐.
			System.out.println(arr[b] - arr[a-1]);
		}
		
	}
}
