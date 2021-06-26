#include <iostream>
#include <vector>

using namespace std;
int n;
vector <int> v;

int solution(vector<int>& v, int start, int end) {
	if (start > end )return -1;
	int mid = (start + end) / 2;
	if (v[mid] == mid) return mid;
	else if (v[mid] > mid)
		return solution(v, start, mid - 1);
	else
		return solution(v, mid+1, end - 1);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	int a = solution(v, 0, n - 1);
	cout << a;
}