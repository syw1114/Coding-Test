#include <iostream>
#include <queue>

#define MAX 51

using namespace std;
int n, m;
char MAP[MAX][MAX];

pair<int, int> home; // 도치 집
queue<pair<int, int>>q; //도치 이동
queue<pair<int, int>>qq;//물 이동

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int Hog_time = 0;

void BFS() {
	while (!q.empty()) { //  도치가 이동을 못할때 까지
		//물 이동
		int wqq = qq.size();
		// q.size()로 for을 안돌리는 이유
		// q.size()가 q.push때문에 계속 증가해서 for문 범위가 계속 증가해서 오류가생김.
		for (int i = 0; i < wqq; i++) {
			int wx = qq.front().first;
			int wy = qq.front().second;

			qq.pop();
			//물 현재위치에서 인접한 공간 탐색.
			for (int j = 0; j < 4; j++) {
				int nwx = wx + dx[j];
				int nwy = wy + dy[j];
				// 인접좌표가 지도안에있는 곳인지, 빈곳인지 확인
				if (nwx >= 0 && nwy >= 0 && nwx < n && nwy < m && MAP[nwx][nwy] == '.') {
					//물 전용 qq에 물 좌표 삽입
					qq.push(make_pair(nwx, nwy));
					//인접 좌표를 물이 확장된 위치로 변경.
					MAP[nwx][nwy] = '*';
				}
			}
		}
		// 도치이동
		int hogq = q.size();

		for (int i = 0; i < hogq; i++) {
			int hx = q.front().first;
			int hy = q.front().second;

			q.pop();

			for (int j = 0; j < 4; j++) {
				int nhx = hx + dx[j];
				int nhy = hy + dy[j];
				//인접좌표가 집이면 종료.
				if (nhx == home.first && nhy == home.second ) {
					Hog_time++;
					cout << Hog_time;
					return;
				}
				if (nhx >= 0 && nhy >= 0 && nhx < n  && nhy < m && MAP[nhx][nhy] == '.') {
					q.push(make_pair(nhx, nhy));
					MAP[nhx][nhy] = 'S';
				}
			}
		}
		Hog_time++;
	}
	cout << "KAKTUS";
	return;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 'S') { // 도치의 위치 q에 저장 
				q.push(make_pair(i, j));
			}
			else if (MAP[i][j] == 'D') { // 집 위치 저장
				home = make_pair(i, j);
			}
			else if (MAP[i][j] == '*') { // 물 위치 저장
				qq.push(make_pair(i, j));
			}
		}
	}
	BFS();
}