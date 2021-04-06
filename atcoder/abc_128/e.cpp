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

void solve(int N, int Q, std::vector<int> &S, std::vector<int> &T, std::vector<int> &X, std::vector<int> &D) {
	set<pair<int, int>> s;
	for (int i = 0; i < Q; i++) {
		s.emplace(make_pair(D[i], i));
	}
	vector<int> seq(N);
	iota(seq.begin(), seq.end(), 0);
	sort(seq.begin(), seq.end(), [&](int lhs, int rhs) {
		return make_pair(X[lhs], S[lhs]) < make_pair(X[rhs], S[rhs]);
	});
	vector<int> ans(Q, -1);
	for (int t = 0; t < N; t++) {
		int i = seq[t];
		auto it = s.lower_bound(make_pair(S[i] - X[i], 0));
		while (it != s.end() && it->first < T[i] - X[i]) {
			ans[it->second] = X[i];
			it = s.erase(it);
		}
	}
	for (auto a : ans) {
		cout << a << endl;
	}
}

int main() {
	int N, Q;
	std::cin >> N >> Q;
	std::vector<int> S(N), T(N), X(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i] >> T[i] >> X[i];
	}
	std::vector<int> D(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> D[i];
	}
	solve(N, Q, S, T, X, D);
	return 0;
}
