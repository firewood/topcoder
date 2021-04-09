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
	vector<vector<int>> _edges;
	vector<int> _value;
	int _count;

	Tree(int size) : _size(size), _edges(size), _value(size, -1), _count(0) { }

	void build_edges(const vector<int>& a, const vector<int>&b) {
		for (int i = 0; i < a.size(); ++i) {
			_edges[a[i]].emplace_back(b[i]);
			_edges[b[i]].emplace_back(a[i]);
		}
	}

	void dfs(int n, const vector<int>& c) {
		_value[n] = c[_count++];
		for (auto next : _edges[n]) {
			if (_value[next] < 0) {
				dfs(next, c);
			}
		}
	}
};

void solve(int N, std::vector<int> &a, std::vector<int> &b, std::vector<int> &c) {
	Tree tree(N);
	tree.build_edges(a, b);
	sort(c.rbegin(), c.rend());
	tree.dfs(0, c);
	cout << accumulate(c.begin() + 1, c.end(), 0LL) << endl;
	string delim = "";
	for (auto x : tree._value) {
		cout << delim << x;
		delim = " ";
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
	std::vector<int> c(N);
	for (int i = 0; i < N; i++) {
		std::cin >> c[i];
	}
	solve(N, a, b, c);
	return 0;
}
