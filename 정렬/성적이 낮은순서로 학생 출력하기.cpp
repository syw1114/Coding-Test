#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
class student {
public : 
	string name;
	int score;
	student(string name, int score) {
		this->name = name;
		this->score = score;
	}
	bool operator < (student&other) {
		return this->score < other.score;   
	}
};  
vector<student>v;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name;
		int score;
		cin >> name >> score;
		v.push_back(student(name, score));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		cout << v[i].name << ' ';
	}
}