#include <iostream>
#include <vector>
#include <queue>

int arr[101][101]; // 맵정보.

using namespace std;
int n, k, L;
vector <pair<int, char>> v;
//동 남 서 북 
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int turn(int direction, char c) {
	if (c == 'L') direction = (direction == 0) ? 3 : direction - 1;
	else direction = (direction + 1) % 4;
	return direction;
}

int simulate() {
	//초기 뱀 위치.
	int x = 1;
	int y = 1;
	int direction = 0; // 처음에는 동쪽을 보고 있음
	int time = 0; // 시작한 뒤에 지난 '초' 시간
	int index = 0; // 다음에 회전할 정보
	queue <pair<int, int >> q;
	q.push({x, y});
	while (true) {
		//초기에 동쪽을 바라보고있음.
		int nx = x + dx[direction];
		int ny = y + dy[direction];
		if (1 <= nx && nx <= n && 1 <= ny && ny <= n && arr[nx][ny] != 2) {
			if (arr[nx][ny] == 0) {
				arr[nx][ny] == 2;
				q.push({ nx,ny });
				int px = q.front().first;
				int py = q.front().second;
				q.pop();
				arr[px][py] = 0;
			}
			if (arr[nx][ny] == 1) {
				arr[nx][ny] == 2;
				q.push({ nx,ny });
			}
		}
		else {
			time += 1;
			break;
		}
		x = nx;
		y = ny;
		time += 1;
		if (index < L && time == v[index].first) {
			direction = turn(direction, v[index].second);
			index += 1;
		}
	}
	return time;
}

int main() {
	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1; // 사과있는 위치는 1로 표시.
	}
	cin >> L;

	for (int i = 0; i < L; i++) {
		int a;
		char b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	cout << simulate() << '\n';
}