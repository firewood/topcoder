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

int64_t solve(int64_t N, std::vector<int64_t> H, std::vector<int64_t> S) {
	int64_t left = -1, right = 1LL << 60;
	auto possible = [&](int64_t x) -> bool {
		vector< int64_t > v(N);
		for (int i = 0; i < N; ++i) {
			int64_t d = (x - H[i]);
			if (d < 0) return false;
			v[i] = d / S[i];
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < N; ++i) {
			if (v[i] < i) {
				return false;
			}
		}
		return true;
	};
	while (right - left > 1) {
		int64_t mid = (left + right) / 2;
		if (possible(mid)) {
			right = mid;
		} else {
			left = mid;
		}
	}
	return right;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> H(N), S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> H[i] >> S[i];
	}
	cout << solve(N, H, S) << endl;
	return 0;
}
