#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>v,int k, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;
		if (v[mid] == k)
			return mid;
		else if (v[mid] > k) {
			end = mid - 1;
		}
		else
			start = mid + 1;

	}
}

int n, k;
vector<int>v;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	int result = search(v, k, 0, n-1);
	if (result == -1) {
		cout << "원소가 존재하지 않습니다." << endl;
	}
	else
		cout << result + 1 << endl;
}