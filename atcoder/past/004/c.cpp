#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> a(n), b(n, string(m, '0'));
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int y = max(0, i - 1); y <= min(n - 1, i + 1); ++y) {
				for (int x = max(0, j - 1); x <= min(m - 1, j + 1); ++x) {
					b[i][j] += a[y][x] == '#';
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << b[i] << endl;
	}
	return 0;
}
