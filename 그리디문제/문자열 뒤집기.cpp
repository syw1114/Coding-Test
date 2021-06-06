#include <iostream>
#include <string>
using namespace std;

string str;

int main() {
	cin >> str;
	int count0 = 0;
	int count1 = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != str[i + 1]) {
			if (str[i + 1] == '1')
				count1 += 1;
		}
		else
			count0 += 1;
	}
	cout << min(count1, count0) << endl;
}