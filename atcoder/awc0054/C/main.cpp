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

int64_t solve(int64_t N, int64_t M, std::vector<int64_t> S, std::vector<int64_t> L, std::vector<int64_t> R, std::vector<int64_t> W) {
	int64_t ans = 0;
	atcoder::fenwick_tree<int64_t> bit(N + 1);
	for (int64_t i = 0; i < M; ++i) {
		bit.add(L[i], W[i]);
		bit.add(R[i], -W[i]);
	}
	for (int64_t i = 0; i < N; ++i) {
		ans += bit.sum(0, i + 1) > S[i];
	}
	return ans;
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int64_t> S(N);
	for (int64_t i = 0; i < N; ++i) {
		std::cin >> S[i];
	}
	std::vector<int64_t> L(M), R(M), W(M);
	for (int64_t i = 0; i < M; ++i) {
		std::cin >> L[i] >> R[i] >> W[i];
		--L[i];
	}
	auto ans = solve(N, M, std::move(S), std::move(L), std::move(R), std::move(W));
	cout << ans << endl;
}
