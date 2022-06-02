#include <iostream>
#include <queue>

#define MAX 51

using namespace std;
int n, m;
char MAP[MAX][MAX];

pair<int, int> home; // ��ġ ��
queue<pair<int, int>>q; //��ġ �̵�
queue<pair<int, int>>qq;//�� �̵�

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int Hog_time = 0;

void BFS() {
	while (!q.empty()) { //  ��ġ�� �̵��� ���Ҷ� ����
		//�� �̵�
		int wqq = qq.size();
		// q.size()�� for�� �ȵ����� ����
		// q.size()�� q.push������ ��� �����ؼ� for�� ������ ��� �����ؼ� ����������.
		for (int i = 0; i < wqq; i++) {
			int wx = qq.front().first;
			int wy = qq.front().second;

			qq.pop();
			//�� ������ġ���� ������ ���� Ž��.
			for (int j = 0; j < 4; j++) {
				int nwx = wx + dx[j];
				int nwy = wy + dy[j];
				// ������ǥ�� �����ȿ��ִ� ������, ������� Ȯ��
				if (nwx >= 0 && nwy >= 0 && nwx < n && nwy < m && MAP[nwx][nwy] == '.') {
					//�� ���� qq�� �� ��ǥ ����
					qq.push(make_pair(nwx, nwy));
					//���� ��ǥ�� ���� Ȯ��� ��ġ�� ����.
					MAP[nwx][nwy] = '*';
				}
			}
		}
		// ��ġ�̵�
		int hogq = q.size();

		for (int i = 0; i < hogq; i++) {
			int hx = q.front().first;
			int hy = q.front().second;

			q.pop();

			for (int j = 0; j < 4; j++) {
				int nhx = hx + dx[j];
				int nhy = hy + dy[j];
				//������ǥ�� ���̸� ����.
				if (nhx == home.first && nhy == home.second ) {
					Hog_time++;
					cout << Hog_time;
					return;
				}
				if (nhx >= 0 && nhy >= 0 && nhx < n  && nhy < m && MAP[nhx][nhy] == '.') {
					q.push(make_pair(nhx, nhy));
					MAP[nhx][nhy] = 'S';
				}
			}
		}
		Hog_time++;
	}
	cout << "KAKTUS";
	return;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 'S') { // ��ġ�� ��ġ q�� ���� 
				q.push(make_pair(i, j));
			}
			else if (MAP[i][j] == 'D') { // �� ��ġ ����
				home = make_pair(i, j);
			}
			else if (MAP[i][j] == '*') { // �� ��ġ ����
				qq.push(make_pair(i, j));
			}
		}
	}
	BFS();
}