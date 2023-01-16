package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 백준1654 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		
		int arr[] = new int[N];
		
		long max = 0;
		
		for(int i = 0 ; i<N; i++) {
			arr[i] = Integer.parseInt(br.readLine());
			if(max < arr[i]) {
				//입력과 동시에 제일 긴 길이를 max로 지정
				max = arr[i];
			}
		}
		

		
		long min = 1;
		long mid = 0;
		
		while(min <= max) {

			mid = ( min + max ) / 2;
			
			long count = 0;
			
			for(int i = 0; i<arr.length; i++) {
				count += (arr[i] / mid);
			}
			
			if(count < K) {
				max = mid-1;
			}
			else {
				min = mid +1;
			}
		}
		System.out.println(min-1);
	}

}
