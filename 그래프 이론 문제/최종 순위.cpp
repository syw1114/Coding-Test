#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int testcase,n,m;
int arr[501];
bool graph[501][501];
int main() {
	cin >> testcase;
	for (int tc = 0; tc < testcase; tc++) {
		fill(arr, arr + 501, 0);
		for (int i = 0; i < 501; i++) {
			fill(graph, graph + 501, false);
		}
		cin >> n;
		vector<int>v;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			v.push_back(x);
		}

	}
	
}