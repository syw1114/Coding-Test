#include <iostream>
#include <cmath>
#include <queue>
#include <cstring>
#include <vector>
#define MAX 100


using namespace std;
int N, L, R;
int map[MAX][MAX];
int visit[MAX][MAX];
bool check = true;
vector<int>v;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool combi(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
			if (L <= abs(map[x][y] - map[nx][ny]) && abs(map[x][y] - map[nx][ny]) <= R) return true;
		}
	}
	return false;
}
bool combi2(int x, int y, int xx, int yy) {
	if (L <= abs(map[x][y] - map[xx][yy]) && abs(map[x][y] - map[xx][yy]) <= R) return true;
	return false;
}

void BFS(int a,int b) {
	visit[a][b] = true;
	queue<pair<int, int>>q;
	queue<pair<int, int>>qq;
	q.push({ a,b });
	qq.push({ a,b });
	int sum = 0;
	int avg = 0;
	int cnt = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();
		sum = sum + map[x][y];
		cnt = cnt + 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N && visit[nx][ny] == 0) {
				if (combi2(x, y, nx, ny) == true) {
					visit[nx][ny] = 1;
					q.push({ nx,ny });
					qq.push({ nx,ny });
				}
			}
		}
	}
	avg = sum / cnt;

	while (!qq.empty()) {
		int x = qq.front().first;
		int y = qq.front().second;

		qq.pop();
		map[x][y] = avg;
	}
}
void solve() {
	int day = 0;
	while (check) {
		check = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (combi(i,j) == true && visit[i][j] == 0) {
					v.clear();
					BFS(i, j);
					check = true;
				}
			}
		}
		if (check == true) day++;
		memset(visit, 0, sizeof(visit));
	}
	cout << day;
}
int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	solve();
}