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

	void build_unidirection_edges(const vector<int>& a, const vector<int>& b) {
		for (int i = 0; i < a.size(); ++i) {
			_edges[a[i]].emplace_back(b[i]);
		}
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

vector<int> solve(int N, int M, std::vector<int> A, std::vector<int> B) {
	Tree tree(N);
	tree.build_unidirection_edges(A, B);
	return tree.topological_sort();
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> A(M), B(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i] >> B[i];
		--A[i];
		--B[i];
	}
	vector<int> ans = solve(N, M, A, B);
	if (ans.size() < N) {
		cout << -1 << endl;
	} else {
		for (int i = 0; i < ans.size(); ++i) {
			if (i) cout << " ";
			cout << (ans[i] + 1);
		}
		cout << endl;
	}
}
