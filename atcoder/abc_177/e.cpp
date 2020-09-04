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

#ifdef _DEBUG
const LL MAX_N = 10000;
#else
const LL MAX_N = 1000000;
#endif

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

void solve(long long N, std::vector<long long> &A) {
	vector<vector<int>> p(MAX_N + 1);
	vector<int> f(MAX_N + 1);
	LL g = 0;
	for (int i = 2; i <= MAX_N; ++i) {
		if (p[i].empty()) {
			for (int j = i; j <= MAX_N; j += i) {
				p[j].emplace_back(i);
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (auto x : p[A[i]]) {
			f[x] += 1;
		}
		g = gcd(A[i], g);
	}
	string ans = "not coprime";
	if (*max_element(f.begin(), f.end()) <= 1) {
		ans = "pairwise coprime";
	} else if (g == 1) {
		ans = "setwise coprime";
	}
	cout << ans << endl;
}

int main() {
    long long N;
	scanf("%lld", &N);
	std::vector<long long> A(N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
	}
	solve(N, A);
	return 0;
}
