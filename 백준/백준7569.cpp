#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
int n, m, h;
int graph[101][101][101];
int dist[101][101][101];
int result = 0;
int dz[6] = { 0,0,0 ,0,-1,1 }; // 상,하,우,좌,위,아래
int dx[6] = { 0,0 ,1,-1,0,0 };
int dy[6] = { -1,1,0,0,0,0 };

int main() {
	cin >> n >> m >> h;
	queue<pair<pair<int, int>, int>>q;
	for (int a = 0; a < h; a++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
					cin >> graph[a][i][j];
					if (graph[a][i][j] == 1) {
						q.push({ {a,i},j});
					}
					if (graph[a][i][j] == 0)
						dist[a][i][j] = -1;
			}
		}
	}
	while (!q.empty()) {
		pair<pair<int, int>, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nz = cur.first.first + dz[i];
			int nx = cur.first.second + dx[i];
			int ny = cur.second + dy[i];
			if (nz >= 0 && nz < h && nx >= 0 && nx < m && ny >= 0 && ny < n && dist[nz][nx][ny] < 0) {
				dist[nz][nx][ny] = dist[cur.first.first][cur.first.second][cur.second] + 1;
				q.push({ { nz,nx}, ny });
			}
		}
	}
	for (int a = 0; a < h; a++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (dist[a][i][j] == -1) {
					cout << -1;
					return 0;
				}
				result = max(result, dist[a][i][j]);
			}
		}
	}
	cout << result;
}