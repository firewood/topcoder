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
	size_t _size;
	vector<vector<int>> _edges;
	vector<int> _vis;

	Tree(size_t size) : _size(size), _edges(size), _vis(size) { }

	void build_edges(const vector<int>& a, const vector<int>& b) {
		for (size_t i = 0; i < a.size(); ++i) {
			_edges[a[i]].emplace_back(b[i]);
			_edges[b[i]].emplace_back(a[i]);
		}
	}

	bool dfs(int n, int start) {
		_vis[n] += 1;
		if (n == start) {
			cout << (n + 1);
			return true;
		}
		for (auto next : _edges[n]) {
			if (_vis[next] <= 0) {
				if (dfs(next, start)) {
					cout << " " << (n + 1);
					return true;
				}
			}
		}
		return false;
	}
};

void solve(int N, int X, int Y, std::vector<int> U, std::vector<int> V) {
	Tree tree(N);
	tree.build_edges(U, V);
	tree.dfs(Y, X);
	cout << endl;
}

int main() {
	int N, X, Y;
	std::cin >> N >> X >> Y;
	--X, --Y;
	std::vector<int> U(N - 1), V(N - 1);
	for (int i = 0; i < N - 1; i++) {
		std::cin >> U[i] >> V[i];
		--U[i], --V[i];
	}
	solve(N, X, Y, U, V);
	return 0;
}
