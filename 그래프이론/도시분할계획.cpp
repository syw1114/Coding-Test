#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
int d[100001];
vector<pair<int, pair<int, int>>> v;
int result = 0;

int findparent(int x) {
	if (d[x] == x) {
		return x;
	}
	return d[x] = findparent(d[x]);
}

void unionparent(int a, int b) {
	a = findparent(a);
	b = findparent(b);

	if (a < b)
		d[b] = a;
	else
		d[a] = b;
}
int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		d[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ c, { a,b } });
	}
	sort(v.begin(), v.end());
	int last = 0;
	for (int i = 0; i < v.size(); i++) {
		int cost = v[i].first;
		int a = v[i].second.first;
		int b = v[i].second.second;
		if (findparent(a) != findparent(b)) {
			unionparent(a, b);
			result += cost;
			last = cost;
		}

	}
	cout << result - last << result << last;
}