#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int n, m, x, y = 0, dim[3];
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> dim[0] >> dim[1] >> dim[2];
		int mn[3] = { 1 << 30, 1 << 30, 1 << 30 };
		int mx[3] = { -1, -1, -1 };
		cin >> m;
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < 3; ++k) {
				cin >> x;
				mn[k] = min(mn[k], x);
				mx[k] = max(mx[k], x);
			}
		}
		for (int k = 0; k < 3; ++k) {
			y ^= mn[k];
			y ^= dim[k] - mx[k] - 1;
		}
	}
	cout << (y ? "WIN" : "LOSE") << endl;
	return 0;
}
