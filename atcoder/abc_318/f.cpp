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

static const int64_t INF = 1LL << 61;

int64_t solve(int64_t N, std::vector<int64_t> X, std::vector<int64_t> L) {
	int64_t ans = 0;

	set<int64_t> s;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int d = -1; d <= 1; ++d) {
				s.insert(X[i] - L[j] + d);
				s.insert(X[i] + L[j] + d);
			}
		}
	}

	auto possible = [&](int64_t t) -> bool {
		vector<int64_t> v(N);
		for (int i = 0; i < N; ++i) {
			v[i] = abs(X[i] - t);
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < N; ++i) {
			if (v[i] > L[i]) {
				return false;
			}
		}
		return true;
	};

	int64_t valid = INF;
	for (auto x : s) {
		if (possible(x)) {
			valid = min(valid, x);
		} else {
			ans += max(int64_t(0), x - valid);
			valid = INF;
		}
	}

	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> X(N);
	for (int i = 0; i < N; i++) {
		std::cin >> X[i];
	}
	std::vector<int64_t> L(N);
	for (int i = 0; i < N; i++) {
		std::cin >> L[i];
	}
	cout << solve(N, X, L) << endl;
	return 0;
}
