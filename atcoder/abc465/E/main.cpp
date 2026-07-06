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
using mint = atcoder::modint998244353;

#ifdef _MSC_VER
#define popcount __popcnt64
#else
#define popcount __builtin_popcountll
#endif

mint solve(string N) {
	mint ans = 0;
	int64_t len = N.length();
	// 桁DP
	// 桁, 未満フラグ, mod 3, 使った数字の種類
	auto dp = vector(len + 1, vector(2, vector(3, vector(1024, mint(0)))));
	dp[0][0][0][0] = 1;
	for (int64_t i = 0; i < len; ++i) {
		int64_t max_d = N[i] - '0';
		for (int64_t j = 0; j < 2; ++j) {
			for (int64_t k = 0; k < 3; ++k) {
				for (int64_t m = 0; m < 1024; ++m) {
					for (int64_t d = 0; d <= (j ? 9 : max_d); ++d) {
						// leading zero ではない == 数字が1以上か、すでに1以上の数値が使われている
						int next_m = m | (d > 0 || m > 0) * (1 << d);
						dp[i + 1][j || (d < max_d)][(k + d) % 3][next_m] += dp[i][j][k][m];
					}
				}
			}
		}
	}

	// 3条件のうち、条件を1つだけ満たすものだけ抽出
	for (int64_t j = 0; j < 2; ++j) {
		for (int64_t m = 2; m < 1024; ++m) {
			bool use_three = (m & 8) != 0;
			bool use_three_digits = popcount(m) == 3;
			if (!use_three && !use_three_digits) {
				ans += dp[len][j][0][m];
			} else if (use_three != use_three_digits) {
				ans += dp[len][j][1][m];
				ans += dp[len][j][2][m];
			}
		}
	}
	
	return ans;
}

int main() {
	string N;
	cin >> N;
	auto ans = solve(N);
	cout << ans.val() << endl;
}
