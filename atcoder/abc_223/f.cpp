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
#include <atcoder/lazysegtree>

using namespace std;

using S = int64_t;
using F = int64_t;

const int64_t INF = 1LL << 60;

S op(S a, S b) { return std::min(a, b); }
S e() { return INF; }
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

int main() {
	int N, Q, t, l, r;
	cin >> N >> Q;
	string s;
	cin >> s;

	std::vector<S> values(N);
	atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> segtree(values);

	for (int i = 0; i < N; ++i) {
		segtree.apply(i, N, s[i] == '(' ? 1 : -1);
	}

	for (int i = 0; i < Q; ++i) {
		cin >> t >> l >> r;
		--l, --r;
		if (t == 1) {
			if (s[l] != s[r]) {
				segtree.apply(l, N, s[l] == '(' ? -1 : 1);
				segtree.apply(r, N, s[r] == '(' ? -1 : 1);
				swap(s[l], s[r]);
				segtree.apply(l, N, s[l] == '(' ? 1 : -1);
				segtree.apply(r, N, s[r] == '(' ? 1 : -1);
			}
		} else {
			S st = segtree.get(l), ed = segtree.get(r);
			bool ok = s[l] == '(' && st - 1 == ed && segtree.prod(l, r + 1) >= ed;
			cout << (ok ? "Yes" : "No") << endl;
		}
	}

	return 0;
}
