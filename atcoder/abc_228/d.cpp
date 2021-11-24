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

vector<int64_t> solve(int64_t Q, std::vector<int64_t> t, std::vector<int64_t> x) {
    const int64_t N = 1LL << 20;
    vector<int64_t> ans, seq(N), val(N, -1);
#if 1
	iota(seq.begin(), seq.end(), 0);
	set<int64_t> s(seq.begin(), seq.end());
	for (int i = 0; i < Q; ++i) {
		int64_t xi = x[i] % N;
		if (t[i] == 1) {
			auto it = s.lower_bound(xi);
			if (it == s.end()) {
				it = s.lower_bound(0);
			}
			val[*it] = x[i];
			s.erase(it);
		} else {
			ans.emplace_back(val[xi]);
		}
	}
#else
	map<int64_t, int64_t> m;
	m[0] = 0;
	auto find = [&](int64_t xi) {
		auto it = m.lower_bound(xi);
		if (it != m.begin()) {
			auto prev = it;
			--prev;
			if (prev->first + prev->second >= xi) {
				return prev;
			}
		}
		if (it != m.end() && it->first == xi) {
			return it;
		}
		m[xi] = 0;
		return m.find(xi);
	};
	for (int i = 0; i < Q; ++i) {
		int64_t xi = x[i] % N;
		if (t[i] == 1) {
			auto it = find(xi);
			if (it->first + it->second >= N) {
				it = m.begin();
			}
			val[it->first + it->second] = x[i];
			it->second += 1;

			auto next = m.find(it->first + it->second);
			if (next != m.end()) {
				it->second += next->second;
				m.erase(next);
			}
		} else {
			ans.emplace_back(val[xi]);
		}
	}
#endif
	return ans;
}

int main() {
	int64_t Q;
	std::cin >> Q;
	std::vector<int64_t> t(Q), x(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> t[i] >> x[i];
	}
	vector<int64_t> ans = solve(Q, t, x);
	for (auto x : ans) {
		cout << x << endl;
	}
	return 0;
}
