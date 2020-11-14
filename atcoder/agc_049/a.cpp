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
#include <bitset>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL, LL> II;
typedef pair<LL, II> III;
typedef priority_queue<III, vector<III>, greater<>> Queue;
static const int INF = 1LL << 29;

static const int COMBSZ = 256;
LD C[COMBSZ][COMBSZ] = { 1 };
LD fact[COMBSZ] = {};

void solve(long long N, std::vector<std::string>& S) {
	for (int i = 1; i < COMBSZ; ++i) {
		C[i][0] = C[i - 1][0] / 1;
		for (int j = 1; j <= i; ++j) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) / 1;
		}
	}
	fact[0] = 1;
	for (int i = 1; i < COMBSZ; ++i) {
		fact[i] = fact[i - 1] * i;
	}

	vector<vector<int>> dist(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			dist[i][j] = S[i][j] == '0' ? INF : 1;
		}
	}
	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	LD bp = 1 / fact[N];
	LD ans = 1;
	for (int i = 0; i < N; ++i) {
		int r = N - 1;
		for (int j = 0; j < N; ++j) {
			if (i != j && dist[j][i] < INF) {
				--r;
			}
		}
		for (int j = 1; j < N; ++j) {
			LD p = r >= j ? C[r][j] : 0;
			p *= (bp * fact[j] * fact[N - j - 1]);
			ans += p;
		}
	}
	cout << ans << endl;
}

int main() {
	cout.precision(20);
	long long N;
	std::cin >> N;
	std::vector<std::string> S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}
	solve(N, S);
	return 0;
}
