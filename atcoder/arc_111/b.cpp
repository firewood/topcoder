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

struct UnionFind {
	std::vector<int> _parent;
	std::vector<int> _size;
	UnionFind(int size) : _parent(size, -1), _size(size, 1) { }
	void unite(int a, int b) {
		int ra = root(a), rb = root(b); if (ra == rb) { return; }
		if (_size[ra] >= _size[rb]) { _parent[rb] = ra, _size[ra] += _size[rb]; } else { _parent[ra] = rb, _size[rb] += _size[ra]; }
	}
	int root(int a) {
		int p = _parent[a];
		if (p < 0) { return a; }
		while (_parent[p] >= 0) { p = _parent[p]; }
		return _parent[a] = p;
	}
	int size(int a) { return _size[root(a)]; }
};

int solve(int N, std::vector<int>& a, std::vector<int>& b) {
	const size_t COLORS = 400000;
	int ans = 0;
	UnionFind uf(COLORS);
	for (int i = 0; i < N; i++) {
		uf.unite(a[i], b[i]);
	}
	vector<int> count(COLORS);
	for (int i = 0; i < N; i++) {
		count[uf.root(a[i])] += 1;
	}
	for (int i = 0; i < COLORS; i++) {
		if (i == uf.root(i)) {
			int size = uf.size(i);
			ans += size - (count[i] < size);
		}
	}
	return ans;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> a(N), b(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i] >> b[i];
		--a[i]; --b[i];
	}
	cout << solve(N, a, b) << endl;
	return 0;
}
