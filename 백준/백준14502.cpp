#include <algorithm>
#include <iostream>

using namespace std;
int graph[1001][1001];
int map[1001][1001];
int n, m;
int dx[4] = { 0,0,1,-1 }; // »óÇÏ¿ìÁÂ
int dy[4] = { -1,1,0,0 };
int result = 0;

void virus(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < n && nx >= 0 && ny < m && ny >= 0) {
			if (map[nx][ny] == 0) {
				map[nx][ny] = 2;
				virus(nx,ny);
			}
		}
	}
}
int getscore() {
	int score = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				score++;
			}
		}
	}
	return score;
}

void dfs(int count) {
	if (count == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j] = graph[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 2) {
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
	cout << result;
}