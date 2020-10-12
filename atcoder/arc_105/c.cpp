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

LL solve(long long N, long long M, std::vector<long long>& w, std::vector<long long>& l, std::vector<long long>& v) {
	LL max_w = *max_element(w.begin(), w.end());
	LL min_allow = *min_element(v.begin(), v.end());
	if (max_w > min_allow) {
		return -1;
	}
	vector<II> vv;
	for (int i = 0; i < M; ++i) {
		vv.emplace_back(II(l[i], v[i]));
	}
	sort(vv.begin(), vv.end());
	map<LL, LL> m;
	m[0] = 0;
	LL mn = INF;
	for (LL i = M - 1; i >= 0; --i) {
		if (vv[i].second < mn) {
			mn = vv[i].second;
			m[mn] = vv[i].first;
		}
	}

	sort(w.rbegin(), w.rend());
	swap(w[1], w[N - 1]);
	vector<int> seq(N);
	iota(seq.begin(), seq.end(), 0);

	LL ans = INF;
	do {
		vector<vector<LL>> dist(N, vector<LL>(N));
		vector<LL> pos(N);
		for (LL i = 1; i < N; ++i) {
			LL tot_w = w[seq[i]];
			for (LL j = i - 1; j >= 0; --j) {
				tot_w += w[seq[j]];
				auto x = m.lower_bound(tot_w);
				if (x == m.end()) --x;
				if (tot_w <= x->first) --x;
				dist[i][j] = dist[j][i] = x->second;
			}
		}

		// Bellman-Ford
		vector<LL> costs(N);
		costs[0] = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				costs[j] = max(costs[j], costs[i] + dist[i][j]);
			}
		}
		ans = min(ans, costs[N - 1]);
	} while (next_permutation(seq.begin() + 1, seq.begin() + N - 1));
	return ans;
}

int main() {
	long long N, M;
	std::cin >> N >> M;
	std::vector<long long> w(N), l(M), v(M);
	for (int i = 0; i < N; i++) {
		std::cin >> w[i];
	}
	for (int i = 0; i < M; i++) {
		std::cin >> l[i] >> v[i];
	}
	cout << solve(N, M, w, l, v) << endl;
	return 0;
}
