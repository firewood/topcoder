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

int solve(long long N, long long L, long long K, std::vector<long long>& a) {
	a.emplace_back(L);
	int left = 0, right = 1 << 30;
	auto possible = [&](int t) -> bool {
		int k = 0, len = 0, prev = 0;
		for (auto x : a) {
			len += x - prev;
			prev = x;
			if (len >= t) {
				++k;
				len = 0;
			}
		}
		return k >= K + 1;
	};
	while (right - left > 1) {
		int mid = (left + right) / 2;
		if (possible(mid)) {
			left = mid;
		} else {
			right = mid;
		}
	}
	return left;
}

int main() {
	long long N, L, K;
	std::cin >> N >> L >> K;
	std::vector<long long> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	cout << solve(N, L, K, a) << endl;
	return 0;
}
