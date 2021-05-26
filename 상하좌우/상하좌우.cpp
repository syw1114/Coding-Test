#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string str;
	int x = 1, y = 1;

	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = {-1, 1 , 0 , 0 };

	char moveType[4] = { 'L','R','U','D' };

	cin.ignore();
	getline(cin, str);

	for (int i = 0; i < str.size(); i++) {
		char plan = str[i];
		int nx = 0, ny = 0;
		for (int j = 0; j < 4; j++) {
			if (plan == moveType[j]) {
				nx = x + dx[j];
				ny = y + dy[j];
			}
		}
		if (nx < 1 || ny < 1 || nx > n || ny > n)
			continue;
		x = nx;
		y = ny;
	}
	cout << x << ' ' << y << endl;
	
}