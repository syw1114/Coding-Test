#include <iostream>
#include <algorithm>
#include <cstring>
//https://royhelen.tistory.com/21

using namespace std;

int n;
int map[101][101];
bool visit[101][101];
int dx[] = { 1,-1,0,0 }; // 동서남북
int dy[] = { 0, 0 ,1,-1 };
int max_level;
int result;
bool area_check;

/*void visited() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = false;
		}
	}
}*/
void solve(int x, int y, int h) {
	if (0 <= x && x < n && 0 <= y && y < n  && !visit[x][y]) {
		visit[x][y] = true;
		if (map[x][y] > h) {
			area_check = true;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 <= nx && nx < n && 0 <= ny && ny < n && !visit[nx][ny]) {
					solve( nx, ny,h);
				}
			}
		}
	}
}
int main() {
	memset(map, 0, sizeof(map));
	memset(visit, 0, sizeof(visit));
	result = 1; // 비가안왔을경우.
	cin >> n;
	max_level = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			max_level = max(max_level, map[i][j]);
		}
	}
	for (int h = 1; h <= max_level; h++) {
		int area_count = 0;
		memset(visit, 0, sizeof(visit));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				area_check = false;
				solve(i, j, h);
				if (area_check) {
					area_count++;
				}
			}
		}
		result = max(result, area_count);
	}
	cout << result << endl;
}
