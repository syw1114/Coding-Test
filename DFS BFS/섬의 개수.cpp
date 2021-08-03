#include <iostream>
#include<vector>
using namespace std;

int arr[51][51];
vector<int> v;
int w, h;

bool dfs(int x, int y) {
	if (x <= -1 || x >= w || y <= -1 || y >= h) { // ������ ����� ����.
		return false;
	}
	if (arr[x][y] == 1) {
		arr[x][y] = 0;
		dfs(x - 1, y); //��
		dfs(x + 1, y); //��
		dfs(x, y - 1); //��
		dfs(x, y + 1); //��
		dfs(x - 1, y + 1);//���
		dfs(x + 1, y + 1);//����
		dfs(x - 1, y - 1);//�»�
		dfs(x + 1, y - 1);//����
		return true;
	}
	return false;
}
int main() {
	while (1) {
		cin >> h >> w;
		if (!w && !h) break;
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				cin >> arr[i][j];
			}
		}
		int result = 0;
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				if (dfs(i, j)) {
					result += 1;
				}
			}
		}
		v.push_back(result);
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}