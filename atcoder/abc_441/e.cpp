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

typedef long double LD;
typedef pair<int64_t, int64_t> II;
typedef pair<int64_t, II> III;

static const int64_t INF = 1LL << 60;

template<typename T> struct BIT {
	int _size;
	atcoder::fenwick_tree<T> ft;
	BIT(int size) : _size(size), ft(size) { }
	void add(int pos, T value) { ft.add(pos, value); }
	T range_sum(int from, int to) { return ft.sum(from, to); }
	T sum(int pos) { return range_sum(0, pos); }
	int lower_bound(int64_t value) {
		int left = -1, right = _size;
		while (right - left > 1) {
			int mid = (left + right) / 2;
			if (sum(mid + 1) >= value) { right = mid; } else { left = mid; }
		}
		return right;
	}
	void set_all(void) { for (int i = 0; i < _size; ++i) { insert(i); } }
	int size(void) { return int(sum(_size)); }
	void insert(int x) { add(x, 1); }
	void erase(int x) { add(x, -1); }
	int nth_smallest(int rank) { return (rank >= 1 && rank <= size()) ? lower_bound(rank) : -1; }
	int nth_biggest(int rank) { return nth_smallest(_size + 1 - rank); }
};

int64_t solve(int64_t N, std::string S) {
	int64_t ans = 0, cnt = 0;
	int64_t ofs = 500000;
	BIT<int64_t> bit(1000002);
	for (int i = 0; i < N; ++i) {
		bit.add(ofs + cnt, 1);
		if (S[i] == 'A') {
			++cnt;
		}
		if (S[i] == 'B') {
			--cnt;
		}
		ans += bit.sum(ofs + cnt);
	}
	return ans;
}

int main() {
	{
		int64_t N;
		std::string S;
		std::cin >> N >> S;
		cout << solve(N, S) << endl;
	}
	return 0;
}
