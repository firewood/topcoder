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

void solve(long long N) {
	set<LL> ans;
	for (LL i = 1; i * i <= N; ++i) {
		if ((N % i) == 0) {
			ans.insert(i);
			ans.insert(N / i);
		}
	}
	for (auto x : ans) {
		cout << x << endl;
	}
}

int main() {
    long long N;
	std::cin >> N;
	solve(N);
	return 0;
}
