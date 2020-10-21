#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int lcs(const string& a, const string& b) {
	int dp[102][102] = {};
	for (int i = 0; i != a.length(); ++i) {
		for (int j = 0; j != b.length(); ++j) {
			if (a[i] == b[j]) {
				dp[i + 1][j + 1] = 1 + dp[i][j];
			} else {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}
	return dp[a.length()][b.length()];
}

void solve(int N, std::string S) {
	int m = 0;
	for (int i = 1; i < N; ++i) {
		m = max(m, lcs(S.substr(0, i), S.substr(i)));
	}
	int ans = N - m * 2;
	cout << ans << endl;
}

int main() {
    long long N;
	std::cin >> N;
	std::string S;
	std::cin >> S;
	solve(N, S);
	return 0;
}
