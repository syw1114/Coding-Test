#include <iostream>
using namespace std;

int n, m, x, y, d;
int map[50][50]; // ��ü �� ����.
int arr[50][50]; // ���� ��ġ ���� ���� ��.

int dx[] = { -1, 0, 1, 0 }; // �� �� �� �� 
int dy[] = { 0, 1, 0, -1 };

void turn_left(){
	d -= 1;
	if (d == -1)
		d = 3;
}

int main() {
	cin >> n >> m;
	cin >> x >> y >> d;
	int move = 1; // �̵�Ƚ�� 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j]; // ��ü �� ���� �Է¹ޱ�.
		}
	}

	for (;;) {
		for (int i = 1; i <= 4; i++) {
			turn_left();
			int nx = x + dx[d];
			int ny = y + dy[d];
			//ȸ�� ���� ���鿡 ���������� ĭ�� �����ϴ� ���. �̵��ϰ� ���� ��ġ ����.
			if (arr[nx][ny] == 0 && map[nx][ny] == 0) {
				arr[nx][ny] = 1; // ���� ��ġ ����.
				x = nx; 
				y = ny;
				move++;
				continue;
			}
			if (i == 4) { // ��� ���� �ٴ��ΰ��.
				nx = x - dx[d];
				ny = y - dy[d];
				if (map[nx][ny] == 0) { // �ڷ� �� �� ������ �̵�.
					x = nx;
					y = ny;
					move++;
				}
				else { // �ڰ� �ٴٷ� ���������� ����ϰ� ����.
					cout << move;
					return 0;
				}
			}
		}
	}
}