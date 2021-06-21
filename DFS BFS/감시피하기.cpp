#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
char arr[10][10];
vector<pair<int, int>> teacher;
vector<pair<int, int>> space;


bool watch(int x, int y, int j) {
	if (j == 0) {
		while (y >= 0) {
			if (arr[x][y] == 'S') {
				return true;
			}
			if (arr[x][y] == 'O') {
				return false;
			}
			y -= 1;
		}
	}
	if (j == 1) {
		while (y < n) {
			if (arr[x][y] == 'S') {
				return true;
			}
			if (arr[x][y] == 'O') {
				return false;
			}
			y += 1;
		}
	}
	if (j == 2) {
		while (x >= 0) {
			if (arr[x][y] == 'S') {
				return true;
			}
			if (arr[x][y] == 'O') {
				return false;
			}
			x -= 1;
		}
	}
	if (j == 3) {
		while (x < n) {
			if (arr[x][y] == 'S') {
				return true;
			}
			if (arr[x][y] == 'O') {
				return false;
			}
			x += 1;
		}
	}
	return false;
}

bool process() {
	for (int i = 0; i < teacher.size(); i++) {
		int x = teacher[i].first;
		int y = teacher[i].second;
		for (int i = 0; i < 4; i++) {
			if (watch(x, y, i)) {
				return true;
			}
		}
	}
	return false;
}
bool found;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'X') {
				space.push_back({ i,j });
			}
			if (arr[i][j] == 'T') {
				teacher.push_back({ i,j });
			}
		}
	}
		vector<bool>binary(space.size());
		fill(binary.end() - 3, binary.end(), true);
		do {
			for (int i = 0; i < space.size(); i++) {
				if (binary[i]) {
					int x = space[i].first;
					int y = space[i].second;
					arr[x][y] = 'O';
				}
			}
			if (!process()) {
				found = true;
				break;
			}
			for (int i = 0; i < space.size(); i++) {
				if (binary[i]) {
					int x = space[i].first;
					int y = space[i].second;
					arr[x][y] = 'X';
				}
			}
		} while (next_permutation(binary.begin(), binary.end()));
		if (found) cout << "YES";
		else cout << "NO";
	}