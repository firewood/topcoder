// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]) {
	int r, c, k, ans = 0;
	cin >> r >> c >> k;
	vector<vector<int>> ud(r + 1, vector<int>(c)), du(r + 1, vector<int>(c));
	vector<string> b(r);
	for (int i = 0; i < r; ++i) {
		cin >> b[i];
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (b[i][j] == 'o') {
				ud[i + 1][j] = ud[i][j] + 1;
			}
		}
	}
	for (int i = r - 1; i >= 0; --i) {
		for (int j = 0; j < c; ++j) {
			if (b[i][j] == 'o') {
				du[i][j] = du[i + 1][j] + 1;
			}
		}
	}
	for (int i = k - 1; i <= r - k; ++i) {
		for (int j = k - 1; j <= c - k; ++j) {
			bool ok = true;
			for (int l = -k + 1; l < k; ++l) {
				if (ud[i + 1][j + l] < k - abs(l)) {
					ok = false;
				}
				if (du[i][j + l] < k - abs(l)) {
					ok = false;
				}
			}
			ans += ok;
		}
	}
	cout << ans << endl;
	return 0;
}
