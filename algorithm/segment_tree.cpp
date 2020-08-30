#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;
typedef long long LL;

#ifdef _DEBUG
static const int N = 1 << 8;
static const int LOOPS = 2;
static const int QUERY_LOOPS = 100;
#define ASSERT(exp) assert(exp)
#else
static const int N = 1 << 12;
static const int LOOPS = 10;
static const int QUERY_LOOPS = 10000;
#define ASSERT(exp) if (!(exp)) return false
#endif

template<typename T, long long SIZE, T DEF_VAL, const T& Compare(const T&, const T&)>
class SegmentTree {
	vector<T> val;
public:
	SegmentTree() : val(SIZE * 2, DEF_VAL) { }
	void update(long long i, const T &value) {
		i += SIZE;
		val[i] = value;
		while (i > 1) i >>= 1, val[i] = Compare(val[i * 2], val[i * 2 + 1]);
	}
	T get(long long a, long long b, long long l = 0, long long r = SIZE, long long i = 1) {
		if (r <= a || b <= l) return DEF_VAL;
		if (a <= l && r <= b) return val[i];
		return Compare(get(a, b, l, (l + r) / 2, i * 2), get(a, b, (l + r) / 2, r, i * 2 + 1));
	}
	long long find_leftmost_index(long long a, long long b, const T &value, long long l = 0, long long r = SIZE, long long i = 1) {
		if (Compare(val[i], value) != val[i]) return -1;
		if (r <= a || b <= l) return -1;
		if (i >= SIZE) return i - SIZE;
		long long leftmost_index = find_leftmost_index(a, b, value, l, (l + r) / 2, i * 2);
		if (leftmost_index >= 0) return leftmost_index;
		return find_leftmost_index(a, b, value, (l + r) / 2, r, i * 2 + 1);
	}
	long long find_rightmost_index(long long a, long long b, const T &value, long long l = 0, long long r = SIZE, long long i = 1) {
		if (Compare(val[i], value) != val[i]) return -1;
		if (r <= a || b <= l) return -1;
		if (i >= SIZE) return i - SIZE;
		long long rightmost_index = find_rightmost_index(a, b, value, (l + r) / 2, r, i * 2 + 1);
		if (rightmost_index >= 0) return rightmost_index;
		return find_rightmost_index(a, b, value, l, (l + r) / 2, i * 2);
	}
};
typedef SegmentTree<long long, 1 << 18, 1LL << 60, min> MinSegTree;
typedef SegmentTree<long long, 1 << 18,         0, max> MaxSegTree;

bool test() {
	for (int t = 0; t < LOOPS; ++t) {
		vector<LL> v(N);
		MinSegTree st;
		for (LL i = 0; i < N; ++i) {
			v[i] = i + 1;
		}
		random_shuffle(v.begin(), v.end());
		for (int i = 0; i < N; ++i) {
			st.update(i, v[i]);
		}
		for (int t = 0; t < QUERY_LOOPS; ++t) {
			LL a = rand() % N, b = rand() % N;
			if (a >= b) swap(a, b);
			LL p = *min_element(v.begin() + a, v.begin() + b + 1);
			LL q = st.get(a, b + 1);
			ASSERT(p == q);
		}
	}

	for (int t = 0; t < LOOPS; ++t) {
		vector<LL> v(N);
		MinSegTree st;
		for (LL i = 0; i < N; ++i) {
			v[i] = rand() % N;
		}
		random_shuffle(v.begin(), v.end());
		for (int i = 0; i < N; ++i) {
			st.update(i, v[i]);
		}
		for (int t = 0; t < QUERY_LOOPS; ++t) {
			LL a = rand() % N, b = rand() % N;
			if (a >= b) swap(a, b);
			LL p = *min_element(v.begin() + a, v.begin() + b + 1);
			LL q = st.get(a, b + 1);
			ASSERT(p == q);

			LL left_index = st.find_leftmost_index(a, b + 1, q);
			LL right_index = st.find_rightmost_index(a, b + 1, q);
			ASSERT(v[left_index] == p);
			ASSERT(v[right_index] == p);
			if (left_index < right_index) {
				for (LL i = a; i < left_index; ++i) {
					ASSERT(v[i] != p);
				}
				for (LL i = right_index + 1; i <= b; ++i) {
					ASSERT(v[i] != p);
				}
			}
		}
	}

	for (int t = 0; t < LOOPS; ++t) {
		vector<LL> v(N);
		MaxSegTree st;
		for (LL i = 0; i < N; ++i) {
			v[i] = i + 1;
		}
		random_shuffle(v.begin(), v.end());
		for (int i = 0; i < N; ++i) {
			st.update(i, v[i]);
		}
		for (int t = 0; t < QUERY_LOOPS; ++t) {
			LL a = rand() % N, b = rand() % N;
			if (a >= b) swap(a, b);
			LL p = *max_element(v.begin() + a, v.begin() + b + 1);
			LL q = st.get(a, b + 1);
			ASSERT(p == q);
		}
	}

	for (int t = 0; t < LOOPS; ++t) {
		vector<LL> v(N);
		MaxSegTree st;
		for (LL i = 0; i < N; ++i) {
			v[i] = rand() % N;
		}
		random_shuffle(v.begin(), v.end());
		for (int i = 0; i < N; ++i) {
			st.update(i, v[i]);
		}
		for (int t = 0; t < QUERY_LOOPS; ++t) {
			LL a = rand() % N, b = rand() % N;
			if (a >= b) swap(a, b);
			LL p = *max_element(v.begin() + a, v.begin() + b + 1);
			LL q = st.get(a, b + 1);
			ASSERT(p == q);

			LL left_index = st.find_leftmost_index(a, b + 1, q);
			LL right_index = st.find_rightmost_index(a, b + 1, q);
			ASSERT(v[left_index] == p);
			ASSERT(v[right_index] == p);
			if (left_index < right_index) {
				for (LL i = a; i < left_index; ++i) {
					ASSERT(v[i] != p);
				}
				for (LL i = right_index + 1; i <= b; ++i) {
					ASSERT(v[i] != p);
				}
			}
		}
	}

	for (int t = 0; t < LOOPS; ++t) {
		vector<int> v(N);
		SegmentTree<int, N, 1 << 30, min> st;
		for (int i = 0; i < N; ++i) {
			v[i] = i + 1;
		}
		random_shuffle(v.begin(), v.end());
		for (int i = 0; i < N; ++i) {
			st.update(i, v[i]);
		}
		for (int t = 0; t < QUERY_LOOPS; ++t) {
			LL a = rand() % N, b = rand() % N;
			if (a >= b) swap(a, b);
			int p = *min_element(v.begin() + a, v.begin() + b + 1);
			int q = st.get(a, b + 1);
			ASSERT(p == q);
		}
	}

	for (int t = 0; t < LOOPS; ++t) {
		vector<int> v(N);
		SegmentTree<int, N, 0, max> st;
		for (int i = 0; i < N; ++i) {
			v[i] = i + 1;
		}
		random_shuffle(v.begin(), v.end());
		for (int i = 0; i < N; ++i) {
			st.update(i, v[i]);
		}
		for (int t = 0; t < QUERY_LOOPS; ++t) {
			LL a = rand() % N, b = rand() % N;
			if (a >= b) swap(a, b);
			int p = *max_element(v.begin() + a, v.begin() + b + 1);
			int q = st.get(a, b + 1);
			ASSERT(p == q);
		}
	}

	return true;
}

int main(int argc, char* argv[]) {
	cout << (test() ? "OK" : "FAILED") << endl;
}
