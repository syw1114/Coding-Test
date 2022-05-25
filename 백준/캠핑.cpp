#include <iostream>
using namespace std;

int main() {
	int L, P, V;
	int i = 1;
	for (;;) {
		cin >> L >> P >> V;
		int cnt = 0;
		if (L == 0 && P == 0 && V == 0) {
			break;
		}
		int ans = (V / P) * L + min((V % P), L);
		cout << "Case " <<i<< ": " << ans << "\n";
		i++;
	}
}