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

typedef long long LL;
static const LL INF = 1LL << 60;

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
	long long find_leftmost_index(long long a, long long b, const T& value, long long l = 0, long long r = SIZE, long long i = 1) {
		if (Compare(val[i], value) != val[i]) return -1;
		if (r <= a || b <= l) return -1;
		if (i >= SIZE) return i - SIZE;
		long long leftmost_index = find_leftmost_index(a, b, value, l, (l + r) / 2, i * 2);
		if (leftmost_index >= 0) return leftmost_index;
		return find_leftmost_index(a, b, value, (l + r) / 2, r, i * 2 + 1);
	}
	long long find_rightmost_index(long long a, long long b, const T& value, long long l = 0, long long r = SIZE, long long i = 1) {
		if (Compare(val[i], value) != val[i]) return -1;
		if (r <= a || b <= l) return -1;
		if (i >= SIZE) return i - SIZE;
		long long rightmost_index = find_rightmost_index(a, b, value, (l + r) / 2, r, i * 2 + 1);
		if (rightmost_index >= 0) return rightmost_index;
		return find_rightmost_index(a, b, value, l, (l + r) / 2, i * 2);
	}
};

LL exclusiveOr(const LL& a, const LL& b) {
	return a ^ b;
}

void solve(long long N, long long Q, std::vector<long long> &A, std::vector<long long> &T, std::vector<long long> &X, std::vector<long long> &Y) {
	SegmentTree < LL, 1 << 19, 0, exclusiveOr > st;
	for (LL i = 0; i < N; ++i) {
		st.update(i, A[i]);
	}
	for (LL i = 0; i < Q; ++i) {
		if (T[i] == 1) {
			st.update(X[i] - 1, Y[i]);
		} else {
			cout << st.get(X[i] - 1, Y[i]) << endl;
		}
	}
}

int main() {
	long long N, Q;
	std::cin >> N >> Q;
	std::vector<long long> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	std::vector<long long> T(Q), X(Q), Y(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> T[i] >> X[i] >> Y[i];
	}
	solve(N, Q, A, T, X, Y);
	return 0;
}
