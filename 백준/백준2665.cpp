#include <iostream>
#include <queue>
#define MAX 50

using namespace std;

int N;
int map[MAX][MAX];
int visited[MAX][MAX];

int dx[] = { 1,-1,0,0 }; // µ¿¼­³²ºÏ
int dy[] = { 0, 0 ,1,-1 };

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < S.length(); j++) {
			map[i][j] = S[j] - '0';
		}
	}
}
void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 9999999;
		}
	}
	queue<pair<int, int>>q;
	q.push(make_pair(0, 0));
	visited[0][0] = 0;
	
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];


			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if (map[nx][ny] == 1) {
					if (visited[nx][ny] > visited[x][y]) {
						visited[nx][ny] = visited[x][y];
						q.push(make_pair(nx, ny));
					}
				}
				else
					if (visited[nx][ny] > visited[x][y] + 1) {
						visited[nx][ny] = visited[x][y] + 1;
						q.push(make_pair(nx, ny));
					}
			}
		}
	}
}
int main() {
	input();
	solve();
	cout << visited[N-1][N-1];
}