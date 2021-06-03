#include <iostream>

using namespace std;

int n, m;
int d[100001]; // 부모테이블


//특정 원소가 속한 집합찾기.
int findunion(int x) {
	if (d[x] == x)
		return x;
	return findunion(d[x]);
	
}
/*
// 특정 원소가 속한 집합을 찾기
int findunion(int x) {
    // 루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
    if (x == d[x]) return x;
    return d[x] = findunion(d[x]);
}
*/
// 두 원소가 속한 집합을 합치기
void uniond(int a, int b) {
	a = findunion(a);
	b = findunion(b);
	if (a < b)
		d[b] = a;
	else
		d[a] = b;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		d[i] = i; // 자기자신을 부모로 초기화.
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		uniond(a, b);
	}
	// 각 원소가 속한 집합 출력하기
	cout << "각 원소가 속한 집합: ";
	for (int i = 1; i <= n; i++) {
		cout << findunion(i) << ' ';
	}
	cout << endl;

	// 부모 테이블 내용 출력하기
	cout << "부모 테이블: ";
	for (int i = 1; i <= n; i++) {
		cout << d[i] << ' ';
	}
	cout << endl;
}