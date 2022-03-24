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
	vector<int64_t> _cnt;
	string _goal;
	string _state;
	vector<int> _path;

	Tree(int64_t size) : _size(size), _edges(size), _vis(size), _cnt(size) { }

	void build_edges(const vector<int64_t>& a, const vector<int64_t>& b) {
		for (int64_t i = 0; i < a.size(); ++i) {
			_edges[a[i]].emplace_back(b[i]);
			_edges[b[i]].emplace_back(a[i]);
		}
	}

	void queue(int next) {
		if (_goal != _state) {
			_state[next] ^= 1;
			_path.emplace_back(next + 1);
		}
	}

	void dfs(int64_t n) {
		_vis[n] += 1;
		queue(n);
		for (auto next : _edges[n]) {
			if (_vis[next] <= 0) {
				dfs(next);
				queue(n);
				if (_goal[next] != _state[next]) {
					queue(next);
					queue(n);
				}
			}
		}
	}
};

vector<int> solve(int64_t N, int64_t M, std::vector<int64_t> u, std::vector<int64_t> v, std::string S) {
	Tree tree(N);
	tree._goal = S;
	tree._state = string(N, '0');
	tree.build_edges(u, v);
	tree.dfs(0);
	for (auto next : tree._edges[0]) {
		tree.queue(next);
		tree.queue(0);
		tree.queue(next);
		break;
	}
	return tree._path;
}

int main() {
	int64_t N, M;
	std::string S;
	std::cin >> N >> M;
	std::vector<int64_t> u(M), v(M);
	for (int i = 0; i < M; i++) {
		std::cin >> u[i] >> v[i];
		--u[i], --v[i];
	}
	std::cin >> S;
	vector<int> ans = solve(N, M, u, v, S);
	cout << ans.size() << endl;
	if (!ans.empty()) {
		for (size_t i = 0; i < ans.size(); ++i) {
			if (i) cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}
