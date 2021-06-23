#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int arr[50][50];
int unions[50][50];
int nx[] = { -1,0,1,0 };
int ny[] = { 0,-1,0,1 };
int result = 0;
int n,l,r;
void process(int x, int y, int index) {
	vector<pair<int, int>> v;
	v.push_back({ x,y });
	queue<pair<int, int>>q;
	q.push({ x,y });
	unions[x][y] = index;
	int summary = arr[x][y]; // 현재 연합의 전체 인구수.
	int count = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = x + nx[i];
			int dy = y + ny[i];
			if (0 <= dx && dx < n && 0 <= dy && dy < n && unions[dx][dy] == -1) {
				int gap = abs(arr[x][y] - arr[dx][dy]);
				if (l<= gap && gap <= r) {
					q.push({ dx,dy });
					unions[dx][dy] = index;
					summary += arr[dx][dy];
					count += 1;
					v.push_back({ dx,dy });
				}
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;
		arr[x][y] = summary / count;
	}
}

int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	

	while (true) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				unions[i][j] = -1;
			}
		}
		int index = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (unions[i][j] == -1) {
					process(i, j, index);
					index += 1;
				}
			}
		}
		if (index == n * n) break;
		result += 1;
	}
	cout << result;
}