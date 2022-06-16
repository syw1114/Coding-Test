#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 50

using namespace std;

int N,M,Empty_place, answer = 9999999;
int dx[] = { 1,-1,0,0 }; // µ¿¼­³²ºÏ
int dy[] = { 0, 0 ,1,-1 };

int MAP[MAX][MAX];
int Time[MAX][MAX];
bool Select[10];

vector<pair<int, int>>v;

int Min(int A, int B) {
	if (A < B) return A;
	return B;
}
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 0) Empty_place++;
			else if (MAP[i][j] == 2) v.push_back(make_pair(i, j));
		}
	}
}
void spread(queue<pair<int,int>>q) {
	int total_time = 0;
	int infect_place = 0;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if (MAP[nx][ny] != 1 && Time[nx][ny] == -1) {
					Time[nx][ny] = Time[x][y] + 1;
					if (MAP[nx][ny] == 0) {
						infect_place++;
						total_time = Time[nx][ny];
					}
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	if (Empty_place == infect_place)
		answer = Min(answer, total_time);
}
void Virus(int a, int cnt) {
	if (cnt == M) {
		queue<pair<int, int>>q;
		memset(Time, -1, sizeof(Time));
		for (int i = 0; i < v.size(); i++) {
			if (Select[i] == true) {
				q.push(make_pair(v[i].first,v[i].second));
				Time[v[i].first][v[i].second] = 0;
			}
		}
		spread(q);
		return;
	}
	for (int i = a; i < v.size(); i++) {
		if (Select[i] == true) continue;
		Select[i] = true;
		Virus(i + 1, cnt + 1);
		Select[i] = false;
	}
}
void solve() {
	Virus(0, 0);
	if (answer == 9999999) answer = -1;
	cout << answer;
}
int main() {
	input();
	solve();
}