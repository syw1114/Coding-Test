#include <iostream>
using namespace std;

int main() {
	int x, y;
	int result;
	cin >> x >> y;

	for (int i = 0; i < x; i++) {
		int min_value = 10001;
		for (int j = 0; j < y; j++) {
			int x;
			cin >> x;
			min_value = min(min_value, x);  // 최소값과 비교해 더 작으면 최소값에
		}
		result = max(min_value, result); //작은수들 중에서 비교해 더 큰것을 결과값에 저장. 
	}
	cout << result;
}