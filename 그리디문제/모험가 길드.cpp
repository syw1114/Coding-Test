#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <int> v;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	int result = 0; // 그룹수
	int count = 0;
	for (int i = 0; i < n; i++) { //공포도가 낮은 모험가부터 확인.
		count += 1; 
		if (count >= v[i]) {
			result += 1;
			count = 0; // 모험가가 그룹에 포함되었으니 모험가수 초기화.
		}
	}
	cout << result;
}