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

int64_t solve(int64_t N, std::vector<int64_t> a, std::vector<std::string> c) {
	int t[128] = {};
	t['R'] = 0;
	t['G'] = 1;
	t['B'] = 2;
	vector<vector<int64_t>> v(3);
	for (int i = 0; i < 2 * N; i++) {
		v[t[c[i][0]]].emplace_back(a[i]);
	}
	if (v[0].size() % 2 == 0) {
		swap(v[0], v[1]);
	}
	if (v[1].size() % 2 == 0) {
		swap(v[1], v[2]);
	}
	if (v[0].size() % 2 == 0) {
		return 0;
	}
	for (int i = 0; i < 3; ++i) {
		sort(v[i].begin(), v[i].end());
	}
	auto get_min = [&](const vector<int64_t>& a, const vector<int64_t>& b) {
		int64_t ans = 1LL << 60;
		int i = 0;
		for (auto x : a) {
			while (i < b.size() - 1 && abs(x - b[i]) >= abs(x - b[i + 1])) {
				++i;
			}
			ans = min(ans, abs(x - b[i]));
		}
		return ans;
	};
	int64_t ans = get_min(v[0], v[1]);
	if (!v[2].empty()) {
		ans = min(ans, get_min(v[0], v[2]) + get_min(v[1], v[2]));
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> a(2*N);
	std::vector<std::string> c(2*N);
	for (int i = 0; i < 2*N; i++) {
		std::cin >> a[i] >> c[i];
	}
	cout << solve(N, std::move(a), std::move(c)) << endl;
	return 0;
}
