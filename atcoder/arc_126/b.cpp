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
#include <random>
#include <atcoder/maxflow>

using namespace std;
using namespace atcoder;

template<typename T> inline T maximum(const T& a, const T& b) { return max(a, b); }

template<typename T, int64_t SIZE, T DEF_VAL, T Compare(const T&, const T&)>
struct SegmentTree {
	vector<T> val;
public:
	SegmentTree() : val(SIZE * 2, DEF_VAL) { }
	void update(int64_t i, const T& value) {
		i += SIZE;
		val[i] = Compare(val[i], value);
		while (i > 1) i >>= 1, val[i] = Compare(val[i * 2], val[i * 2 + 1]);
	}
	T get(int64_t a, int64_t b, int64_t l = 0, int64_t r = SIZE, int64_t i = 1) {
		if (r <= a || b <= l) return DEF_VAL;
		if (a <= l && r <= b) return val[i];
		return Compare(get(a, b, l, (l + r) / 2, i * 2), get(a, b, (l + r) / 2, r, i * 2 + 1));
	}
	int64_t find_leftmost_index(int64_t a, int64_t b, const T& value, int64_t l = 0, int64_t r = SIZE, int64_t i = 1) {
		if (Compare(val[i], value) != val[i]) return -1;
		if (r <= a || b <= l) return -1;
		if (i >= SIZE) return i - SIZE;
		int64_t leftmost_index = find_leftmost_index(a, b, value, l, (l + r) / 2, i * 2);
		if (leftmost_index >= 0) return leftmost_index;
		return find_leftmost_index(a, b, value, (l + r) / 2, r, i * 2 + 1);
	}
	int64_t find_rightmost_index(int64_t a, int64_t b, const T& value, int64_t l = 0, int64_t r = SIZE, int64_t i = 1) {
		if (Compare(val[i], value) != val[i]) return -1;
		if (r <= a || b <= l) return -1;
		if (i >= SIZE) return i - SIZE;
		int64_t rightmost_index = find_rightmost_index(a, b, value, (l + r) / 2, r, i * 2 + 1);
		if (rightmost_index >= 0) return rightmost_index;
		return find_rightmost_index(a, b, value, l, (l + r) / 2, i * 2);
	}
};
typedef SegmentTree<int, 1 << 18, 0, maximum<int>> MaxSegTree;

int solve(int N, int M, std::vector<int> a, std::vector<int> b) {
	MaxSegTree st;
	map<int, vector<int>> m;
	for (int i = 0; i < M; i++) {
		m[a[i]].emplace_back(b[i]);
	}
	for (auto kv : m) {
		vector<int> v = kv.second;
		sort(v.rbegin(), v.rend());
		for (int x : v) {
			st.update(x, st.get(0, x) + 1);
		}
	}
	return st.get(0, N + 1);
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> a(M), b(M);
	for (int i = 0; i < M; i++) {
		std::cin >> a[i] >> b[i];
	}
	int ans = solve(N, M, a, b);
	cout << ans << endl;
	return 0;
}
