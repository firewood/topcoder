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
#include <atcoder/modint>

using namespace std;
const int64_t MOD = 998244353;
static const size_t TABLE_SIZE = 1000000;		// 1e6
using mint = atcoder::modint998244353;
static vector<mint> fact(TABLE_SIZE + 1, 0), inv(TABLE_SIZE + 1, 0);

static void build_fact_table() {
	fact[0] = 1;
	for (int i = 1; i <= TABLE_SIZE; ++i) {
		fact[i] = fact[i - 1] * i;
	}
	inv[TABLE_SIZE] = fact[TABLE_SIZE].inv();
	for (int i = TABLE_SIZE; i >= 1; --i) {
		inv[i - 1] = inv[i] * i;
	}
}

inline mint permutation(int n, int r) {
	return r > n ? 0 : fact[n] * inv[n - r];
}

inline mint combination(int n, int r) {
	return r > n ? 0 : (fact[n] * inv[r]) * inv[n - r];
}

inline mint nHr(int n, int r) {
	return combination(n + r - 1, r);
}

mint solve(int N, vector<int> L, vector<int> R) {
	mint ans = 0;
	vector<vector<int>> change(N + 2);
	for (int64_t i = 0; i < N; ++i) {
		change[L[i]].emplace_back(i);
		change[R[i] + 1].emplace_back(i);
		change[N - L[i] + 1].emplace_back(i);
		change[N - R[i]].emplace_back(i);
	}
	vector<int> aok(N), bok(N);
	int m[2][2] = { {N, 0}, {0, 0} };
	for (int64_t i = 1; i <= N - 1; ++i) {
		for (auto x : change[i]) {
			m[aok[x]][bok[x]]--;
			aok[x] = L[x] <= i && i <= R[x];
			bok[x] = L[x] <= (N - i) && (N - i) <= R[x];
			m[aok[x]][bok[x]]++;
		}
		if (m[0][0] == 0 && m[1][0] <= i && m[0][1] <= (N - i)) {
			ans += combination(m[1][1], i - m[1][0]);
		}
	}
	return ans;
}

int main() {
	build_fact_table();
	int N;
	cin >> N;
	vector<int> L(N), R(N);
	for (int64_t i = 0; i < N; ++i) {
		cin >> L[i] >> R[i];
	}
	auto ans = solve(N, L, R);
	cout << ans.val() << endl;
}
