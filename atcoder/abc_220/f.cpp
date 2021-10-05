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

// 全方位木DP
struct Tree {
	struct NodeValue {
		int64_t count;
		int64_t cost;
		NodeValue(int64_t count_, int64_t cost_) : count(count_), cost(cost_) { }
		NodeValue() : NodeValue(1, 0) { }
		NodeValue op(const NodeValue& a) {
			NodeValue value;
			value.count = count + a.count;
			value.cost = cost + a.cost + a.count;
			return value;
		}
		NodeValue add(const NodeValue& a) {
			NodeValue value;
			value.count = count + a.count;
			value.cost = cost + a.cost;
			return value;
		}
		static NodeValue emptyValue() {
			return { 0, 0 };
		}
	};

	int64_t _size;
	vector<vector<int>> _edges;
	vector<NodeValue> _value;

	Tree(int64_t size) : _size(size), _edges(size), _value(size) { }

	void build_edges(const vector<int>& a, const vector<int>& b) {
		for (int64_t i = 0; i != a.size(); ++i) {
			_edges[a[i]].emplace_back(b[i]);
			_edges[b[i]].emplace_back(a[i]);
		}
	}

	// calculate value
	NodeValue dfs1(int n, int parent) {
		for (auto next : _edges[n]) {
			if (next != parent) {
				_value[n] = _value[n].op(dfs1(next, n));
			}
		}
		return _value[n];
	}

	// reroot
	void dfs2(int n, int parent, NodeValue parentValue) {
		vector<int> indexes;
		vector<NodeValue> lsum, rsum;
		lsum.emplace_back(NodeValue::emptyValue());
		for (auto next : _edges[n]) {
			if (next != parent) {
				indexes.emplace_back(next);
				lsum.emplace_back(lsum.back().add(_value[next]));
			}
		}
		rsum.emplace_back(NodeValue::emptyValue());
		for (int i = indexes.size() - 1; i >= 0; --i) {
			NodeValue total;
			total = total.op(parentValue);
			total = total.op(lsum[i]);
			total = total.op(rsum.back());
			rsum.emplace_back(rsum.back().add(_value[indexes[i]]));
			_value[indexes[i]] = _value[indexes[i]].op(total);
			dfs2(indexes[i], n, total);
		}
	}
};

vector<int64_t> solve(int N, std::vector<int> U, std::vector<int> V) {
	vector<int64_t> ans(N, 0);
	Tree tree(N);
	tree.build_edges(U, V);
	tree.dfs1(0, -1);
	tree.dfs2(0, -1, Tree::NodeValue::emptyValue());
	for (int i = 0; i < N; ++i) {
		ans[i] = tree._value[i].cost;
	}
	return ans;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> U(N - 1), V(N - 1);
	for (int i = 0; i < N - 1; i++) {
		std::cin >> U[i] >> V[i];
		--U[i];
		--V[i];
	}
	vector<int64_t> ans = solve(N, U, V);
	for (auto x : ans) {
		cout << x << endl;
	}
	return 0;
}
