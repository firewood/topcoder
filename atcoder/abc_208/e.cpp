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

// 桁DP
int64_t solve1(int64_t N, int64_t K) {
	map<int64_t, int64_t> eq;		// Nと等しい
	map<int64_t, int64_t> le;		// Nより小さい
	string s = to_string(N);
	for (int64_t i = 0; i < s.length(); i++) {
		map<int64_t, int64_t> neq, nle;
		int64_t d = s[i] - '0';
		if (i == 0) {
			for (int64_t j = 1; j < d; ++j) {
				nle[j] += 1;
			}
			neq[d] += 1;
		} else {
			for (int64_t j = 0; j <= 9; ++j) {
				if (j <= d) {
					for (auto kv : eq) {
						int64_t x = min(K + 1, kv.first * j);
						if (j < d) {
							nle[x] += kv.second;
						} else {
							neq[x] += kv.second;
						}
					}
				}
				for (auto kv : le) {
					int64_t x = min(K + 1, kv.first * j);
					nle[x] += kv.second;
				}
				if (j > 0) {
					nle[j] += 1;
				}
			}
		}
		eq = neq, le = nle;
	}
	int64_t ans = 0;
	for (auto kv : eq) {
		if (kv.first <= K) {
			ans += kv.second;
		}
	}
	for (auto kv : le) {
		if (kv.first <= K) {
			ans += kv.second;
		}
	}
	return ans;
}

// 桁DP
int64_t solve(int64_t N, int64_t K) {
	int64_t ans = 0;
	string s = to_string(N);
	int64_t prod = 1;
	map<int64_t, int64_t> dp;
	for (int64_t i = 0; i < s.length(); i++) {
		map<int64_t, int64_t> next;
		int64_t d = s[i] - '0';
		for (int64_t j = 0; j <= 9; ++j) {
			for (auto kv : dp) {
				next[min(kv.first * j, K + 1)] += kv.second;
			}
			if (i > 0 && j > 0) {
				next[min(j, K + 1)] += 1;
			}
		}
		for (int64_t j = 0; j < d; ++j) {
			if (i > 0 || j > 0) {
				next[min(prod * j, K + 1)] += 1;
			}
		}
		prod = min(prod * d, K + 1);
		dp = next;
	}
	for (const auto& kv : dp) {
		if (kv.first <= K) {
			ans += kv.second;
		}
	}
	ans += prod <= K;
	return ans;
}

int main() {
	int64_t N, K;
	std::cin >> N >> K;
	cout << solve(N, K) << endl;
	return 0;
}
