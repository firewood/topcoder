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
	int get_diameter(int &start, int &end) {
		int max_dist = 0;
		get_distance(-1, 0, 0, start, max_dist);
		get_distance(-1, start, 0, end, max_dist);
		return max_dist;
	}
};

bool solve(int N, std::vector<int>& a, std::vector<int>& b) {
	Tree tree(N);
	for (int i = 0; i < N - 1; i++) {
		tree._edges[a[i]].emplace_back(b[i]);
		tree._edges[b[i]].emplace_back(a[i]);
	}
	int start, end;
	return tree.get_diameter(start, end) % 3 != 1;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> a(N - 1), b(N - 1);
	for (int i = 0; i < N - 1; i++) {
		std::cin >> a[i] >> b[i];
		--a[i], --b[i];
	}
	cout << (solve(N, a, b) ? "First" : "Second") << endl;
	return 0;
}
