#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int map[51][51];
bool visit[51][51];
vector<int>v;
int n, m, k;
int dx[4] = { 0,0,1,-1 }; // µ¿¼­³²ºÏ
int dy[4] = { 1,-1,0,0 }; 

bool dfs(int x, int y) {
	if (visit[x][y]) return false;
	visit[x][y] = true;
	for (int j = 0; j < 4; j++) {
		int nx = x + dx[j];
		int ny = y + dy[j];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny])
			dfs(nx, ny);
	}
	return true;
}

int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> n >> m >> k;
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		for (int j = 0; j < k; j++) {
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}
		int count = 0;
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < m; b++) {
				if (map[a][b] && !visit[a][b]) {
					if (dfs(a, b))
						count++;
				}
			}
		}
		v.push_back(count);
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
}