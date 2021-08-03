#include<vector>
#include<iostream>
#include<queue>
#define INF 1e9

using namespace std;
vector<pair<int, int>> v[20001];
int arr[20001];
int n, m, start;


void dijkstra(int start) {
	priority_queue<pair<int, int> > pq;
	pq.push({ 0,start });
	arr[start] = 0;
	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (arr[now] < dist) continue;
		for (int i = 0; i < v[now].size(); i++) {
			int cost = dist + v[now][i].second;
			if (cost < arr[v[now][i].first]) {
				arr[v[now][i].first] = cost;
				pq.push(make_pair(-cost, v[now][i].first));
			}
		}
	}
}
int main() {
	cin >> n >> m >> start;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		//a에서 b로 가는 비용이 c
		v[a].push_back({ b,c });
	}
	fill(arr, arr + 20001, INF);

	dijkstra(start);
	for (int i = 1; i <= n; i++) {
		// 도달할 수 없는 경우, 무한(INFINITY)이라고 출력
		if (arr[i] == INF) {
			printf("INF\n");
		}
		// 도달할 수 있는 경우 거리를 출력
		else {
			printf("%d\n", arr[i]);
		}
	}
}