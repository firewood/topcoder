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

template<typename T> inline T maximum(const T& a, const T& b) { return max(a, b); }

template<typename T, long long SIZE, T DEF_VAL, T Compare(const T&, const T&)>
class SegmentTree {
	vector<T> val;
public:
	SegmentTree() : val(SIZE * 2, DEF_VAL) { }
	void update(long long i, const T& value) {
		i += SIZE;
		val[i] = Compare(val[i], value);
		while (i > 1) i >>= 1, val[i] = Compare(val[i * 2], val[i * 2 + 1]);
	}
	T get(long long a, long long b, long long l = 0, long long r = SIZE, long long i = 1) {
		if (r <= a || b <= l) return DEF_VAL;
		if (a <= l && r <= b) return val[i];
		return Compare(get(a, b, l, (l + r) / 2, i * 2), get(a, b, (l + r) / 2, r, i * 2 + 1));
	}
};

int solve(long long N, std::vector<int> &w, std::vector<int> &h) {
	vector<int> seq(N);
	iota(seq.begin(), seq.end(), 0);
	sort(seq.begin(), seq.end(), [&](int lhs, int rhs) {
		return make_pair(-w[lhs], h[lhs]) < make_pair(-w[rhs], h[rhs]);
	});

	SegmentTree<int, 1 << 18, 0, maximum<int>> segtree;
	for (int i = 0; i < N; ++i) {
		segtree.update(h[seq[i]], 1 + segtree.get(h[seq[i]] + 1, 1 << 18));
	}
	return segtree.get(0, 1 << 18);
}

int main() {
    long long N;
	std::cin >> N;
	std::vector<int> w(N), h(N);
	for (int i = 0; i < N; i++) {
		std::cin >> w[i] >> h[i];
	}
	cout << solve(N, w, h) << endl;
	return 0;
}
