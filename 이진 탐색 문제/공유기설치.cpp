#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
vector<int> v;

int main() {
	cin >> n >> c;
	//전체 집 좌표 정보를 입력받기.
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	//이진 탐색 수행을 위해 정렬 수행.
	sort(v.begin(), v.end());

	int start = 1; // 가능한 최소 거리.
	int end = v[n-1] -v[0]; // 가능한 최대 거리.
	int result = 0;
	while (start <= end) {
		// mid는 가장 인접한 두 공유기 사이의 거리.
		int mid = (start + end) / 2;
		//첫째집은 무조건 공유기를 설치한다고 가정.
		int count = 1;
		int value = v[0];
		//현재 mid값을 이용해 공유기를 설치.
		for (int i = 1; i < n; i++) {
			if (v[i] >= value + mid) { // 앞에서부터 차근차근 설치.
				value = v[i];
				count += 1;
			}
		}
		//c개 이상의 공유기를 설치할 수 있는 경우 거리를 증가.
		if (count >= c) {
			start = mid + 1;
			result = mid;
		}
		//c개 이상의 공유기를 설치할 수 없는 경우, 거리를 감소.
		else {

			end = mid - 1;
		}
	}
	cout << result;
}