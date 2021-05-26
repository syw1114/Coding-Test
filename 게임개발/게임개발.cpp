#include <iostream>
using namespace std;

int n, m, x, y, d;
int map[50][50]; // 전체 맵 정보.
int arr[50][50]; // 현재 위치 정보 저장 맵.

int dx[] = { -1, 0, 1, 0 }; // 북 동 남 서 
int dy[] = { 0, 1, 0, -1 };

void turn_left(){
	d -= 1;
	if (d == -1)
		d = 3;
}

int main() {
	cin >> n >> m;
	cin >> x >> y >> d;
	int move = 1; // 이동횟수 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j]; // 전체 맵 정보 입력받기.
		}
	}

	for (;;) {
		for (int i = 1; i <= 4; i++) {
			turn_left();
			int nx = x + dx[d];
			int ny = y + dy[d];
			//회전 이후 정면에 가보지않은 칸이 존재하는 경우. 이동하고 현재 위치 변경.
			if (arr[nx][ny] == 0 && map[nx][ny] == 0) {
				arr[nx][ny] = 1; // 현재 위치 저장.
				x = nx; 
				y = ny;
				move++;
				continue;
			}
			if (i == 4) { // 모든 면이 바다인경우.
				nx = x - dx[d];
				ny = y - dy[d];
				if (map[nx][ny] == 0) { // 뒤로 갈 수 있으면 이동.
					x = nx;
					y = ny;
					move++;
				}
				else { // 뒤가 바다로 막혀있으면 출력하고 종료.
					cout << move;
					return 0;
				}
			}
		}
	}
}