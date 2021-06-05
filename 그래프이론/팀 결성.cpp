#include <iostream>


using namespace std;
int n, m;
int d[100001]; // 부모테이블

int findparent(int x) {
	if (d[x] == x) {
		return x;
	}
	return d[x] = findparent(d[x]);
}
void unionparent(int a, int b) {
	a = findparent(a);
	b = findparent(b);
	if (a < b) {
		d[b] = a;
	}
	else
		d[a] = b;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		d[i] = i;

	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		// 팀을 합치는 연산.
		if (a == 0) {
			unionparent(b, c);
		}
		else if (a == 1) {
			if (findparent(b) == findparent(c)) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
}