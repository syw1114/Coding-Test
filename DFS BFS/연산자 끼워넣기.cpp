#include <iostream>
#include <vector>

using namespace std;
vector<int> arr;
int n;
int add, sub,mul, divi;
int maxvalue = 0;
int minvalue = 0;

void dfs(int i, int now) {
	
	if (i == n) {
		maxvalue = max(maxvalue, now);
		minvalue = min(minvalue, now);
}	
	else {
		if (add > 0) {
			add--;
			dfs(i + 1, now + arr[i]);
			add++;
		}
		if (sub > 0) {
			sub--;
			dfs(i + 1, now - arr[i]);
			sub++;
		}
		if (mul > 0) {
			mul--;
			dfs(i + 1, now * arr[i]);
			mul++;
		}
		if (divi > 0) {
			divi--;
			dfs(i + 1, now / arr[i]);
			divi++;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
	
	cin >> add >> sub >> mul >> divi;
	dfs(1, arr[0]);

	cout << maxvalue << '\n' << minvalue << '\n';
}