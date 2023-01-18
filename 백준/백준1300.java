package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class 백준1300 {


	
	
	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		int K = Integer.parseInt(br.readLine());
		
		int left = 1;
		int right = K;
		
		while(left < right) {
			int mid = (left+right) / 2;
			
			long count = 0;
			
			for(int i = 1; i<=N; i++) {
				count += Math.min(mid/i , N);
			}
			
			if(count < K) {
				left = mid+1;
			}else {
				right = mid;
			}
		}
		System.out.print(right);
	}

}
