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
#include <atcoder/math>

using namespace std;

vector<int64_t> solve(int64_t N, int64_t K, const vector<int64_t> &P) {
	vector<int64_t> ans(N), parent(N, -1), offset(N, -1);
	vector<vector<int64_t>> link(N);
	for (int i = 0; i < N; ++i) {
		int64_t node = i;
		while (parent[node] < 0) {
			parent[node] = i;
			offset[node] = link[i].size();
			link[i].emplace_back(node);
			node = P[node];
		}
	}

	for (int i = 0; i < N; ++i) {
		vector<int64_t>& v = link[parent[i]];
		ans[i] = v[(offset[i] + atcoder::pow_mod(2, K, v.size())) % v.size()];
	}

	return ans;
}

int main() {
	int64_t N, K;
	cin >> N >> K;
	vector<int64_t> P(N);
	for (int i = 0; i < N; i++) {
		cin >> P[i];
		--P[i];
	}

	vector<int64_t> ans = solve(N, K, P);
	for (size_t i = 0; i < ans.size(); ++i) {
		if (i) cout << " ";
		cout << ans[i] + 1;
	}
	cout << endl;
	return 0;
}
