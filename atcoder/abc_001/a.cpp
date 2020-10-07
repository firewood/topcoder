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

void solve(std::vector<long long> &H) {
	LL ans = H[0] - H[1];
	cout << ans << endl;
}

int main() {
    std::vector<long long> H(2);
	for (int i = 0; i < 2; i++) {
		std::cin >> H[i];
	}
	solve(H);
	return 0;
}
