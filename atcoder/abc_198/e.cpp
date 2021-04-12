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
#include <bitset>

using namespace std;

struct Tree {
	int _size;
	vector<vector<int>> _edges;
	vector<int> _vis;
	vector<int> _ok;
	vector<int> _color_count;

	Tree(int size) : _size(size), _edges(size), _vis(size), _ok(size), _color_count(100000) { }

	void build_edges(const vector<int>& a, const vector<int>& b) {
		for (int i = 0; i < a.size(); ++i) {
			_edges[a[i]].emplace_back(b[i]);
			_edges[b[i]].emplace_back(a[i]);
		}
	}

	void dfs(int n, const vector<int> &color) {
		_vis[n] += 1;
		if (_color_count[color[n]] == 0) {
			_ok[n] = 1;
		}
		_color_count[color[n]] += 1;
		for (auto nx : _edges[n]) {
			if (_vis[nx] <= 0) {
				dfs(nx, color);
			}
		}
		_color_count[color[n]] -= 1;
	}
};

void solve(int N, std::vector<int> &C, std::vector<int> &A, std::vector<int> &B) {
	Tree tree(N);
	tree.build_edges(A, B);
	tree.dfs(0, C);
	for (int i = 0; i < N; i++) {
		if (tree._ok[i]) {
			cout << i + 1 << endl;
		}
	}
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> C(N);
	for (int i = 0; i < N; i++) {
		std::cin >> C[i];
		--C[i];
	}
	std::vector<int> A(N-1), B(N-1);
	for (int i = 0; i < N-1; i++) {
		std::cin >> A[i] >> B[i];
		--A[i], --B[i];
	}
	solve(N, C, A, B);
	return 0;
}
