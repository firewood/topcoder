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

struct Tree {
	int64_t _size;
	vector<vector<int>> _edges;

	Tree(int64_t size) : _size(size), _edges(size) { }

	void add_edge(int from, int to) {
		_edges[from].emplace_back(to);
	}

	vector<int> topological_sort() {
		vector<int> result, count(_size);
		priority_queue<int, vector<int>, greater<>> q;
		for (auto edges : _edges) {
			for (auto e : edges) {
				count[e]++;
			}
		}
		for (int i = 0; i < _size; i++) {
			if (count[i] == 0) {
				q.push(i);
			}
		}
		while (!q.empty()) {
			int node = q.top();
			q.pop();
			result.push_back(node);
			for (auto e : _edges[node]) {
				if (--count[e] == 0) {
					q.push(e);
				}
			}
		}
		return result;
	}
};

bool solve(int H, int W, std::vector<std::vector<int>> A) {
	vector<II> v;
	for (int y = 0; y < H; ++y) {
		int mn = 1 << 30, mx = 0;
		for (int x = 0; x < W; ++x) {
			if (A[y][x] > 0) {
				mn = min(mn, A[y][x]);
				mx = max(mx, A[y][x]);
			}
		}
		if (mx > 0) {
			v.emplace_back(II(mn, mx));
		}
	}
	sort(v.begin(), v.end());
	for (size_t i = 1; i < v.size(); ++i) {
		if (v[i].first < v[i - 1].second) {
			return false;
		}
	}

	int tree_size = (H + 1) * W, last_index = W;
	Tree tree(tree_size);
	for (int y = 0; y < H; ++y) {
		map<int, vector<int>> m;
		for (int x = 0; x < W; ++x) {
			if (A[y][x] > 0) {
				m[A[y][x]].emplace_back(x);
			}
		}
		auto prev = m.begin();
		if (prev != m.end()) {
			auto it = prev;
			for (++it; it != m.end(); ++it) {
				for (auto from : prev->second) {
					tree.add_edge(from, last_index);
				}
				for (auto to : it->second) {
					tree.add_edge(last_index, to);
				}
				++last_index;
				prev = it;
			}
		}
	}
	return tree.topological_sort().size() == tree_size;
}

int main() {
	int H, W;
	std::cin >> H >> W;
	std::vector<std::vector<int>> A(H, std::vector<int>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			std::cin >> A[i][j];
		}
	}
	cout << (solve(H, W, A) ? "Yes" : "No") << endl;
	return 0;
}
