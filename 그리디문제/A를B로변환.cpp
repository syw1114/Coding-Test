#include<iostream>
#include <string>
using namespace std;

int n, m;
string str;
int sum = 1;
int main() {
	cin >> n >> m;
	str = to_string(m);
	while (true) {
		if (str[str.length()-1] == '1') {
			sum++;
			str = str.substr(0, str.length() - 1);
			m = stoi(str);
		}
		else if (m%2 == 0) {
			m = m / 2;
			sum++;
			str = to_string(m);
		}
		else if (m % 2 == 1) {
			sum = -1;
			break;
		}
		if (n == m)
			break;
		else if (n > m) {
			sum = -1;
			break;
		}
	}
	cout << sum;
}