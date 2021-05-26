#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int result = 0;
vector<int>v;
vector<int>q;

bool comp(int a, int b) {
	return a < b;
}
bool comp1(int a, int b) {
	return a > b;
}

int main() {
	cin >> n >> k;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			v.push_back(x);
		}
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			q.push_back(x);
		}
		sort(v.begin(), v.end(), comp);
		sort(q.begin(), q.end(), comp1);
		for (int i = 0; i < k; i++) {
			swap(v[i], q[i]);
		}
		for (int i = 0; i < n; i++) {
			result += v[i];
		}
		cout << result;
}