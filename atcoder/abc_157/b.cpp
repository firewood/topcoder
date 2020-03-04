// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int a[3][3];
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> a[i][j];
		}
	}
	int n, x;
	cin >> n;
	for (int k = 0; k < n; ++k) {
		cin >> x;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (x == a[i][j]) {
					a[i][j] = -1;
				}
			}
		}
	}
	bool ans = false;
	auto ok = [&](int y, int x, int dy, int dx) {
		int cnt = 0;
		for (int i = 0; i < 3; ++i) {
			cnt += a[y + dy * i][x + dx * i] < 0;
		}
		return cnt >= 3;
	};
	for (int i = 0; i < 3; ++i) {
		if (ok(0, i, 1, 0)) ans = true;
		if (ok(i, 0, 0, 1)) ans = true;
	}
	if (ok(0, 0, 1, 1)) ans = true;
	if (ok(2, 0, -1, 1)) ans = true;
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
