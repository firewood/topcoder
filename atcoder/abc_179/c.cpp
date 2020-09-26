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

void solve(long long N) {
	LL ans = 0;
	for (LL a = 1; a < N; ++a) {
		for (LL b = 1; b < N; ++b) {
			if (a * b >= N) break;
			++ans;
		}
	}
	cout << ans << endl;
}

int main() {
	long long N;
	std::cin >> N;
	solve(N);
	return 0;
}
