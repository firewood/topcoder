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

typedef long double LD;
typedef pair<int64_t, int64_t> II;

void solve(int64_t N, std::vector<int64_t> A) {
	{
		auto possible = [&](LD t) -> bool {
			LD sum = 0;
			vector<LD> dp(2, 0);
			for (int i = 0; i < N; ++i) {
				dp = { dp[1], max(dp[0], dp[1]) + A[i] - t };
			}
			return dp[0] >= 0 || dp[1] >= 0;
		};
		LD left = 0, right = 1e9 + 1;
		for (int i = 0; i < 100; ++i) {
			LD mid = (left + right) / 2;
			if (!possible(mid)) {
				right = mid;
			} else {
				left = mid;
			}
		}
		cout << left << endl;
	}
	{
		auto possible = [&](int64_t t) -> bool {
			int64_t sum = 0;
			vector<int64_t> dp(2, 0);
			for (int i = 0; i < N; ++i) {
				dp = { dp[1], max(dp[0], dp[1]) + (A[i] >= t ? 1 : -1) };
			}
			return dp[0] > 0 || dp[1] > 0;
		};
		int64_t left = 0, right = 1e9 + 1;
		while (right - left > 1) {
			int64_t mid = (left + right) / 2;
			if (!possible(mid)) {
				right = mid;
			} else {
				left = mid;
			}
		}
		cout << left << endl;
	}
}

int main() {
	cout.precision(20);
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	solve(N, A);
	return 0;
}
