#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v; // °¡°Ô ¶±.
int n, m;


bool comp(int a, int b) {
	return a > b;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end(), comp);
	int start = 0;
	int end = v[0];
	int result = 0;

	while (start <= end) {
		int sum = 0;
		int mid = (start + end) / 2;
		for (int i = 0; i < n; i++) {
			if (v[i] > mid)
				sum += v[i] - mid;
		}
		if (sum < m)
			end = mid - 1;

		else {
			result = mid;
			start = mid + 1;
		}
	}
	cout << result;
}
