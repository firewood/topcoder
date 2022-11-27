#include <algorithm>
#include <cctype>
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

typedef pair<int, int> II;
typedef pair<II, vector<int>> IIV;

static const int INF = 1 << 30;

int solve(int N, std::vector<int> H, std::vector<int> M, std::vector<int> S, std::vector<int> E) {
	int ans = 0;
	vector<II> v;
	for (int i = 0; i < N; ++i) {
		v.emplace_back(II(S[i], i));
	}
	sort(v.begin(), v.end());
	v.emplace_back(II(INF, -1));
	priority_queue<IIV, vector<IIV>, greater<>> q;
	vector<vector<int>> dp(N);
	vector<int> mxs(N);
	for (int vi = 0; vi <= N; ++vi) {
		int tm = v[vi].first, i = v[vi].second;
		while (!q.empty() && q.top().first.first <= tm) {
			int type = q.top().first.second, mx = 0;
			vector<int>& w = dp[type];
			const vector<int>& x = q.top().second;
			w.resize(max(w.size(), x.size()));
			for (size_t k = 0; k < x.size(); ++k) {
				w[k] = max(w[k], x[k]);
				mx = max(mx, w[k]);
			}
			mxs[type] = max(mxs[type], mx);
			q.pop();
		}
		if (i >= 0) {
			vector<int> w = dp[M[i]];
			w.emplace_back(0);
			for (size_t k = w.size() - 1; k >= 1; --k) {
				w[k] = max(w[k], w[k - 1] + H[k]);
			}
			int mx = 0;
			for (int j = 0; j < N; ++j) {
				if (M[i] != j) {
					mx = max(mx, mxs[j]);
				}
			}
			w[0] = max(w[0], mx + H[0]);
			q.emplace(IIV(II(E[i], M[i]), w));
		}
	}
	return *max_element(mxs.begin(), mxs.end());
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> H(N);
	for (int i = 0; i < N; i++) {
		std::cin >> H[i];
	}
	std::vector<int> M(N), S(N), E(N);
	for (int i = 0; i < N; i++) {
		std::cin >> M[i] >> S[i] >> E[i];
		--M[i];
	}
	cout << solve(N, H, M, S, E) << endl;
	return 0;
}
