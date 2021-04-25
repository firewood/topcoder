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

struct Tree {
	int _size;
	vector<vector<int>> _edges;
	vector<int> _vis1;
	vector<int> _vis2;
	vector<int> _color;
	vector<int> _shifts;
	vector<int> _nodes;

	Tree(int size) : _size(size), _edges(size), _vis1(size), _vis2(size), _color(size), _shifts(size){ }

	void build_edges(const vector<int>& a, const vector<int>& b) {
		for (int i = 0; i < a.size(); ++i) {
			_edges[a[i]].emplace_back(b[i]);
			_edges[b[i]].emplace_back(a[i]);
		}
	}

	void dfs1(int n) {
		_vis1[n] = 1;
		for (auto next : _edges[n]) {
			if (_vis1[next] <= 0) {
				dfs1(next);
			}
		}
		_nodes.emplace_back(n);
	}

	bool dfs2(int n) {
		_vis2[n] = 1;
		for (auto next : _edges[n]) {
			if (_vis2[next] <= 0) {
				_color[next] = (_color[n] + _shifts[next]) % 3;
				if (!dfs2(next)) {
					return false;
				}
			}
			if (_color[n] == _color[next]) {
				return false;
			}
		}
		return true;
	}

	LL solve() {
		LL ans = 1;
		for (int node = 0; node < _size; ++node) {
			if (_vis1[node]) {
				continue;
			}
			_nodes.clear();
			dfs1(node);
			_nodes.pop_back();
			int sum = 0, bm = 1 << _nodes.size();
			for (int b = 0; b < bm; ++b) {
				for (int i = 0; i < _nodes.size(); ++i) {
					_shifts[_nodes[i]] = ((1 << i) & b) ? 1 : 2;
				}
				_color[node] = 0;
				_vis2 = vector<int>(_size);
				if (dfs2(node)) {
					++sum;
				}
			}
			ans *= sum * 3;
		}
		return ans;
	}
};

LL solve(int N, int M, std::vector<int> &A, std::vector<int> &B) {
	Tree tree(N);
	tree.build_edges(A, B);
	return tree.solve();
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> A(M), B(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i] >> B[i];
		--A[i], --B[i];
	}
	cout << solve(N, M, A, B) << endl;
	return 0;
}
