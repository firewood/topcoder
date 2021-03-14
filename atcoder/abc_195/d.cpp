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

typedef long long LL;
typedef pair<LL, LL> II;

static const LL INF = 1LL << 60;

LL solve(vector<LL> W, vector<LL> V, vector<LL> X) {
	LL ans = 0;
	LL N = W.size();
	LL sz = X.size();
	vector<int> used(sz);
	if (X.empty()) return 0;
	sort(X.begin(), X.end());
	vector<II> v;
	for (int i = 0; i < N; i++) {
		v.emplace_back(II(-V[i], W[i]));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		LL value = -v[i].first;
		LL weight = v[i].second;
		int pos = lower_bound(X.begin(), X.end(), weight) - X.begin();
		for (int j = pos; j < sz; ++j) {
			if (!used[j]) {
				used[j] = 1;
				ans += value;
				break;
			}
		}
	}
	return ans;
}

int main() {
	LL N, M, Q, L, R;
	cin >> N >> M >> Q;
	std::vector<long long> W(N), V(N), X(M);
	for (int i = 0; i < N; i++) {
		std::cin >> W[i] >> V[i];
	}
	for (int i = 0; i < M; i++) {
		std::cin >> X[i];
	}
	for (int q = 0; q < Q; ++q) {
		cin >> L >> R;
		--L, --R;
		vector<LL> x;
		for (int i = 0; i < L; ++i) {
			x.emplace_back(X[i]);
		}
		for (int i = R + 1; i < M; ++i) {
			x.emplace_back(X[i]);
		}
		cout << solve(W, V, x) << endl;
	}
	return 0;
}
