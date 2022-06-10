#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 101
using namespace std;
int N, answer;
int MAP[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int, int>>v;

int dx[] = { 1,-1,0,0 }; // µ¿¼­³²ºÏ
int dy[] = { 0, 0 ,1,-1 };

int Min(int A, int B) {
	if (A < B) return A;
	return B;
}

void input() {
	answer = 987654321;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 1) {
				MAP[i][j] = -1;
				v.push_back(make_pair(i, j));
			}
		}
	}
}
void make_land(int a, int b, int L) {
	queue<pair<int, int>>q;
	visited[a][b] = true;
	MAP[a][b] = L;
	q.push(make_pair(a, b));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if (visited[nx][ny] == false && MAP[nx][ny] == -1) {
					q.push(make_pair(nx, ny));
					visited[nx][ny] = true;
					MAP[nx][ny] = L;
				}
			}
		}
	}
}

int BFS(int num) {
	int result = 0;
	queue<pair<int, int>>q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (MAP[i][j] == num) {
				visited[i][j] = true;
				q.push(make_pair(i, j));
			}
		}
	}
	while (!q.empty()) {
		int S = q.size();

		for (int i = 0; i < S; i++) {
			int x = q.front().first;
			int y = q.front().second;

			q.pop();

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
					if (MAP[nx][ny] != 0 && MAP[nx][ny] != num) return result;
					else if (MAP[nx][ny] == 0 && visited[nx][ny] == false) {
						visited[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
		result++;
	}
}
void solve() {
	int land_label = 1;
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;

		if (visited[x][y] == false) {
			make_land(x, y, land_label);
			land_label++;
		}
	}
	for (int i = 1; i < land_label; i++) {
		answer = Min(answer, BFS(i));
		memset(visited, false, sizeof(visited));
	}
	cout << answer;
}
int main() {
	input();
	solve();
}