#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector < pair<int, pair<int, int>>> v;
int arr[100001];
int n;
int result;
int findparent(int x) {
	if (arr[x] == x)
		return x;
	else
		findparent(arr[x]);
}
void union_find(int a, int b) {
	a = findparent(a);
	b = findparent(b);
	if (a < b) arr[b] = a;
	else arr[a] = b;
}
int main() {
	cin >> n;
	//부모는 자기자신으로 초기화.
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}
	vector<pair<int, int>>x;
	vector<pair<int, int>>y;
	vector<pair<int, int>>z;
	for (int i = 1; i <= n; i++) {
		int a,b, c;
		cin >> a>> b >> c;
		x.push_back({ a,i });
		y.push_back({ b,i });
		z.push_back({ c,i });		
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	sort(z.begin(), z.end());

	for (int i = 0; i < n - 1; i++) {
		v.push_back({ x[i + 1].first - x[i].first, {x[i + 1].second, x[i].second }});
		v.push_back({ y[i + 1].first - y[i].first,{y[i + 1].second, y[i].second } });
		v.push_back({ z[i + 1].first - z[i].first,{z[i + 1].second,z[i].second} });
	}
	//간선을 비용순으로 정렬.
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		int cost = v[i].first;
		int a = v[i].second.first;
		int b = v[i].second.second;
		//사이클 돌지않을경우에만 집합에 포함.
		if (findparent(a) != findparent(b)) {
			union_find(a, b);
			result += cost;
		}
	}
	cout << result;
}