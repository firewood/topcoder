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

typedef pair<int, int> II;

using S = int64_t;
using F = int64_t;
S op(S x, S y) { return max(x, y); }
S mapping(F t, S x) { return t + x; }
F composition(F t, F s) { return t + s; }
S e() { return -(1LL << 60); }
F id() { return 0; }

int64_t solve(int N, int D, int W, std::vector<int> T, std::vector<int> X) {
	int64_t ans = 0;

	vector<int64_t> data(400004);
	atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>seg(data);

	vector<II> v;
	for (int i = 0; i < N; ++i) {
		v.emplace_back(II(X[i], i));
	}
	sort(v.begin(), v.end());

	int left = 0;
	for (int vi = 0; vi < N; ++vi) {
		int i = v[vi].second;
		while (left < vi && X[v[left].second] + W <= X[i]) {
			int j = v[left].second;
			seg.apply(T[j], T[j] + D, -1);
			++left;
		}
		seg.apply(T[i], T[i] + D, 1);
		ans = max(ans, seg.prod(0, 200002));
	}

	return ans;
}

int main() {
	int N, D, W;
	std::cin >> N >> D >> W;
	std::vector<int> T(N), X(N);
	for (int i = 0; i < N; i++) {
		std::cin >> T[i] >> X[i];
	}
	cout << solve(N, D, W, T, X) << endl;
	return 0;
}
