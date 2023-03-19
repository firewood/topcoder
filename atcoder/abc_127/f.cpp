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
#include <atcoder/fenwicktree>

using namespace std;

int main() {
	int64_t Q, type, pos = -1, ans, seq = 0, adj = 0;
	atcoder::fenwick_tree<int64_t> cnt(200002), sum(200002);
	cin >> Q;
	vector<int64_t> t(Q), a(Q), b(Q);
	map <int64_t, int64_t> m, rev;
	for (int i = 0; i < Q; ++i) {
		cin >> t[i];
		if (t[i] == 1) {
			cin >> a[i] >> b[i];
			m[a[i]] = 0;
		}
	}
	for (auto& kv : m) {
		rev[seq] = kv.first;
		kv.second = seq++;
	}

	auto calc = [&](int64_t pos) {
		int64_t center = rev[pos];
		return center * cnt.sum(0, pos) - sum.sum(0, pos) + sum.sum(pos + 1, 200002) - center * cnt.sum(pos + 1, 200002) + adj;
	};

	set<int64_t> s;

	for (int i = 0; i < Q; ++i) {
		if (t[i] == 1) {
			int64_t k = m[a[i]];
			adj += b[i];
			cnt.add(k, 1);
			sum.add(k, a[i]);
			s.insert(k);
			if (pos < 0) {
				pos = k;
				ans = calc(k);
			} else {
				ans = calc(pos);
				auto it = s.find(pos);
				if (it != s.begin()) {
					--it;
					int64_t x = calc(*it);
					if (x <= ans) {
						pos = *it;
						ans = x;
					}
				}
				it = s.lower_bound(pos + 1);
				if (it != s.end()) {
					int64_t x = calc(*it);
					if (x < ans) {
						pos = *it;
						ans = x;
					}
				}
			}
		}
		if (t[i] == 2) {
			cout << rev[pos] << " " << ans << endl;
		}
	}

	return 0;
}
