#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;
typedef long long LL;

template<typename T, size_t SIZE, T DEF_VAL, const T& Compare(const T&, const T&)>
class SegmentTree {
	vector<T> val;
public:
	SegmentTree() : val(SIZE * 2, DEF_VAL) { }
	T get(int a, int b, int l = 0, int r = SIZE, size_t i = 1) {
		if (r <= a || b <= l) return DEF_VAL;
		if (a <= l && r <= b) return val[i];
		return Compare(get(a, b, l, (l + r) / 2, i * 2), get(a, b, (l + r) / 2, r, i * 2 + 1));
	}
	void update(size_t i, T value) {
		i += SIZE;
		val[i] = Compare(val[i], value);
		while (i > 1) i >>= 1, val[i] = Compare(val[i * 2], val[i * 2 + 1]);
	}
};
typedef SegmentTree<long long, 1 << 18, 1LL << 62, min> MinLLSegTree;
typedef SegmentTree<long long, 1 << 18,         0, max> MaxLLSegTree;

int main(int argc, char* argv[]) {
	const int N = 1 << 8;
	{
		vector<LL> v(N, 1LL << 62);
		MinLLSegTree st;
		for (int i = 0; i < N; ++i) {
			v[i] = i + 1;
		}
		random_shuffle(v.begin(), v.end());
		for (int i = 0; i < N; ++i) {
			st.update(i, v[i]);
		}
		for (int t = 0; t < 100000; ++t) {
			int a = rand() % N, b = rand() % N;
			if (a >= b) swap(a, b);
			LL p = *min_element(v.begin() + a, v.begin() + b + 1);
			LL q = st.get(a, b + 1);
			assert(p == q);
		}
	}
	{
		vector<LL> v(N, 0);
		MaxLLSegTree st;
		for (int i = 0; i < N; ++i) {
			v[i] = i + 1;
		}
		random_shuffle(v.begin(), v.end());
		for (int i = 0; i < N; ++i) {
			st.update(i, v[i]);
		}
		for (int t = 0; t < 100000; ++t) {
			int a = rand() % N, b = rand() % N;
			if (a >= b) swap(a, b);
			LL p = *max_element(v.begin() + a, v.begin() + b + 1);
			LL q = st.get(a, b + 1);
			assert(p == q);
		}
	}
	{
		vector<int> v(N, 1 << 30);
		SegmentTree<int, N, 1 << 30, min> st;
		for (int i = 0; i < N; ++i) {
			v[i] = i + 1;
		}
		random_shuffle(v.begin(), v.end());
		for (int i = 0; i < N; ++i) {
			st.update(i, v[i]);
		}
		for (int t = 0; t < 100000; ++t) {
			int a = rand() % N, b = rand() % N;
			if (a >= b) swap(a, b);
			int p = *min_element(v.begin() + a, v.begin() + b + 1);
			int q = st.get(a, b + 1);
			assert(p == q);
		}
	}
	{
		vector<int> v(N, 0);
		SegmentTree<int, N, 0, max> st;
		for (int i = 0; i < N; ++i) {
			v[i] = i + 1;
		}
		random_shuffle(v.begin(), v.end());
		for (int i = 0; i < N; ++i) {
			st.update(i, v[i]);
		}
		for (int t = 0; t < 100000; ++t) {
			int a = rand() % N, b = rand() % N;
			if (a >= b) swap(a, b);
			int p = *max_element(v.begin() + a, v.begin() + b + 1);
			int q = st.get(a, b + 1);
			assert(p == q);
		}
	}
	cout << "OK" << endl;
}
