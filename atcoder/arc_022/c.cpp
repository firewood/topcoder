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

	Tree(int size) : _size(size), _edges(size) { }

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

	// 直径を求める
	int get_diameter(int& start, int& end) {
		int max_dist = 0;
		get_distance(-1, 0, 0, start, max_dist);
		get_distance(-1, start, 0, end, max_dist);
		if (start > end) swap(start, end);
		return max_dist;
	}
};

void solve(int N, std::vector<int>& A, std::vector<int>& B) {
	Tree tree(N);
	for (int i = 0; i < N - 1; i++) {
		tree._edges[A[i]].emplace_back(B[i]);
		tree._edges[B[i]].emplace_back(A[i]);
	}
	int start, end;
	tree.get_diameter(start, end);
	cout << start + 1 << " " << end + 1 << endl;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> A(N - 1), B(N - 1);
	for (int i = 0; i < N - 1; i++) {
		std::cin >> A[i] >> B[i];
		--A[i], --B[i];
	}
	solve(N, A, B);
	return 0;
}
