#include <iostream>
#include <vector>
#include <queue>

int arr[101][101]; // ������.

using namespace std;
int n, k, L;
vector <pair<int, char>> v;
//�� �� �� �� 
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int turn(int direction, char c) {
	if (c == 'L') direction = (direction == 0) ? 3 : direction - 1;
	else direction = (direction + 1) % 4;
	return direction;
}

int simulate() {
	//�ʱ� �� ��ġ.
	int x = 1;
	int y = 1;
	int direction = 0; // ó������ ������ ���� ����
	int time = 0; // ������ �ڿ� ���� '��' �ð�
	int index = 0; // ������ ȸ���� ����
	queue <pair<int, int >> q;
	q.push({x, y});
	while (true) {
		//�ʱ⿡ ������ �ٶ󺸰�����.
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
		arr[a][b] = 1; // ����ִ� ��ġ�� 1�� ǥ��.
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