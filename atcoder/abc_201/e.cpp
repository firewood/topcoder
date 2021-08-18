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

static const int64_t MOD = 1000000007;

struct modint {
	int64_t x;
	modint() { }
	modint(int _x) : x(_x) { }
	operator int() const { return (int)x; }
	modint operator+(int y) { return (x + y + MOD) % MOD; }
	modint operator+=(int y) { x = (x + y + MOD) % MOD; return *this; }
	modint operator-(int y) { return (x - y + MOD) % MOD; }
	modint operator-=(int y) { x = (x - y + MOD) % MOD; return *this; }
	modint operator*(int y) { return (x * y) % MOD; }
	modint operator*=(int y) { x = (x * y) % MOD; return *this; }
	modint operator/(int y) { return (x * modpow(y, MOD - 2)) % MOD; }
	modint operator/=(int y) { x = (x * modpow(y, MOD - 2)) % MOD; return *this; }
	static modint modinv(int a) { return modpow(a, MOD - 2); }
	static modint modpow(int a, int b) {
		modint x = a, r = 1;
		for (; b; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

struct Tree {
	int64_t _size;
	vector<vector<pair<int64_t, int64_t>>> _edges;
	vector<int64_t> _color;

	Tree(int64_t size) : _size(size), _edges(size), _color(size, -1) { }

	void build_edges(const vector<int64_t>& a, const vector<int64_t>& b, const vector<int64_t>& c) {
		for (int64_t i = 0; i < a.size(); ++i) {
			_edges[a[i]].emplace_back(make_pair(b[i], c[i]));
			_edges[b[i]].emplace_back(make_pair(a[i], c[i]));
		}
	}

	void dfs(int n, int64_t color) {
		_color[n] = color;
		for (auto [next, weight] : _edges[n]) {
			if (_color[next] < 0) {
				dfs(next, color ^ weight);
			}
		}
	}
};

int64_t solve(int N, std::vector<int64_t> u, std::vector<int64_t> v, std::vector<int64_t> w) {
	modint ans = 0;
	Tree tree(N);
	tree.build_edges(u, v, w);
	tree.dfs(0, 0);
	for (int i = 0; i < 60; ++i) {
		modint c = 0;
		for (int j = 0; j < N; ++j) {
			c += (tree._color[j] >> i) & 1;
		}
		ans += c * (N - c) * int((1LL << i) % MOD);
	}
	return ans;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int64_t> u(N-1), v(N-1), w(N-1);
	for (int i = 0; i < N-1; i++) {
		std::cin >> u[i] >> v[i] >> w[i];
		--u[i]; --v[i];
	}
	cout << solve(N, u, v, w) << endl;
	return 0;
}
