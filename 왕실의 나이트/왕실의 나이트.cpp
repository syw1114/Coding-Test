#include <iostream>
using namespace std;

int dx[] = { -2,-1,2,1,-2,-1,2,1};
int dy[] = { -1,-2,-1,-2,1,2,1,2};

int main() {
	string input; //����Ʈ ��ǥ
	cin >> input;

	int row = input[1] - '0';
	int column = input[0] - 'a' + 1;
	
	int result = 0;

	for (int i = 0; i < 8; i++) { // 8���� ���⿡ ���� �̵��� �������� Ȯ��.
		int nextrow = row + dx[i];
		int nextcolumn = column + dy[i];

		if (nextrow >= 1 && nextrow <= 8 && nextcolumn >= 1 && nextcolumn <= 8) {
			result++;
			// �̵��� �����ϸ� ī��Ʈ����.
		}
	}
	cout << result;
}