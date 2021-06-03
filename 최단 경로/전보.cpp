#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 1e9

int n, m, c;
vector<pair<int, int>> v[100001];
int d[100001];

void dijkstra(int c) {
	priority_queue<pair<int, int> > pq;
	pq.push({ 0,c });
	d[c] = 0;
	while (!pq.empty()) {
		int dist = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (d[now] < dist) continue;
		for (int i = 0; i < v[now].size(); i++) {
			int cost = dist + v[now][i].second;
			if (cost < d[v[now][i].first]) {
				d[v[now][i].first] = cost;
				pq.push(make_pair(cost, v[now][i].first));
			}
		}
	}
}

int main() {
	cin >> n >> m >> c;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v[x].push_back({ y,z });
	}

	fill(d, d+100001, INF);

	dijkstra(c);

	int count = 0;
	int maxdistance = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] != INF) {
			count++;
			maxdistance = max(d[i], maxdistance);
		}
	}
	cout << count-1 << ' ' << maxdistance;
}