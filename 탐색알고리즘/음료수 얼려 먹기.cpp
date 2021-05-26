#include <iostream>
#include <vector>
using namespace std;

int graph[1000][1000];
int n, m;

bool dfs(int x, int y) {
	if (x <= -1 || x >= n || y <= -1 || y >= m) { // 범위를 벗어나면 종료.
		return false;
	}

	if (graph[x][y] == 0) {
		graph[x][y] = 1; // 현재 노드를 아직 방문하지 않았다면 현재노드 방문처리.
		//상하좌우 위치 모두 재귀호출.
		dfs(x - 1, y);
		dfs(x, y - 1);
		dfs(x + 1, y);
		dfs(x, y + 1);
		return true;
	}
	return false;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dfs(i, j)) {
				result += 1;
			}
		}
	}
	cout << result;

}
