#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

char MAP[12][6];
bool visit[12][6];
int temp_cnt = 0;
int dx[] = { 1,-1,0,0 }; // 동서남북
int dy[] = { 0, 0 ,1,-1 };
//vv = 뿌요가 터지고난 좌표를 저장하는곳.
vector<pair<int, int>> v, vv;

void input() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> MAP[i][j];
		}
	}
}
void DFS(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < 12 && ny < 6) {
			if (MAP[nx][ny] == '.')continue;
			if (visit[nx][ny] == true) continue;
			if (MAP[x][y] != MAP[nx][ny]) continue;

			temp_cnt++;
			vv.push_back(make_pair(nx, ny));
			visit[nx][ny] = true;
			DFS(nx, ny);
		}
	}
}
void solve() {
	bool flag;
	int answer = 0;
	
	while (1) {
		flag = false;
		memset(visit, false, sizeof(visit));
		v.clear();

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (MAP[i][j] != '.' && visit[i][j] == false) {
					temp_cnt = 1;
					visit[i][j] = true;
					vv.push_back(make_pair(i, j));
					DFS(i, j);
					if (temp_cnt >= 4) {
						flag = true;
						for (int k = 0; k < vv.size(); k++) {
							v.push_back(vv[k]);
						}
					}
					vv.clear();
				}
			}
		}
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].first;
			int y = v[i].second;

			MAP[x][y] = '.';
		}
		for (int i = 10; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (MAP[i][j] == '.') continue;
				int tmp = i;
				while (1)
				{
					if (tmp == 11 || MAP[tmp + 1][j] != '.') break;

					MAP[tmp + 1][j] = MAP[tmp][j];
					MAP[tmp][j] = '.';
					tmp++;
				}
			}
		}
		if (flag == true) answer++;
		else break;
	}
	cout << answer;
}
int main() {
	input();
	solve();
}