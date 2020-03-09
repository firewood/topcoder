// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <set>
#include <cassert>

using namespace std;

vector<vector<int>> e;
set<int> g[2];

void color(int n, int c) {
	g[c].insert(n);
	c = (c + 1) % 2;
	for (int x : e[n]) {
		if (g[c].find(x) == g[c].end()) {
			color(x, c);
		}
	}
}

void assign(set<int>& g, vector<int>& pool, vector<int>& v) {
	set<int> r = g;
	for (int x : g) {
		if (pool.empty()) {
			break;
		}
		v[x] = pool.back();
		pool.pop_back();
		r.erase(x);
	}
	g = r;
}

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1, a, b;
		cin >> n;
		if (n < 0) return 0;
		e.clear();
		e.resize(n);
		g[0].clear();
		g[1].clear();
		for (int i = 0; i < n - 1; ++i) {
			cin >> a >> b;
			--a, --b;
			e[a].push_back(b);
			e[b].push_back(a);
		}
		color(0, 0);
		if (g[0].size() > g[1].size()) {
			swap(g[0], g[1]);
		}
		vector<int> pool[3];
		for (int i = 1; i <= n; ++i) {
			pool[i % 3].push_back(i);
		}
		vector<int> vars(n, -1);
		if (g[0].size() <= pool[0].size()) {
			assign(g[0], pool[0], vars);
			for (auto p : pool) {
				assign(g[1], p, vars);
			}
		} else if (g[0].size() >= pool[2].size() && g[1].size() >= pool[1].size()) {
			assign(g[0], pool[2], vars);
			assign(g[0], pool[0], vars);
			assign(g[1], pool[1], vars);
			assign(g[1], pool[0], vars);
		}
		for (int a : vars) {
			cout << " " << a;
			if (a < 0) break;
		}
		cout << endl;
	}
	return 0;
}
