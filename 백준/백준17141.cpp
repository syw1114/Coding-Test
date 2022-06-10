#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define MAX 50
using namespace std;

int MAP[MAX][MAX];
bool visit[MAX][MAX];
bool Select[10];
int N, M, answer = 9999999;

vector<pair<int, int>> select_v;
vector<pair<int, int>>v;
int dx[] = { 1,-1,0,0 }; // µ¿¼­³²ºÏ
int dy[] = { 0, 0 ,1,-1 };

int Min(int A, int B) {
	if (A < B) return A;
	return B;
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 2) select_v.push_back(make_pair(i, j));
		}
	}
}
bool Check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (MAP[i][j] == 1) continue;
			if (visit[i][j] == false) return false;
		}
	}
	return true;
}
// ¹ÙÀÌ·¯½º ÆÛÁü
void spread_V() {
	queue<pair<int, int>>q;
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;

		q.push(make_pair(x, y));
		visit[x][y] = true;
	}
	int cnt = 0;
	while (!q.empty())
	{
		int s = q.size();
		for (int i = 0; i < s; i++) {
			int x = q.front().first;
			int y = q.front().second;

			q.pop();

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
					if (visit[nx][ny] == false && MAP[nx][ny] != 1) {
						visit[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
		if (q.size() != 0) cnt++;
	}
	if (Check() == true)
		answer = Min(answer, cnt);
}
void select_virus(int a, int cnt) {
	if (cnt == M) {
		memset(visit, false, sizeof(visit));
		spread_V();
		return;
	}
	for (int i = a; i < select_v.size(); i++) {
		if (Select[i] == true) continue;
		Select[i] = true;
		v.push_back(select_v[i]);
		select_virus(i, cnt + 1);
		v.pop_back();
		Select[i] = false;
	}
}
void solve() {
	select_virus(0, 0);
	if (answer == 9999999) answer = -1;
	cout << answer;
}
int main() {
	input();
	solve();
}
