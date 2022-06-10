#include <iostream>
#include <queue>
#define MAX 100

using namespace std;
int N, M;
int map[MAX][MAX];
int visited[MAX][MAX];
int dx[] = { 1,-1,0,0 }; // 동서남북
int dy[] = { 0, 0 ,1,-1 };

queue<pair<int, int>>qq;

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				//치즈가있는 곳은 -1로 표시.
				visited[i][j] = -1;
			}
		}
	}
}
//외부 내부공기 나누기.
void First_Air() {
	queue<pair<int, int>>q;
	visited[0][0] = 1;
	q.push(make_pair(0, 0));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && ny < M && nx < N) {
				if (map[nx][ny] == 0 && visited[nx][ny] == 0) {
					visited[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
//치즈와 인접한 외부 공기.
void adjacent_Air() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == 1) {
				for (int a = 0; a < 4; a++) {
					int nx = i + dx[a];
					int ny = j + dy[a];

					if (nx >= 0 && ny >= 0 && ny < M && nx < N) {
						if (map[nx][ny] == 1) {
							qq.push(make_pair(i, j));
							break;
						}
					}
				}
			}
		}
	}
}
bool check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) return false;
		}
	}
	return true;
}
//치즈 녹이는과정
void melt() {
	queue<pair<int, int >> q = qq;
	while (!qq.empty())
		qq.pop();
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				if (map[nx][ny] == 1) {
					map[nx][ny] = 0;
					qq.push(make_pair(nx, ny));
				}
			}
		}
	}
}
void add_Air() {
	queue<pair<int, int>> q = qq;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				if (visited[nx][ny] == 0) {
					qq.push(make_pair(nx, ny));
					q.push(make_pair(nx, ny));
					visited[nx][ny] = 1;

				}
			}
		}
	}
}
void solve() {
	First_Air();
	adjacent_Air();

	int time = 0;
	int size = 0;
	while (1)
	{
		//치즈가 다녹고나면 치즈가 존재하지않음으로 break;
		if (check() == true) break;
		melt();
		size = qq.size();
		
		add_Air();
		time++;
	}
	cout << time << "\n" << size << "\n";
}
int main() {
	input();
	solve();
}