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

int64_t solve(int64_t N, int64_t K, std::vector<int64_t> c) {
	int ans = 0, cnt = 0;
	map<int, int> m;
	for (int i = 0; i < N; ++i) {
		cnt += m[c[i]] == 0;
		m[c[i]] += 1;
		if (i >= K) {
			m[c[i - K]] -= 1;
			cnt -= m[c[i - K]] == 0;
		}
		ans = max(ans, cnt);
	}
	return ans;
}

int main() {
	int64_t N, K;
	std::cin >> N >> K;
	std::vector<int64_t> c(N);
	for (int i = 0; i < N; i++) {
		std::cin >> c[i];
	}
	cout << solve(N, K, std::move(c)) << endl;
	return 0;
}
