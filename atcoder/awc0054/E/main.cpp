#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <atcoder/fenwicktree>

using namespace std;

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

std::vector<int64_t> solve(int64_t N, int64_t M, std::vector<int64_t> S) {
	std::vector<int64_t> ans(M);
	BIT<int64_t> bit(N + 1);
	bit.set_all();
	bit.erase(0);
	for (int64_t i = 0; i < M; ++i) {
		ans[i] = bit.sum(S[i] + 1);
		bit.erase(S[i]);
	}
	return ans;
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int64_t> S(M);
	for (int64_t i = 0; i < M; ++i) {
		std::cin >> S[i];
	}
	auto answers = solve(N, M, std::move(S));
	for (const auto ans : answers) {
		cout << ans << endl;
	}
}
