#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 1000
#define INF 999999
using namespace std;

int N,W,H;

char MAP[MAX][MAX]; // 전제 지도.
int Fire_MAP[MAX][MAX]; // 불 지도.
bool visit[MAX][MAX];
int dx[] = { 1,-1,0,0 }; // 동서남북
int dy[] = { 0, 0 ,1,-1 };

pair<int, int>start;
queue<pair<int, int>>Fq;
void input() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			Fire_MAP[i][j] = INF;
		}
	}
	memset(visit, false, sizeof(visit));
		cin >> W >> H;
		for (int j = 0; j < H; j++) {
			for (int k = 0; k < W; k++) {
				cin >> MAP[j][k];
				if (MAP[j][k] == '*') {
					Fire_MAP[j][k] = 0;
					Fq.push(make_pair(j, k));
				}
				else if (MAP[j][k] == '@') {
					start.first = j;
					start.second = k;
				}
			}
		}
}

void Fire_spread() {
	while (!Fq.empty())
	{
		int Qs = Fq.size();

		for (int k = 0; k < Qs; k++) {
			int x = Fq.front().first;
			int y = Fq.front().second;

			Fq.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && ny >= 0 && nx < H && ny < W) {
					if (MAP[nx][ny] != '#') {
						if (Fire_MAP[nx][ny] > Fire_MAP[x][y] + 1) {
							Fire_MAP[nx][ny] = Fire_MAP[x][y] + 1;
							Fq.push(make_pair(nx, ny));
						}
					}
				}
			}
		}
	}
}
int People_move() {
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(start.first, start.second),0));
	visit[start.first][start.second] = true;
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;

		int Cnt = q.front().second;
		q.pop();
		if (x == H - 1 || x == 0 || y == W - 1 || y == 0) return (Cnt + 1);

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx >= 0 && ny >= 0 && nx < H && ny < W) {
				if (MAP[nx][ny] == '.' && visit[nx][ny] == false) {
					if (Fire_MAP[nx][ny] > Cnt+1) {
						visit[nx][ny] = true;
						q.push(make_pair(make_pair(nx, ny), Cnt + 1));
					}
				}
			}
		}
	}
	return -1;
}
void solve() {
	Fire_spread();
	int R = People_move();
	if (R == -1) cout << "IMPOSSIBLE" << endl;
	else cout << R << endl;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		input();
		solve();
	}
}