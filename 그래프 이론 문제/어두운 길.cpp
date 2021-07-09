#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int,pair<int, int>>>v;
int n,m;
int arr[10001];
int result;
int findparent(int x) {
	if (arr[x] == x)
		return x;
	return findparent(arr[x]);
}
void union_parent(int a, int b) {
	a = findparent(a);
	b = findparent(b);
	if (a < b) arr[b] = a;
	else arr[a] = b;
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ c, { a,b } });
	}

	sort(v.begin(), v.end());
	int total = 0;
	for (int i = 0; i < v.size(); i++) {
		int cost = v[i].first;
		int a = v[i].second.first;
		int b = v[i].second.second;
		total += cost;
		//사이클이 돌지않는 경우에만 집합에 포함.
		if (findparent(a) != findparent(b)) {
			union_parent(a, b);
			result += cost;
		}
	}
	cout << total - result;
}