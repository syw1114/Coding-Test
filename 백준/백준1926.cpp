#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 501

using namespace std;

int N, M;
int MAP[MAX][MAX];
bool visit[MAX][MAX];
int cnt = 0;
int num = 0; // ±×¸²ÀÇ °¹¼ö.
int answer = 0;
queue<pair<int, int>>q;

int dx[] = { 1,-1,0,0 }; // µ¿¼­³²ºÏ
int dy[] = { 0, 0 ,1,-1 };

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}
}
void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] == false && MAP[i][j] == 1) {
				cnt = 0;
				visit[i][j] = true;
				cnt++;
				num++;
				q.push(make_pair(i, j));
				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;

					q.pop();

					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
							if (visit[nx][ny] == true) continue;
							if (MAP[nx][ny] == 0) continue;
							visit[nx][ny] = true;
							q.push(make_pair(nx,ny));
							cnt++;
						}
					}
				}
				answer = max(answer, cnt);
			}
		}
	}
	if (num == 0) {
		cout << '0' << endl << '0' << endl;
	}
	else {
		cout << num << endl << cnt << endl;
	}
}
int main() {
	input();
	solve();
}
