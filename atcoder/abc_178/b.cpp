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

void solve(long long a, long long b, long long c, long long d) {
	LL ans = max({ a * c, a * d, b * c, b * d });
	cout << ans << endl;
}

int main() {
	long long a, b, c, d;
	std::cin >> a >> b >> c >> d;
	solve(a, b, c, d);
	return 0;
}
