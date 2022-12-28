import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class 백준1021 {
	
	static LinkedList<Integer> q = new LinkedList<>();
	static int arr[];
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int count = 0;
		
		arr = new int[M];
		
		for(int i = 1; i<=N; i++) {
			q.add(i);
		}
		st = new StringTokenizer(br.readLine()," ");
		for(int i = 0; i<M; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		for(int i = 0; i<M; i++) {
			int x = q.indexOf(arr[i]);
			int halfx;
			if(q.size() % 2 == 0) {
				halfx = q.size()/2 -1;
			}else {
				halfx = q.size()/2;
			}
			//중간이거나 앞인경우
			if(x <= halfx) {
				for(int j = 0; j<x; j++) {
					int temp = q.removeFirst();
					q.addLast(temp);
					count++;
				}
			}
			//중간보다 뒤에있는경우
			else {
				for(int j = x; j<q.size(); j++) {
					int temp = q.removeLast();
					q.addFirst(temp);
					count++;
				}
			}
			q.removeFirst();
		}
		System.out.print(count);
	}
}
