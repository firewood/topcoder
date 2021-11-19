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
#include <random>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;

static const LL INF = 1LL << 60;

vector<LL> solve(LL N, LL M, LL X, vector<LL> h) {
	vector<LL> ans(N, -1);
	if (N == M) {
		ans.resize(N);
		iota(ans.begin(), ans.end(), 1);
		return ans;
	}

	vector<II> v;
	for (int i = 0; i < N; ++i) {
		v.emplace_back(II(h[i], i));
	}
	sort(v.rbegin(), v.rend());

	priority_queue<II, vector<II>, greater<>> q;
	for (int i = 0; i < M; ++i) {
		q.emplace(II(0, i + 1));
	}
	for (int i = 0; i < N; ++i) {
		II top = q.top();
		q.pop();
		top.first += v[i].first;
		q.emplace(top);
		ans[v[i].second] = top.second;
	}
	return ans;
}

int main() {
	LL t, N, M, X;
	cin >> t;
	for (LL q = 0; q < t; ++q) {
		cin >> N >> M >> X;
		std::vector<LL> h(N);
		for (int i = 0; i < N; i++) {
			cin >> h[i];
		}
		vector<LL> ans = solve(N, M, X, h);
		if (ans.empty()) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			for (int i = 0; i < N; ++i) {
				if (i) cout << " ";
				cout << ans[i];
			}
			cout << endl;
		}
	}
	return 0;
}
