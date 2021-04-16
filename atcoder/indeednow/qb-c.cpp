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
	int _size;
	int _root;
	vector<vector<int>> _edges;

	Tree(int size) : _root(0), _size(size), _edges(size) { }

	void build_edges(const vector<int>& a, const vector<int>& b) {
		for (int i = 0; i < a.size(); ++i) {
			_edges[a[i]].emplace_back(b[i]);
			_edges[b[i]].emplace_back(a[i]);
		}
	}

	vector<int> solve() {
		vector<int> order;
		vector<int> visited(_size);
		priority_queue<int, vector<int>, greater<>> q;
		q.emplace(0);
		visited[0] = 1;
		while (!q.empty()) {
			int node = q.top();
			q.pop();
			order.emplace_back(node);
			for (auto next : _edges[node]) {
				if (!visited[next]) {
					visited[next] = 1;
					q.emplace(next);
				}
			}
		}
		return order;
	}
};

void solve(int N, std::vector<int> &a, std::vector<int> &b) {
	Tree tree(N);
	tree.build_edges(a, b);
	vector<int> ans = tree.solve();
	for (int i = 0; i < N; ++i) {
		if (i) cout << " ";
		cout << ans[i] + 1;
	}
	cout << endl;
}

int main() {
    int N;
	std::cin >> N;
	std::vector<int> a(N-1), b(N-1);
	for (int i = 0; i < N-1; i++) {
		std::cin >> a[i] >> b[i];
		--a[i], --b[i];
	}
	solve(N, a, b);
	return 0;
}
