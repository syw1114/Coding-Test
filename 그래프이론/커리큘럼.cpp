#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> v[501];
int d[501]; // ��������
int times[501]; // �� ���ǽð�.

void topology_sort() {
	vector<int> result(501);

	queue<int>q;
	for (int i = 1; i <= n; i++) {
		result[i] = times[i];
	}

	for (int i= 1; i <= n; i++) {
		if (d[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			result[v[now][i]] = max(result[v[now][i]], result[now] + times[v[now][i]]);
			d[v[now][i]] -= 1;
			// ���Ӱ� ���������� 0�� �Ǵ� ��带 ť�� ����
			if (d[v[now][i]] == 0) {
				q.push(v[now][i]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << result[i] << '\n';
	}
}


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; 
		cin >> x;
		times[i] = x; // ���ǽð�
		// �ش� ���Ǹ� ������� ���� �����ϴ� ����.
		while (true){
			cin >> x;
			if (x == -1) break;
			d[i] += 1;
			v[x].push_back(i); 
		}
		}
	topology_sort();
}