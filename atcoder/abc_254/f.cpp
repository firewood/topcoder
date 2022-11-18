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

template<typename T> inline T gcd(const T& a, const T& b) { return b ? gcd(b, a % b) : a; }

template<typename T, int64_t SIZE, T DEF_VAL, T Compare(const T&, const T&)>
class SegmentTree {
	vector<T> val;
public:
	SegmentTree() : val(SIZE * 2, DEF_VAL) { }
	void update(int64_t i, const T& value) {
		i += SIZE;
		val[i] = value;
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
typedef SegmentTree<int64_t, 1 << 18, 0, gcd<int64_t>> GcdSegTree;

vector<int64_t> solve(int64_t N, int64_t Q, vector<int64_t> A, vector<int64_t> B, vector<int64_t> h1, vector<int64_t> h2, vector<int64_t> w1, vector<int64_t> w2) {
	vector<int64_t> ans(Q);
	GcdSegTree a, b;
	for (int i = 1; i < N; ++i) {
		a.update(i, abs(A[i] - A[i - 1]));
		b.update(i, abs(B[i] - B[i - 1]));
	}
	for (int i = 0; i < Q; ++i) {
		ans[i] = gcd(A[h1[i] - 1] + B[w1[i] - 1], gcd(a.get(h1[i], h2[i]), b.get(w1[i], w2[i])));
	}
	return ans;
}

int main() {
	int64_t N, Q;
	cin >> N >> Q;
	std::vector<int64_t> A(N), B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		std::cin >> B[i];
	}
	std::vector<int64_t> h1(Q), h2(Q), w1(Q), w2(Q);
	for (int i = 0; i < Q; ++i) {
		cin >> h1[i] >> h2[i] >> w1[i] >> w2[i];
	}
	vector<int64_t> ans = solve(N, Q, A, B, h1, h2, w1, w2);
	for (size_t i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
