import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 백준1920 {

	static int arr[];
	
	public static void main(String[] args) throws IOException  {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int N = Integer.parseInt(br.readLine());
		arr = new int[N];
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		for(int i = 0; i<N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		//배열은 정렬되어있어야함.
		Arrays.sort(arr);
		
		int M = Integer.parseInt(br.readLine());
		
		st = new StringTokenizer(br.readLine(), " ");
		
		for(int i = 0; i<M; i++) {
			
			if(solution(Integer.parseInt(st.nextToken()))>=0) {
				sb.append(1).append('\n');
			}else
				sb.append(0).append('\n');
		}
		
		System.out.print(sb);
	}
	
	static int solution(int num) {
		
		int begin = 0;
		int end = arr.length - 1;
		
		while(begin <= end) {
			int mid = (begin + end) / 2;
			
			//num값이 중간값보다 작을경우에 탐색범위를 중간보다 작게잡음.
			if(num < arr[mid]) {
				end = mid - 1;
			}
			//num값이 중간값보다 큰 경우에 탐색범위 첫 시작을 중간값보다 크게.
			else if(num > arr[mid]) {
				begin = mid + 1;
			}
			//중간값과 찾고자하는 값이 같은경우에 바로 리턴.
			else {
				return mid;
			}
		}
		//찾고자하는 값이없는경우에는 종료.
		return -1;
	}
	
}
