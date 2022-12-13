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

void dfs(vector<int>& ans, vector<II>& q) {
	if (q.empty()) {
		return;
	}
	int node = q.back().second, cnt = q.back().first;
	q.pop_back();
	--cnt;
	ans.emplace_back(node);
	while (cnt >= 1) {
		dfs(ans, q);
		--cnt;
		ans.emplace_back(node);
	}
}

vector<int> solve(int N, const vector<int>& c) {
	vector<int> ans, cnt(N + 1);
	for (int i = 0; i < N; ++i) {
		cnt[c[i]] += 1;
	}
	vector<II> v;
	for (int i = 1; i <= N; ++i) {
		if (cnt[i]) {
			v.emplace_back(II(cnt[i], i));
		}
	}
	sort(v.begin(), v.end());
	dfs(ans, v);
	while (!v.empty()) {
		ans.emplace_back(v.back().second);
		v.pop_back();
	}
	return ans;
}

int main() {
	int T, N;
	cin >> T;
	for (int tt = 0; tt < T; ++tt) {
		cin >> N;
		vector<int> c(N);
		for (int i = 0; i < N; ++i) {
			cin >> c[i];
		}
		vector<int> ans = solve(N, c);
		for (size_t i = 0; i < ans.size(); ++i) {
			if (i) cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}
