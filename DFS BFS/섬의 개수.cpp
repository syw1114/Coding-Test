#include <iostream>
#include<vector>
using namespace std;

int arr[51][51];
vector<int> v;
int w, h;

bool dfs(int x, int y) {
	if (x <= -1 || x >= w || y <= -1 || y >= h) { // ¹üÀ§¸¦ ¹þ¾î³ª¸é Á¾·á.
		return false;
	}
	if (arr[x][y] == 1) {
		arr[x][y] = 0;
		dfs(x - 1, y); //»ó
		dfs(x + 1, y); //ÇÏ
		dfs(x, y - 1); //ÁÂ
		dfs(x, y + 1); //¿ì
		dfs(x - 1, y + 1);//¿ì»ó
		dfs(x + 1, y + 1);//¿ìÇÏ
		dfs(x - 1, y - 1);//ÁÂ»ó
		dfs(x + 1, y - 1);//ÁÂÇÏ
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