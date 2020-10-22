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

typedef long long LL;

LL solve(long long X, long long Y, long long A, long long B) {
	LL ans = 0;
	for (LL x = X, c = 0; x < Y; x *= A, ++c) {
		LL cc = c + (Y - x - 1) / B;
		ans = max(ans, cc);
		if (x * A <= x) break;		// overflow
	}
	return ans;
}

int main() {
    long long X;
	std::cin >> X;
	long long Y;
	std::cin >> Y;
	long long A;
	std::cin >> A;
	long long B;
	std::cin >> B;
	LL ans = solve(X, Y, A, B);
	cout << ans << endl;
	return 0;
}
