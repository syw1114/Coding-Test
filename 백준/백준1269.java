import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class 백준1269 {
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringBuilder sb = new StringBuilder();
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		HashSet<Integer> set = new HashSet<>();
		HashSet<Integer> set2 = new HashSet<>();
		
		st= new StringTokenizer(br.readLine()," ");
		int sum = 0;
		for(int i = 0; i<N; i++) {
			set.add(Integer.parseInt(st.nextToken()));
		}
		st= new StringTokenizer(br.readLine()," ");
		for(int i =0; i<M; i++) {
			int x = Integer.parseInt(st.nextToken());
			set2.add(x);
			if(!set.contains(x)) {
				sum++;
			}
		}
		set.removeAll(set2);
		
		System.out.println(set.size() + sum);
		
		
	}
}
