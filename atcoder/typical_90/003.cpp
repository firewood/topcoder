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

	void get_distance(int parent_node, int node, int dist, int& max_dist_node, int& max_dist) {
		if (dist > max_dist) {
			max_dist_node = node;
			max_dist = dist;
		}
		for (auto next_node : _edges[node]) {
			if (next_node != parent_node) {
				get_distance(node, next_node, dist + 1, max_dist_node, max_dist);
			}
		}
	}

	int get_diameter(int &start, int &end) {
		int max_dist = 0;
		get_distance(-1, 0, 0, start, max_dist);
		max_dist = 0;
		get_distance(-1, start, 0, end, max_dist);
		if (start > end) swap(start, end);
		return max_dist;
	}
};

int solve(int N, std::vector<int>& A, std::vector<int>& B) {
	Tree tree(N);
	tree.build_edges(A, B);
	int start, end;
	return tree.get_diameter(start, end) + 1;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> A(N - 1), B(N - 1);
	for (int i = 0; i < N - 1; i++) {
		std::cin >> A[i] >> B[i];
		--A[i], --B[i];
	}
	cout << solve(N, A, B) << endl;
	return 0;
}
