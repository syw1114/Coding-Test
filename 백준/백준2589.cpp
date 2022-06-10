#include <iostream>
#include <queue>
#include <cstring>
#define MAX 50

using namespace std;
int N,M,answer;
int dx[] = { 1,-1,0,0 }; // µ¿¼­³²ºÏ
int dy[] = { 0, 0 ,1,-1 };
char MAP[MAX][MAX];
int visit[MAX][MAX];

int big(int A, int B) {
	if ( A > B) return A;
	return B;
}
int BFS(int a, int b) {
	int time_result = 0;
	queue<pair<int, int>>Q;
	Q.push(make_pair(a, b));
	visit[a][b] = 1;


	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;

		Q.pop();

		if (time_result < visit[x][y])
			time_result = visit[x][y];

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				if (visit[nx][ny] == 0 && MAP[nx][ny] == 'L') {
					Q.push(make_pair(nx, ny));
					visit[nx][ny] = visit[x][y] + 1;
				}
			}
		}
	}
	return time_result;
}
void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (MAP[i][j] == 'L') {
				int R = BFS(i, j);
				answer = big(answer, R-1);
				memset(visit, 0, sizeof(visit));
			}
		}
	}
	cout << answer << endl;
}
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}
}
int main() {
	input();
	solve();
}