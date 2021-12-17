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

struct Tree {
	int64_t _size;
	vector<vector<int64_t>> _edges;
	vector<int64_t> _vis;

	Tree(int64_t size) : _size(size), _edges(size), _vis(size) { }

	void build_edges(const vector<int64_t>& a, const vector<int64_t>& b) {
		for (int64_t i = 0; i < a.size(); ++i) {
			_edges[a[i]].emplace_back(b[i]);
			_edges[b[i]].emplace_back(a[i]);
		}
	}

	void dfs(int64_t n, vector<int64_t>& a, vector<int64_t> &s, int64_t sz, vector<int64_t> &ans) {
		_vis[n] += 1;
		int64_t pos = lower_bound(s.begin(), s.begin() + sz, a[n]) - s.begin();
		sz += pos == sz;
		int64_t prev_value = s[pos];
		s[pos] = a[n];
		ans[n] = sz;

		for (auto next : _edges[n]) {
			if (_vis[next] <= 0) {
				dfs(next, a, s, sz, ans);
			}
		}

		s[pos] = prev_value;
	}

/*
	void dfs(int64_t n, vector<int64_t>& a, set<int64_t> &s, vector<int64_t> &ans) {
		_vis[n] += 1;
		int64_t prev = -1;
		auto it = s.lower_bound(a[n]);
		if (it != s.end()) {
			prev = *it;
			s.erase(it);
		}
		s.insert(a[n]);

		ans[n] = s.size();

		for (auto next : _edges[n]) {
			if (_vis[next] <= 0) {
				dfs(next, a, s, ans);
			}
		}

		s.erase(a[n]);
		if (prev >= 0) {
			s.insert(prev);
		}
	}
*/
};

vector<int64_t> solve(int64_t N, std::vector<int64_t> a, std::vector<int64_t> u, std::vector<int64_t> v) {
	vector<int64_t> ans(N);
	Tree tree(N);
	tree.build_edges(u, v);
	vector<int64_t> s(N);
	tree.dfs(0, a, s, 0, ans);
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	std::vector<int64_t> u(N-1), v(N-1);
	for (int i = 0; i < N-1; i++) {
		std::cin >> u[i] >> v[i];
		--u[i];
		--v[i];
	}
	vector<int64_t> ans = solve(N, a, u, v);
	for (auto x : ans) {
		cout << x << endl;
	}
	return 0;
}
