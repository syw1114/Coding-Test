package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class 백준2110 {

	static ArrayList<Integer> arr = new ArrayList<>();
	
	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		
		int N = Integer.parseInt(st.nextToken());
		int C = Integer.parseInt(st.nextToken());
	
		
		
		for(int i = 0; i<N; i++) {
			arr.add(Integer.parseInt(br.readLine()));
		}
		
		Collections.sort(arr);
		
		int min = 1;
		int max = arr.get(N-1) - arr.get(0) + 1;
		
		while(min < max) {
			int mid = (min + max) / 2;
			
			if(solution(mid) < C) {
				max = mid;
			}else
				min = mid + 1;
		}
		System.out.print(min-1);
		
	}
	static int solution(int mid) {
		int count = 1;
		int last = arr.get(0);
		
		for(int i = 0; i< arr.size(); i++) {
			int locate = arr.get(i);
			
			if(locate - last >= mid) {
				count++;
				last = locate;
			}
		}
		return count;
	}

}
