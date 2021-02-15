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

	void get_distance(int n, int d, vector<int> &dist) {
		dist[n] = d;
		for (auto next : _edges[n]) {
			if (dist[next] < 0) {
				get_distance(next, d + 1, dist);
			}
		}
	}

	// 直径を求める
	int get_diameter() {
		vector<int> dist(_size, -1);
		get_distance(0, 0, dist);
		int start = (int)(max_element(dist.begin(), dist.end()) - dist.begin());
		fill(dist.begin(), dist.end(), -1);
		get_distance(start, 0, dist);
		return *max_element(dist.begin(), dist.end());
	}
};

bool solve(int N, std::vector<int> &a, std::vector<int> &b) {
	Tree tree(N);
	for (int i = 0; i < N - 1; i++) {
		tree._edges[a[i]].emplace_back(b[i]);
		tree._edges[b[i]].emplace_back(a[i]);
	}
	return tree.get_diameter() % 3 != 1;
}

int main() {
    int N;
	std::cin >> N;
	std::vector<int> a(N-1), b(N-1);
	for (int i = 0; i < N-1; i++) {
		std::cin >> a[i] >> b[i];
		--a[i], --b[i];
	}
	cout << (solve(N, a, b) ? "First" : "Second") << endl;
	return 0;
}
