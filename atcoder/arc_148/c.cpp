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

vector<int> solve(int N, int Q, vector<int> P, vector<set<int>> v) {
	vector<int> ans(Q);
	vector<vector<int>> edges(N);
	for (int i = 1; i < N; ++i) {
		edges[P[i]].emplace_back(i);
	}
	for (int i = 0; i < Q; ++i) {
		int& c = ans[i];
		for (auto x : v[i]) {
			c += edges[x].size();
			if (v[i].find(P[x]) != v[i].end()) {
				--c;
			} else {
				++c;
			}
		}
	}
	return ans;
}

int main() {
	int64_t N, Q, M, x;
	cin >> N >> Q;
	std::vector<int> P(N, -1);
	for (int i = 1; i < N; i++) {
		cin >> P[i];
		--P[i];
	}
	vector<set<int>> v(Q);
	for (int i = 0; i < Q; ++i) {
		cin >> M;
		for (int j = 0; j < M; ++j) {
			cin >> x;
			--x;
			v[i].insert(x);
		}
	}
	vector<int> ans = solve(N, Q, P, v);
	for (size_t i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
