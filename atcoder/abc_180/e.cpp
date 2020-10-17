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
typedef long double LD;
typedef pair<LL, LL> II;
typedef pair<LL, II> III;
typedef priority_queue<III, vector<III>, greater<>> Queue;
static const LL INF = 1LL << 60;

void solve(long long N, std::vector<long long> &X, std::vector<long long> &Y, std::vector<long long> &Z) {
	auto cf = [&](LL from, LL to) {
		return abs(X[to] - X[from]) + abs(Y[to] - Y[from]) + max(0LL, Z[to] - Z[from]);
	};
	--N;
	LL bm = 1LL << N;
	vector<vector<LL>> cost(N, vector<LL>(bm, INF));
	priority_queue<III, vector<III>, greater<>> q;
	for (LL i = 0; i < N; ++i) {
		cost[i][1 << i] = cf(0, i + 1);
		q.emplace(III(cost[i][1 << i], II(1 << i, i)));
	}
	while (!q.empty()) {
		III top = q.top();
		q.pop();
		LL ma = top.second.first;
		for (LL i = 0; i < N; ++i) {
			LL f = (1LL << i) | ma;
			if (f != ma) {
				LL c = top.first + cf(top.second.second + 1, i + 1);
				if (c < cost[i][f]) {
					cost[i][f] = c;
					q.emplace(III(c, II(f, i)));
				}
			}
		}
	}
	LL ans = INF;
	for (LL i = 0; i < N; ++i) {
		ans = min(ans, cost[i][bm - 1] + cf(i + 1, 0));
	}
	cout << ans << endl;
}

int main() {
    long long N;
	std::cin >> N;
	std::vector<long long> X(N);
	std::vector<long long> Y(N);
	std::vector<long long> Z(N);
	for (int i = 0; i < N; i++) {
		std::cin >> X[i]; // X[i]--;
		std::cin >> Y[i]; // Y[i]--;
		std::cin >> Z[i]; // Z[i]--;
	}
	solve(N, X, Y, Z);
	return 0;
}
