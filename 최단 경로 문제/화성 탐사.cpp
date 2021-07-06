#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9


using namespace std;
int test;
int n;
int graph[125][125], d[125][125];
//╩С го аб ©Л
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };


int main() {
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> graph[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			fill(d[i], d[i] + 125, INF);
		}
		int x = 0, y = 0;
		priority_queue<pair<int, pair<int, int>>> qp;
		qp.push({ -graph[x][y],{0,0} });
		d[x][y] = graph[x][y];

		while (!qp.empty()) {
			int now = -qp.top().first;
			int x = qp.top().second.first;
			int y = qp.top().second.second;
			qp.pop();
			if (d[x][y] < now) continue;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
				int cost = now + graph[nx][ny];
				if (cost < d[nx][ny]) {
					d[nx][ny] = cost;
					qp.push({ -cost, {nx, ny} });
				}
			}
		}
		cout << d[n - 1][n - 1] << '\n';
	}
}