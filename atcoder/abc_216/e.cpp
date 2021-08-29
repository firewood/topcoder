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

int64_t solve(int64_t N, int64_t K, std::vector<int64_t> A) {
	int64_t ans = 0, prev = 0, count = 0, rk = K;
	map<int64_t, int64_t> m;
	for (int i = 0; i < N; ++i) {
		m[A[i]] += 1;
	}
	m[0] += 1;
	for (auto it = m.rbegin(); it != m.rend(); ++it) {
		if (count > 0) {
			int64_t diff = prev - it->first;
			int64_t c = min(rk, diff * count);
			int64_t x = c / count;
			int64_t y = prev - x;
			ans += (y * x + ((x + 1) * x) / 2) * count;
			c -= x * count;
			rk -= x * count;
			if (c > 0 && y > 0) {
				ans += c * y;
				rk -= c;
			}
		}
		prev = it->first;
		count += it->second;
	}
	return ans;
}

int main() {
	int64_t N, K;
	std::cin >> N >> K;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, K, A) << endl;
	return 0;
}
