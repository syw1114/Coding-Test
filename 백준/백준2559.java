import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 백준2559 {

	static int arr[];
	static int max = 0;
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine(), " ");

		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		arr = new int[N];

		
		st = new StringTokenizer(br.readLine(), " ");
		for(int i = 0 ; i<N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		//N-M까지 돌림.
		for(int i = 0; i<=N-M; i++) {
			int sum = 0;
			//i번째에서부터 + M 까지 돌려서 값을 저장후 최대값 비
			for(int j = i; j<i+M; j++) {
				sum += arr[j];
			}
			max = Math.max(max, sum);
		}
		System.out.print(max);
	}

}
