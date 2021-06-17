#include <iostream>
#include <vector>

using namespace std;
int n, m;
int graph[10][10]; // ÃÊ±â¸Ê
int v[10][10]; // º® ¼³Ä¡ÇÑ µÚ ¸Ê.
int result = 0;
// »ó ÇÏ ¿ì ÁÂ
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };


void virus(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (v[nx][ny] == 0) {
				v[nx][ny] = 2;
				virus(nx, ny);
			}
		}
	}
}

int getscore() {
	int score = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 0) {
				score += 1;
			}
		}
	}
	return score;
}
void dfs(int count) {
	if (count == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				v[i][j] = graph[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (v[i][j] == 2) {
					virus(i, j);
				}
			}
		}
		result = max(result, getscore());
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == 0) {
				graph[i][j] = 1;
				count += 1;
				dfs(count);
				graph[i][j] = 0;
				count -= 1;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}
	dfs(0);
	cout << result << '\n';
}