#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
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

void solve(std::string s) {
	int len = (int)s.length();
	int bm = 1 << len;
	vector<int> dp(bm, len);
	int f = 0;
	for (int i = 0; i < len; ++i) {
		if (s[i] == 'o') {
			f |= 1 << i;
		}
	}
	dp[f] = 1;
	for (int b = 1; b < bm; ++b) {
		if (dp[b]) {
			for (int i = 0; i < len; ++i) {
				int a = ((f << i) | (f >> (len - i))) & (bm - 1);
				dp[a | b] = min(dp[a | b], dp[b] + 1);
			}
		}
	}
	cout << dp[bm - 1] << endl;
}

int main() {
	string s;
	cin >> s;
	solve(s);
	return 0;
}
