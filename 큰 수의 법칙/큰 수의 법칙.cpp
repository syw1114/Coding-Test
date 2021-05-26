#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a, b, c;
vector<int> v;

int main() {
	
	cin >> a >> b >> c;  // 공백으로 구분하여 입력받기.

	for (int i = 0; i < a; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end()); // 입력받은 수들 정렬.
	int first = v[a - 1];
	int second = v[a - 2];

	int count = b / c; // 두번째로 큰수가 더해지는 횟수 계산
	int sum = (b / c) * c; // 큰수가 더해지는 횟수 계산.

	int result = 0;

	result += first * sum; // 가장큰수 더하기.  
	result += second * count; // 두번째로 큰수 더하기.

	cout << result << endl;
}