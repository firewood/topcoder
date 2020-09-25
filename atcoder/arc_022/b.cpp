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

void solve(long long N, std::vector<long long> &A) {
	vector<LL> history(100001, -1);
	LL ans = 0, left = -1;
	for (LL i = 0; i < N; ++i) {
		left = max(left, history[A[i]]);
		ans = max(ans, i - left);
		history[A[i]] = i;
	}
	cout << ans << endl;
}

int main() {
    long long N;
	std::cin >> N;
	std::vector<long long> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i]; // A[i]--;
	}
	solve(N, A);
	return 0;
}
