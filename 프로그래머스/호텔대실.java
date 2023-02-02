import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class 호텔대실 {
	
	public static void main(String[] args) {
		
		String[][] book_time = {
				{"15:00","17:00"}, {"16:40", "18:20"}, 
				{"14:20", "15:20"}, {"14:10","19:20"}, {"18:20","21:20"}
				};

		class Book{
			int start_time;
			int end_time;
			
			Book(int start_time, int end_time){
				this.start_time = start_time;
				this.end_time = end_time;
			}
		}
		
		
		ArrayList<Book> bookList = new ArrayList<>();
		
		for(int i = 0; i<book_time.length; i++) {
			int start_time = conversions(book_time[i][0]);
			int end_time = conversions(book_time[i][1]);
		
			bookList.add(new Book(start_time,end_time));
		} 
		
		Collections.sort(bookList, (o1,o2) -> {
			if(o1.start_time == o2.start_time) 
				return o1.end_time - o2.end_time;
			else
				return o1.start_time - o2.start_time;
		});
		
		List<Integer> endTimeList = new ArrayList<>();
		
		for(int i = 0; i<bookList.size(); i++) {
			boolean check = false;
			for(int j = 0; j<endTimeList.size(); j++) {
					int endTime = endTimeList.get(j) + 10;
					if(bookList.get(i).start_time >= endTime) {
						endTimeList.set(j, bookList.get(i).end_time);
						check = true;
						break;
					}
				}
			if(!check) {
				endTimeList.add(bookList.get(i).end_time);
			}
		}
		System.out.print(endTimeList.size());
	}
	
	static int conversions(String time) {
		
		StringTokenizer st = new StringTokenizer(time,":");
		int hour = Integer.parseInt(st.nextToken());
		int minute = Integer.parseInt(st.nextToken());
		
		return hour*60+minute;
	}

}
