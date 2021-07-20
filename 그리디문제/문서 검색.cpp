#include <iostream>
#include<string>

using namespace std;

string a, b;


int main() {
	getline(cin,a);
	getline(cin,b);

	if (a.size() < b.size())

		cout << 0 << "\n";

	else {
		int sum = 0;
		for (int i = 0; i < a.size() - b.size() + 1; i++)
		{
			bool check = true;
			for (int j = 0; j < b.size(); j++)
			{
				check = true;
				if (a[i + j] != b[j]) {
					check = false;
					break;
				}
			}
			if (check) {
				sum++;
				i += b.size();
			}
		}
		cout << sum;

	}

	return 0;

}