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

typedef long long LL;
typedef pair<LL, LL> II;

static const LL INF = 1LL << 60;

LL solve(long long N, std::vector<long long>& X, std::vector<long long>& C) {
	vector<LL> cl(N + 1, INF), cr(N + 1, -INF);
	for (LL i = 0; i < N; i++) {
		LL c = C[i];
		cl[c] = min(cl[c], X[i]);
		cr[c] = max(cr[c], X[i]);
	}
	vector<II> dp(2);
	for (LL i = 1; i <= N; ++i) {
		LL left = cl[i], right = cr[i];
		if (left < INF) {
			vector<II> next(2);
			next[0].first = INF;
			next[1].first = INF;
			for (LL t = 0; t < 2; ++t) {
				LL cost = dp[t].first;
				LL pos = dp[t].second;
				// right -> left
				LL c = cost + abs(right - pos) + (right - left);
				if (c < next[0].first) {
					next[0].first = c;
					next[0].second = left;
				}
				// left -> right
				c = cost + abs(left - pos) + (right - left);
				if (c < next[1].first) {
					next[1].first = c;
					next[1].second = right;
				}
			}
			dp = next;
		}
	}
	return min(dp[0].first + abs(dp[0].second), dp[1].first + abs(dp[1].second));
}

int main() {
	long long N;
	std::cin >> N;
	std::vector<long long> X(N), C(N);
	for (int i = 0; i < N; i++) {
		std::cin >> X[i] >> C[i];
	}
	cout << solve(N, X, C) << endl;
	return 0;
}
