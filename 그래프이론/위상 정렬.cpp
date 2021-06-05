#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, m;
int d[100001];
vector <int> v[100001];
void topology_sort() {
	vector<int> result;
	queue<int>q;

	for (int i = 1; i <= n; i++) {
		if (d[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		result.push_back(now);
		for (int i = 0; i < v[now].size(); i++) {
			//���� ���� -1;
			d[v[now][i]] -= 1;
			//�ش� ����� ���� ������ 0�̸� q�� ����.
			if (d[v[now][i]] == 0) {
				q.push(v[now][i]);
			}
		}
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b); // A -> B �̵�
		//���� ���� ����.
		d[b] += 1;
	}
	topology_sort();
}