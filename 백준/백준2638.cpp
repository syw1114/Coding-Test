#include <iostream>
#include <queue>
#include <vector>
#define MAX 101

using namespace std;

int N, M;
int MAP[MAX][MAX];
int visit[MAX][MAX];

int dx[] = { 1,-1,0,0 }; // ��������
int dy[] = { 0, 0 ,1,-1 };

//ġ� ��ǥ�� �����ϴ� ����
vector < pair<pair<int, int>, bool>> v; 
vector<pair<int, int>> cheese; // ��� ġ��
queue<pair<int, int>>qq;
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 1) {
				v.push_back(make_pair(make_pair(i, j), false));
				visit[i][j] = -1;
			}
		}
	}
}
//�ܺ� ���ΰ��� ������
void First_Air() {
	queue<pair<int, int>>q;
	visit[0][0] = 1;
	q.push(make_pair(0, 0));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				if ( visit[nx][ny] == 0) {
					visit[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

//ġ�� ���̴°���
void melt() {
	cheese.clear();
	for (int i = 0; i < v.size(); i++) {
		if (v[i].second == true) continue;

		int x = v[i].first.first;
		int y = v[i].first.second;

		int cnt = 0;

		for (int j = 0; j < 4; j++) {
			int nx = x + dx[j];
			int ny = y + dy[j];

			if (MAP[nx][ny] == 0 && visit[nx][ny] == 1) cnt++;
		}
		if (cnt >= 2) {
			cheese.push_back(make_pair(x, y));
			v[i].second = true;
		}
	}
}
//ġ� ���Ӱ� ���ÿ� �ܺ�+���ΰ��⿡ ���� ��ǥ qq������
void melting() {
	for (int i = 0; i < cheese.size(); i++) {
		int x = cheese[i].first;
		int y = cheese[i].second;

		MAP[x][y] = 0;
		qq.push(make_pair(x, y));
	}
}
void add_Air() {
	//�ܺΰ���� ���ΰ�����ġ�°���
	while (!qq.empty())
	{
		int x = qq.front().first;
		int y = qq.front().second;

		qq.pop();

		visit[x][y] = 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && ny < M && nx < N) {
				if (visit[nx][ny] == 0) {
					qq.push(make_pair(nx, ny));
					visit[nx][ny] = 1;
				}
			}
		}
	}
}
bool check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (MAP[i][j] == 1) return false;
		}
	}
	return true;
}
void solve() {
	First_Air();
	int time = 0;

	while (1) {
		if (check() == true) break;
		melt();
		melting();
		add_Air();
		time++;
	}
	cout << time;
}
int main() {
	input();
	solve();
}