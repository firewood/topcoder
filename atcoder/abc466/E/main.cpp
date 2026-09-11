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

using namespace std;

int64_t solve(int64_t N, int64_t K, std::vector<int64_t> A, std::vector<int64_t> B) {
	vector<int64_t> vals[2] = { A, B };
	vector<int64_t> dp(K * 2 + 1, 0);
	for (int i = 0; i < N; ++i) {
		vector<int64_t> next = dp;
		for (int j = 0; j <= 2 * K; ++j) {
			next[j] = max(next[j], dp[j] + vals[j % 2][i]);
			if (j < 2 * K) {
				next[j + 1] = max(next[j + 1], dp[j] + vals[(j + 1) % 2][i]);
			}
		}
		dp = next;
	}
	return *max_element(dp.begin(), dp.end());
}

int main() {
	int64_t N, K;
	std::cin >> N >> K;
	std::vector<int64_t> A(N), B(N);
	for (int64_t i = 0 ; i < N ; i++) {
		std::cin >> A[i] >> B[i];
	}
    auto ans = solve(N, K, std::move(A), std::move(B));
    cout << ans << endl;
}
