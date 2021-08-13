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

class BIT {
	std::vector<int64_t> bit;
	int64_t size;
public:
	BIT() { }
	BIT(int64_t sz) { init(sz); }
	void init(int64_t sz) {
		bit = std::vector<int64_t>((size = sz) + 1);
	}
	int64_t sum(int64_t i) {
		int64_t s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	void add(int64_t i, int64_t x) {
		while (i <= size) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

struct Tree {
	int64_t _size;
	vector<vector<int>> _edges;
	vector<int> _counts;
	vector<int> _offset;

	Tree(int64_t size) : _size(size), _edges(size), _counts(size), _offset(size, -1) { }

	void build_edges(const vector<int>& a, const vector<int>& b) {
		for (int i = 0; i < a.size(); ++i) {
			_edges[a[i]].emplace_back(b[i]);
			_edges[b[i]].emplace_back(a[i]);
		}
	}

	void dfs(int node, int& count) {
		_offset[node] = count++;
		for (int next : _edges[node]) {
			if (_offset[next] < 0) {
				dfs(next, count);
			}
		}
		_counts[node] = count - _offset[node];
	}
};

vector<int64_t> solve(int64_t N, std::vector<int> a, std::vector<int> b, int64_t Q, std::vector<int> t, std::vector<int> e, std::vector<int> x) {
	Tree tree(N);
	tree.build_edges(a, b);
	int count = 0;
	tree.dfs(0, count);

	BIT bit(N + 2);
	for (int i = 0; i < Q; ++i) {
		int use = 0, avo = 0;
		if (t[i] == 1) {
			use = a[e[i]], avo = b[e[i]];
		} else {
			use = b[e[i]], avo = a[e[i]];
		}
		if (tree._offset[use] < tree._offset[avo]) {
			bit.add(1, x[i]);
			bit.add(1 + tree._offset[avo], -x[i]);
			bit.add(1 + tree._offset[avo] + tree._counts[avo], x[i]);
		} else {
			bit.add(1 + tree._offset[use], x[i]);
			bit.add(1 + tree._offset[use] + tree._counts[use], -x[i]);
		}
	}

	vector<int64_t> ans(N);
	for (int i = 0; i < N; ++i) {
		ans[i] = bit.sum(tree._offset[i] + 1);
	}
	return ans;
}

int main() {
	int64_t N, Q;
	std::cin >> N;
	std::vector<int> a(N-1), b(N-1);
	for (int i = 0; i < N-1; i++) {
		std::cin >> a[i] >> b[i];
		--a[i]; --b[i];
	}
	std::cin >> Q;
	std::vector<int> t(Q), e(Q), x(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> t[i] >> e[i] >> x[i];
		--e[i];
	}
	for (auto c : solve(N, a, b, Q, t, e, x)) {
		cout << c << endl;
	}
	return 0;
}
