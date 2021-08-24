#include <iostream>
#include<queue>
#include <cstring>
using namespace std;

int num;
int a, b, c, d;
int arr[301][301];
int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

void bfs() {
	queue<pair<int, int>>q;
	q.push({ a, b });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == c && y == d) {
			cout << arr[x][y] << endl;
			while (!q.empty()) {
				q.pop();
			}
			return;
		}
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			// 해당 위치로 이동이 가능하다면 카운트 증가
			if (nx < 0 || nx >= num || ny < 0 || ny >= num) continue;
			if (arr[nx][ny]) continue;
			arr[nx][ny] = arr[x][y] + 1;
			q.push({ nx, ny });
		}
	}
}
int main() {
	int n;
	cin >> n;
	while(n--){
		cin >> num;
		cin >> a >> b;
		cin >> c >> d;
		memset(arr, 0, sizeof(arr));
		bfs();
	}
}