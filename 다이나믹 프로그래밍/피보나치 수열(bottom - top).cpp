#include <iostream>
using namespace std;

long long d[100];
int n;

int main() {
	d[1] = 1;
	d[2] = 1;
	n = 99;

	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}
	cout << d[n] << endl;
}