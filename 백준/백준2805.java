package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 백준2805 {

	public static void main(String[] args)  throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");

		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		
		int arr[] = new int[N];
		
		int max = 0;
		
		st = new StringTokenizer(br.readLine(), " ");
		for(int i = 0; i<N; i++) {
			 arr[i] = Integer.parseInt(st.nextToken());
		
			 if(max<arr[i]) {
				 max = arr[i];
			 }
		}
		
		int min = 0;
		
		
		while(min<max) {
			
			int mid = ( min + max ) / 2;
			long sum = 0;
			
			for(int i = 0; i<arr.length; i++) {
				if(arr[i] - mid > 0) {
					sum += arr[i] - mid;
				}
			}
			if(sum < K) {
				max = mid;
			}
			else {
				min = mid + 1; 
			}
		}
		System.out.print(min-1);
	}

}
