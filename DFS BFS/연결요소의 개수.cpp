#include<iostream>
#include<vector>

using namespace std;

vector<pair<int, int>> v;
int arr[1001];
int n, m;
int findparent(int x) {
	if (x == arr[x]) return x;
	return arr[x] = findparent(arr[x]);
}
void unionparent(int a, int b) {
	a = findparent(a);
	b = findparent(b);
	if (a < b) arr[b] = a;
	else arr[a] = b;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <=n; i++) {
		arr[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	int result = 0;
	for (int i = 0; i < v.size(); i++) {
		int a = v[i].first;
		int b = v[i].second;
		if (findparent(a) != findparent(b)) {
			unionparent(a, b);
			result += 1;
		}
	}
	cout << n - result;
}
