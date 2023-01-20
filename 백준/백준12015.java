package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class 백준12015 {
	
	static int arr[];
	
	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());

		arr = new int[N]; // 초반 수열을 담는 배열.
		List<Integer> list = new ArrayList<>();
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		for(int i = 0; i<N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		list.add(arr[0]);
		int count = 1; // 추가되면 count증가.
		
		for(int i = 1; i<N; i++) {
			int value = arr[i];
			
			if(list.get(count-1) < value) {
				count++;
				list.add(value);
			} else {
				int left = 0;
				int right = count;
				
				while(left < right) {
					int mid = (left + right) / 2;
					
					if(list.get(mid) < value) {
						left = mid + 1;
					}else {
						right = mid;
					}
				}
				list.set(left,value);
			}
		}
		System.out.println(count);
	}

}
