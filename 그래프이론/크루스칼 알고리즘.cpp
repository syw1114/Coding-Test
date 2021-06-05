#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
int parent[100001]; // �θ����̺� �ʱ�ȭ.
int result = 0;
vector <pair<int,pair<int, int>>> v;

int findparent(int x) {
	if (x == parent[x])
		return x;
	return findparent(parent[x]);
}

void unionparent(int a, int b) {
	a = findparent(a);
	b = findparent(b);
	if (a < b) {
		parent[b] = a;
	}
	else
		parent[a] = b;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v.push_back({ cost,{ a,b } });
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		int cost = v[i].first;
		int a = v[i].second.first;
		int b = v[i].second.second;

		//����Ŭ�� �߻����� ���� ��쿡�� ���տ� ����
		if (findparent(a) != findparent(b)) {
			unionparent(a, b);
			result += cost;
		}
	}
	cout << result;
}