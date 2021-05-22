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
	int _log_size;
	int _root;
	vector<vector<int>> _edges;
	vector<int> _offset;
	vector<int> _count;
	vector<vector<int>> _levels;

	Tree(int size) : _root(0), _size(size), _edges(size) { }

	void build_edges_from_parents(const vector<int>& parents) {
		for (int i = 0; i < parents.size(); ++i) {
			_edges[parents[i]].emplace_back(i + 1);
		}
	}

	void build_order_table() {
		_offset = vector<int>(_size);
		_count = vector<int>(_size);
		_levels = vector<vector<int>>(_size);
		int order = 0;
		get_children_size(-1, _root, order, 0);
	}

	void get_children_size(int parent, int node, int& order, int level) {
		_levels[level].emplace_back(order);
		_offset[node] = order++;
		for (int next : _edges[node]) {
			if (next != parent) get_children_size(node, next, order, level + 1);
		}
		_count[node] = order - _offset[node];
	}

};

void solve(int N, std::vector<int> &P, int Q, std::vector<int> &U, std::vector<int> &D) {
	Tree tree(N);
	tree.build_edges_from_parents(P);
	tree.build_order_table();
	for (int i = 0; i < Q; i++) {
		int offset = tree._offset[U[i]];
		int count = tree._count[U[i]];
		vector<int>& lv = tree._levels[D[i]];
		cout << (lower_bound(lv.begin(), lv.end(), offset + count) - lower_bound(lv.begin(), lv.end(), offset)) << endl;
	}
}

int main() {
    int N, Q;
	std::cin >> N;
	std::vector<int> P(N-2+1);
	for (int i = 0; i < N-2+1; i++) {
		std::cin >> P[i];
		--P[i];
	}
	std::cin >> Q;
	std::vector<int> U(Q), D(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> U[i] >> D[i];
		--U[i];
	}
	solve(N, P, Q, U, D);
	return 0;
}
