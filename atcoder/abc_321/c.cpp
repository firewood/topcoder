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

int64_t solve(int64_t K) {
	vector<int64_t> v;
	for (int b = 2; b < (1 << 10); ++b) {
		int64_t x = 0;
		for (int d = 9; d >= 0; --d) {
			if (b & (1 << d)) {
				x = x * 10 + d;
			}
		}
		v.emplace_back(x);
	}
	sort(v.begin(), v.end());
	return v[K - 1];
}

int64_t solve2(int64_t K) {
	vector<int> x(16);
	int d = 1;
	for (int i = 0; i < K; ++i) {
		int k = d - 1;
		for (int j = d - 1; j >= 0; --j) {
			if (x[j] + 1 < x[j + 1]) {
				k = j;
			}
		}
		x[k] += 1;
		if (x[k] >= 10) {
			++d;
			++k;
			x[k] = d - 1;
		}
		for (int j = 0; j < k; ++j) {
			x[j] = j;
		}
	}

	int64_t ans = 0;
	for (int i = d - 1; i >= 0; --i) {
		ans = ans * 10 + x[i];
	}
	return ans;
}

int main() {
	int64_t K;
	std::cin >> K;
	cout << solve(K) << endl;
	return 0;
}
