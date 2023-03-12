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

int64_t solve(vector<int64_t>& x) {
	int64_t ans = 0;
	while (true) {
		sort(x.begin(), x.end());
		if (x[0] + 2 <= x[1] && x[1] + 2 <= x[2]) {
			int64_t a = min(x[1] - x[0], x[2] - x[1]) / 2;
			ans += a;
			x[0] += a * 4;
			x[1] += a * 2;
		} else if (x[1] + 6 <= x[2]) {
			int64_t a = (x[2] - x[1]) / 6;
			ans += a * 2;
			x[2] -= a * 6;
		} else if (x[0] + 6 <= x[1]) {
			int64_t a = (x[1] - x[0]) / 6;
			ans += a * 2;
			x[0] += a * 6;
		} else {
			break;
		}
	}
	for (int i = 0; i < 10; ++i) {
		sort(x.begin(), x.end());
		if (x[0] + 4 <= x[2]) {
			x[0] += 4;
			x[1] += 2;
		} else {
			break;
		}
	}
	sort(x.begin(), x.end());
	return x[0] == x[2] ? ans : -1;
}

int main() {
	int64_t T;
	vector<int64_t> x(3);
	cin >> T;
	for (int tt = 0; tt < T; ++tt) {
		for (int i = 0; i < 3; ++i) {
			cin >> x[i];
		}
		cout << solve(x) << endl;
	}
	return 0;
}
