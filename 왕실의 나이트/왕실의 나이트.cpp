#include <iostream>
using namespace std;

int dx[] = { -2,-1,2,1,-2,-1,2,1};
int dy[] = { -1,-2,-1,-2,1,2,1,2};

int main() {
	string input; //나이트 좌표
	cin >> input;

	int row = input[1] - '0';
	int column = input[0] - 'a' + 1;
	
	int result = 0;

	for (int i = 0; i < 8; i++) { // 8가지 방향에 대해 이동이 가능한지 확인.
		int nextrow = row + dx[i];
		int nextcolumn = column + dy[i];

		if (nextrow >= 1 && nextrow <= 8 && nextcolumn >= 1 && nextcolumn <= 8) {
			result++;
			// 이동이 가능하면 카운트증가.
		}
	}
	cout << result;
}