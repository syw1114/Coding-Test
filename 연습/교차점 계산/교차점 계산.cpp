#include<iostream>
#include<algorithm>
#include<fstream>
#pragma warning(disable:4996)
using namespace std;

ifstream input_fp("cross.inp");
ofstream output_fp("cross.out");
int arr[1001];
int arr2[1001];
int result[1001];
void solution(int n){
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int check = 0;
			if (arr[i] == arr2[j]) {
				for (int count = i; count < n; count++) {
					for (int count2 = j; count2 < n; count2++) {
						if (arr[count+1] == arr2[count2+1]) {
							check++;
						}
					}
				}
				for (int count = i; count > 0; --count) {
					for (int count2 = j; count2 > 0; --count2) {
						if (arr[count] == arr2[count2]) {
							check++;
						}
					}
				}
				sum += n - (check);
			}
		}
	}
	cout << sum/2 << '\n';
}
int main() {
	int c;
	input_fp >> c;
	for (int i = 0; i < c; i++) {
		int n;
		input_fp >> n;
		for (int j = 1; j <= n; j++) {
			input_fp >> arr[j];
		}
		for (int j = 1; j <= n; j++) {
			input_fp >> arr2[j];
		}
		for (int j = 0; j <= n; j++) {
			result[j] = 0;
		}
		solution(n);
	}
 }