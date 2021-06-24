// https://www.acmicpc.net/problem/10825
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int n;
class Student{
public:
	string name;
	int kor;
	int eng;
	int math;
	Student(string name, int kor, int eng, int math) {
		this->name = name;
		this->kor = kor;
		this->eng = eng;
		this->math = math;
	}
	bool operator < (Student &other) {
		if (this->kor == other.kor && this->eng == other.eng && this->math == other.math) {
			return this->name < other.name;
		}
		if (this->kor == other.kor && this->eng == other.eng) {
			return this->math > other.math;
		}
		if (this->kor == other.kor) {
			return this->eng < other.eng;
		}
		return this->kor > other.kor;
	}
};
vector<Student> v;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name;
		int kor, eng, math;
		cin >> name >> kor >> eng >> math;
		v.push_back(Student(name, kor, eng, math));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		cout << v[i].name << endl;
	}
}
