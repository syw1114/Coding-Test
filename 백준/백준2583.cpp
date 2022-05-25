#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
int dx[] = { 1,-1,0,0 }; // µ¿¼­³²ºÏ
int dy[] = { 0, 0 ,1,-1 };
int map[101][101];
bool visit[101][101];
vector<int>v;
int cnt;

void dfs(int x, int y) {
	visit[x][y] = true;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny]) {
			dfs(nx, ny);
		}
	}
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int y = b; y < d; y++) {
			for (int x = a; x < c; x++) {
				map[y][x] = 1;
				visit[y][x] = true;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0 && !visit[i][j]) {
				cnt = 0;
				dfs(i, j);
				v.push_back(cnt);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
}