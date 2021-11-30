#include<iostream>
#include<algorithm>
#include<fstream>
#pragma warning(disable:4996)
using namespace std;

ifstream input_fp("grid1.inp");
ofstream output_fp("grid1.out");
int N = 1;
int arr[10001][10001];
int xy[4] = { -1,1,-1,1 };
int check;
int tt = 1;
void pro(int n, int m,int t, int s,int k) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = N;
			N++;
		}
	}
	N = 1;
	if (s == 1) {
		check = 0;
		int x = 0;
		int y = 0;
		if (t == 1) {
			for(int i= 1; i< k; i++){
				if (check == 0 && x < m-1) {
					x = x + xy[3];
				}
				else if (x == m - 1 && check == 0) {
					check = 1;
					y = y + xy[1];
				}
				else if (check == 1 && x > 0) {
					x = x + xy[2];
				}
				else if (check == 1 && x == 0) {
					check = 0;
					y = y + xy[1];
				}
			}
			cout << arr[y][x] << "\n";
		}
		if (t == 2) {
			for (int i = 1; i < k; i++) {
				if (check == 0 && y < n - 1) {
					y = y + xy[1];
				}
				else if (y == n - 1 && check == 0) {
					check = 1;
					x = x + xy[3];
				}
				else if (check == 1 && y > 0) {
					y = y + xy[0];
				}
				else if (check == 1 && y == 0) {
					check = 0;
					x = x + xy[3];
				}
			}
			cout << arr[y][x] << "\n";
		}
	}
	if (s == 2) {
		int x = m-1;
		int y = 0;
		check = 1;
		if (t == 1) {
			for (int i = 1; i < k; i++) {
				if (check == 1 && x > 0) {
					x = x + xy[2];
				}
				else if (x == 0 && check == 1) {
					check = 0;
					y = y + xy[1];
				}
				else if (check == 0 && x < m-1) {
					x = x + xy[3];
				}
				else if (check == 0 && x == m-1) {
					check = 1;
					y = y + xy[1];
				}
			}
			cout << arr[y][x] << "\n";
		}
		if (t == 2) {
			for (int i = 1; i < k; i++) {
				if (check == 1 && y < n - 1) {
					y = y + xy[1];
				}
				else if (y == n - 1 && check == 1) {
					check = 0;
					x = x + xy[2];
				}
				else if (check == 0 && y > 0) {
					y = y + xy[0];
				}
				else if (check == 0 && y == 0) {
					check = 1;
					x = x + xy[2];
				}
			}
			cout << arr[y][x] << "\n";
		}
	}
	if (s == 3) {
		int x = m - 1;
		int y = n - 1;
		check = 1;
		if (t == 1) {
			for (int i = 1; i < k; i++) {
				if (check == 1 && x > 0) {
					x = x + xy[2];
				}
				else if (x == 0 && check == 1) {
					check = 0;
					y = y + xy[0];
				}
				else if (check == 0 && x < m - 1) {
					x = x + xy[3];
				}
				else if (check == 0 && x == m - 1) {
					check = 1;
					y = y + xy[0];
				}
			}
			cout << arr[y][x] << "\n";
		}
		if (t == 2) {
			for (int i = 1; i < k; i++) {
				if (check == 1 && y > 0) {
					y = y + xy[0];
				}
				else if (y == 0 && check == 1) {
					check = 0;
					x = x + xy[2];
				}
				else if (check == 0 && y < n-1) {
					y = y + xy[1];
				}
				else if (check == 0 && y == n-1) {
					check = 1;
					x = x + xy[2];
				}
			}
			cout << arr[y][x] << "\n";
		}
	}
	if (s == 4) {
		int x = 0;
		int y = n - 1;
		check = 0;
		if (t == 1) {
			for (int i = 1; i < k; i++) {
				if (check == 0 && x < m-1) {
					x = x + xy[3];
				}
				else if (x == m-1 && check == 0) {
					check = 1;
					y = y + xy[0];
				}
				else if (check == 1 && x > 0) {
					x = x + xy[2];
				}
				else if (check == 1 && x == 0) {
					check = 0;
					y = y + xy[0];
				}
			}
			cout << arr[y][x] << "\n";
		}
		if (t == 2) {
			for (int i = 1; i < k; i++) {
				if (check == 0 && y > 0) {
					y = y + xy[0];
				}
				else if (y == 0 && check == 0) {
					check = 1;
					x = x + xy[3];
				}
				else if (check == 1 && y < n - 1) {
					y = y + xy[1];
				}
				else if (check == 1 && y == n - 1) {
					check = 0;
					x = x + xy[3];
				}
			}
			cout << arr[y][x] << "\n";
		}
	}
}


int main() {
	int num,n,m,t,s,k;
	input_fp >> num;
	for (int i = 0; i < num; i++) {
		input_fp >> n >> m >> t >> s >> k;
		pro(n,m,t,s,k);
	}
}