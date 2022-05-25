#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<pair<int,int>>v;
queue<pair<int,int>>q;
int arr[1001][1001];
int n, m;
int result = 0;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				q.push({ i,j });
			}
		}
	}
	while (!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
				if (arr[nx][ny] == 0) {
					arr[nx][ny] = arr[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			// 익지않은 토마토(0)가 존재할 경우
			if (arr[i][j] == 0) {
				cout << "-1";
				return 0;
			}
			if (result < arr[i][j]) {
				result = arr[i][j];
			}
		}
	}
	cout << result - 1;
	return 0;
}