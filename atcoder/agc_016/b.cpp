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

void solve(long long N, std::vector<long long> &a) {
	sort(a.begin(), a.end());
	bool ans = false;
	if (a.back() == a.front()) {
		ans = a.front() == N - 1 || a.front() * 2 <= N;
	} else if (a.front() + 1 == a.back()) {
		int b = count(a.begin(), a.end(), a.front());
		int c = count(a.begin(), a.end(), a.back());
		ans = b < a.back() && (a.back() - b) * 2 <= c;
	}
	cout << (ans ? "Yes" : "No") << endl;
}

int main() {
    long long N;
	scanf("%lld", &N);
	std::vector<long long> a(N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &a[i]); // a[i]--;
	}
	solve(N, a);
	return 0;
}
