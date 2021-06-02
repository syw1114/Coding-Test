#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 1e9

int n, m, start;
vector <pair<int, int>>v[100001];
int d[100001]; // 최단거리만들기

void dijkstra(int start) {
	priority_queue<pair<int, int> > pq;
	pq.push({ 0,start });
	d[start] = 0;
	while (!pq.empty()) {
		int dist = pq.top().first; // 현재 노드까지의 거리
		int now = pq.top().second;
		pq.pop();
		if (d[now] < dist) continue;
		for (int j = 0; j < v[now].size(); j++) {
			int cost = dist + v[now][j].second;
			if (cost < d[v[now][j].first]) {
				d[v[now][j].first] = cost;
				pq.push(make_pair(cost, v[now][j].first));
			}
		}
	}
}

int main() {
	cin >> n >> m >> start;

	for (int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}

	fill_n(d, 100001, INF);
	
	dijkstra(start);
	for (int i = 1; i <= n; i++) {
		// 도달할 수 없는 경우, 무한(INFINITY)이라고 출력
		if (d[i] == INF) {
			cout << "INFINITY" << '\n';
		}
		// 도달할 수 있는 경우 거리를 출력
		else {
			cout << d[i] << '\n';
		}
	}
}