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

typedef long long LL;
static const LL INF = 1LL << 60;

void solve(std::string S, std::string T) {
	LL ans = INF;
	for (LL i = 0; i + T.length() <= S.length(); ++i) {
		LL cnt = 0;
		for (int j = 0; j < T.length(); ++j) {
			cnt += S[i + j] != T[j];
		}
		ans = min(ans, cnt);
	}
	cout << ans << endl;
}

int main() {
	std::string S, T;
	std::cin >> S >> T;
	solve(S, T);
	return 0;
}
