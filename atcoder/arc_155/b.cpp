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

vector<int64_t> solve(int64_t Q, int64_t A, int64_t B, std::vector<int64_t> t, std::vector<int64_t> a, std::vector<int64_t> b) {
	vector<int64_t> ans;
	set<int64_t> s;
	s.insert(A - B);
	s.insert(A + B);
	for (int i = 0; i < Q; ++i) {
		if (t[i] == 1) {
			s.insert(a[i] - b[i]);
			s.insert(a[i] + b[i]);
		}
		if (t[i] == 2) {
			int64_t value = 0;
			auto it = s.lower_bound(a[i]);
			if (it != s.end() && *it <= b[i]) {
				value = 0;
			} else if (it != s.end()) {
				value = *it - b[i];
				if (it != s.begin()) {
					--it;
					value = min(value, a[i] - *it);
				}
			} else {
				--it;
				value = a[i] - *it;
			}
			ans.emplace_back(value);
		}
	}
	return ans;
}

int main() {
	int64_t Q, A, B;
	std::cin >> Q >> A >> B;
	std::vector<int64_t> t(Q), a(Q), b(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> t[i] >> a[i] >> b[i];
	}
	vector<int64_t> ans = solve(Q, A, B, t, a, b);
	for (size_t i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
