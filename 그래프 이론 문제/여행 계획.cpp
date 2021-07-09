#include <iostream>
#include <vector>

using namespace std;
int n,m;
int arr[501];

int findunion(int x) {
	if (arr[x] == x)
		return x;
	//재귀적으로 루트노드찾기.
	return findunion(arr[x]);

}
//두 원소가 속한 집합 합치기.
void union_parent(int a, int b) {
	a = findunion(a);
	b = findunion(b);
	if (a < b) arr[b] = a;
	else arr[a] = b;
}

int main() {
	cin >> n >> m;

	// 부모테이블에서 자기자신을 부모로 초기화.
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}

	//서로 연결된경우 합집합 연산 수행.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			if (x == 1) {
				union_parent(i + 1, j + 1);
			}
		}
	}
	//여행계획 입력받기.
	vector<int>plan;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		plan.push_back(x);
	}
	bool result = true;
	for (int i = 0; i < m - 1; i++) {
		if (findunion(plan[i]) != findunion(plan[i + 1])) {
			result = false;
		}
	}
	if (result) cout << "YES" << endl;
	else cout << "NO" << endl;
}