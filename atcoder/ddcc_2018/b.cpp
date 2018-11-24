// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	int f[100][100] = {};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			f[i][j] = 1;
		}
	}
	int x = 0;
	for (int y = (n-1) / 2; y >= 0; --y) {
		for (int i = y; i >= 0; --i) {
			f[i][x] = 0;
			f[i][n - x - 1] = 0;
		}
		++x;
	}
	x = 0;
	for (int y = n - (n-1) / 2 - 1; y < n; ++y) {
		for (int i = y; i < n; ++i) {
			f[i][x] = 0;
			f[i][n - x - 1] = 0;
		}
		++x;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ans += f[i][j];
		}
	}
	cout << ans << endl;
	return 0;
}
