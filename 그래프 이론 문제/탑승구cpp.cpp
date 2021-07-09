#include <iostream>

using namespace std;
int n , m;
int arr[10001];
int findparent(int x) {
	if (arr[x] == x)
		return x;
	return findparent(arr[x]);
}
void union_parent(int a, int b) {
	a = findparent(a);
	b = findparent(b);
	if (a < b) arr[b] = a;
	else arr[a] = b;
}
int main() {
	cin >> n >> m;
	//자기자신을 부모노드로 초기화.
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}
	int result = 0;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		int root = findparent(x);
		if (root == 0) break;
		union_parent(root, root - 1);
		result += 1;
	}
	cout << result; 
}