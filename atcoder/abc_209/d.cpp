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
	vector<int> _depths;

	Tree(int size) : _root(0), _size(size), _edges(size) { }

	void build_depth() {
		_depths = vector<int>(_size);
		get_depth(-1, _root, 0);
	}

	void get_depth(int parent, int node, int depth) {
		_depths[node] = depth;
		for (int next : _edges[node]) {
			if (next != parent) get_depth(node, next, depth + 1);
		}
	}
};

int main() {
	int64_t N, Q, a, b, c, d;
	cin >> N >> Q;
	Tree tree(N);
	for (int i = 1; i < N; ++i) {
		cin >> a >> b;
		--a, --b;
		tree._edges[a].emplace_back(b);
		tree._edges[b].emplace_back(a);
	}
	tree.build_depth();
	for (int i = 0; i < Q; ++i) {
		cin >> c >> d;
		--c, --d;
		bool is_town = (tree._depths[c] + tree._depths[d]) % 2 == 0;
		cout << (is_town ? "Town" : "Road") << endl;
	}
	return 0;
}
