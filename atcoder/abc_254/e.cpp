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
	int64_t _size;
	vector<vector<int>> _edges;
	vector<set<int>> _s;
	vector<set<int>> _s2;

	Tree(int64_t size) : _size(size), _edges(size) { }

	void build_edges(const vector<int>& a, const vector<int>& b) {
		for (int64_t i = 0; i < a.size(); ++i) {
			_edges[a[i]].emplace_back(b[i]);
			_edges[b[i]].emplace_back(a[i]);
		}
	}

	void bfs() {
		_s = vector<set<int>>(_size);
		for (int i = 0; i < _size; ++i) {
			for (auto x : _edges[i]) {
				_s[i].insert(x);
			}
		}
		_s2 = vector<set<int>>(_size);
		for (int i = 0; i < _size; ++i) {
			for (auto x : _edges[i]) {
				for (auto y : _s[x]) {
					_s2[i].insert(y);
				}
			}
		}
	}

	int64_t query(int n, int k) {
		int64_t ans = 0;
		set<int> s;
		switch (k) {
		case 3:
			for (auto x : _edges[n]) {
				for (auto y : _s2[x]) {
					s.insert(y);
				}
			}
			[[fallthrough]];
		case 2:
			for (auto x : _s2[n]) {
				s.insert(x);
			}
			[[fallthrough]];
		case 1:
			for (auto x : _s[n]) {
				s.insert(x);
			}
			[[fallthrough]];
		case 0:
			s.insert(n);
			break;
		}
		for (auto x : s) {
			ans += x + 1;
		}
		return ans;
	}
};

void solve(int N, int M, std::vector<int> a, std::vector<int> b, int Q, std::vector<int> x, std::vector<int> k) {
	Tree tree(N);
	tree.build_edges(a, b);
	tree.bfs();
	for (int qq = 0; qq < Q; ++qq) {
		cout << tree.query(x[qq], k[qq]) << endl;
	}
}

int main() {
	int N, M, Q;
	std::cin >> N >> M;
	std::vector<int> a(M), b(M);
	for (int i = 0; i < M; i++) {
		std::cin >> a[i] >> b[i];
		--a[i];
		--b[i];
	}
	std::cin >> Q;
	std::vector<int> x(Q), k(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> x[i] >> k[i];
		--x[i];
	}
	solve(N, M, a, b, Q, x, k);
	return 0;
}
