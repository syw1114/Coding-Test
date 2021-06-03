#include <iostream>

using namespace std;

int n, m;
int d[100001]; // 부모테이블

int findParent(int x) {
	if (d[x] == x)
		return x;
	return d[x] = findParent(d[x]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a < b)
		d[b] = a;
	else
		d[a] = b;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i<= n; i++) {
		d[i] = i;
	}
	bool cycle = false;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (findParent(a) == findParent(b)) {
			cycle = true;
			break;
		}
		else
			unionParent(a, b);
	}
	if (cycle)
		cout << "사이클 발생";
	else
		cout << "사이클 발생X";

}