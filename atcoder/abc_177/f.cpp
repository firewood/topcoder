#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
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

typedef long long LL;
static const LL INF = 1LL << 60;

template<typename T, int SIZE, T DEF_VAL, const T& Compare(const T&, const T&)>
class SegmentTree {
	vector<T> val;
public:
	SegmentTree() : val(SIZE * 2, DEF_VAL) { }
	void update(LL i, const T& value) {
		i += SIZE;
		val[i] = value;
		while (i > 1) i >>= 1, val[i] = Compare(val[i * 2], val[i * 2 + 1]);
	}
	T get(LL a, LL b, int l = 0, int r = SIZE, size_t i = 1) {
		if (r <= a || b <= l) return DEF_VAL;
		if (a <= l && r <= b) return val[i];
		return Compare(get(a, b, l, (l + r) / 2, i * 2), get(a, b, (l + r) / 2, r, i * 2 + 1));
	}
	LL find_leftmost_index(LL a, LL b, const T& value, int l = 0, int r = SIZE, int i = 1) {
		if (Compare(val[i], value) != val[i]) return -1;
		if (r <= a || b <= l) return -1;
		if (i >= SIZE) return i - SIZE;
		LL leftmost_index = find_leftmost_index(a, b, value, l, (l + r) / 2, i * 2);
		if (leftmost_index >= 0) return leftmost_index;
		return find_leftmost_index(a, b, value, (l + r) / 2, r, i * 2 + 1);
	}
	LL find_rightmost_index(LL a, LL b, const T& value, int l = 0, int r = SIZE, int i = 1) {
		if (Compare(val[i], value) != val[i]) return -1;
		if (r <= a || b <= l) return -1;
		if (i >= SIZE) return i - SIZE;
		LL rightmost_index = find_rightmost_index(a, b, value, (l + r) / 2, r, i * 2 + 1);
		if (rightmost_index >= 0) return rightmost_index;
		return find_rightmost_index(a, b, value, l, (l + r) / 2, i * 2);
	}
};

void solve(long long H, long long W, std::vector<long long> &A, std::vector<long long> &B) {
	SegmentTree<long long, 1 << 18, INF, min> st;
	for (int i = 0; i < W; ++i) {
		st.update(i, 0);
	}
	for (LL y = 0; y < H; ++y) {
		LL a = A[y] - 1, b = B[y];
		while (true) {
			LL min_value = st.get(a, b);
			if (min_value == INF) break;
			LL index = st.find_leftmost_index(a, b, min_value);
			LL next_cost = min_value + b - index;
			if (b < W && next_cost < st.get(b, b + 1)) {
				st.update(b, next_cost);
			}
			st.update(index, INF);
		}
		LL cost = y + 1 + st.get(0, W);
		cout << (cost < INF ? cost : -1) << endl;
	}
}

int main() {
    long long H;
	scanf("%lld", &H);
	long long W;
	scanf("%lld", &W);
	std::vector<long long> A(H);
	std::vector<long long> B(H);
	for (int i = 0; i < H; i++) {
		scanf("%lld", &A[i]);
		scanf("%lld", &B[i]);
	}
	solve(H, W, A, B);
	return 0;
}
