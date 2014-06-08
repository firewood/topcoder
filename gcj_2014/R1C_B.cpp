// Google Code Jam 2014 R1C
// Problem B. Reordering Train Cars

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;
typedef vector<string> StrVec;
typedef long long LL;

struct UnionFind {
	std::vector<int> _parent;
	std::vector<int> _size;
	UnionFind(int size) : _parent(size, -1), _size(size, 1) { }
	void unite(int a, int b) {
		int ra = root(a), rb = root(b);
		if (ra == rb)
			return;
		if (_size[ra] >= _size[rb]) {
			_parent[rb] = ra, _size[ra] += _size[rb];
		} else {
			_parent[ra] = rb, _size[rb] += _size[ra];
		}
	}
	int root(int a) {
		int p = _parent[a];
		if (p < 0)
			return a;
		while (_parent[p] >= 0)
			p = _parent[p];
		return _parent[a] = p;
	}
	int size(int a) { return _size[root(a)]; }
};

int solve() {
	string s;
	getline(cin, s);
	int N = atoi(s.c_str());
	int same[256] = {};
	int used[256] = {};
	StrVec cars;
	getline(cin, s);
	stringstream ss(s);
	for (int i = 0; i < N; ++i) {
		bool f = false;
		string car;
		ss >> car;

		for (char c = 'a'; c <= 'z'; ++c) {
			int cnt = 0;
			for (int j = 0; j < (int)car.length(); ++j) {
				cnt += car[j] == c;
			}
			if (cnt == (int)car.length()) {
				same[c] += 1;
				f = true;
				break;
			}
		}
		if (!f) {
			cars.push_back(car);
		}
	}

	N = (int)cars.size();
	UnionFind uf(128);

	for (int i = 0; i < N; ++i) {
		int bcnt = 0;
		int tcnt = 0;
		string &car = cars[i];
		for (int j = i + 1; j < N; ++j) {
			string &tar = cars[j];
			int pos = (int)tar.find(car[0]);
			if (pos >= 0) {
				used[car[0]] = 1;

				++bcnt;
				if (bcnt >= 2) {
					return 0;
				}
				for (int k = pos; k < tar.length(); ++k) {
					if (tar[k] != car[0]) {
						return 0;
					}
				}
				if (uf.root(i) == uf.root(j)) {
					return 0;
				}
				uf.unite(i, j);
			}
			pos = (int)tar.rfind(car.back());
			if (pos >= 0) {
				used[car.back()] = 1;

				++tcnt;
				if (tcnt >= 2) {
					return 0;
				}
				for (int k = 0; k < pos; ++k) {
					if (tar[k] != car.back()) {
						return 0;
					}
				}
				if (uf.root(i) == uf.root(j)) {
					return 0;
				}
				uf.unite(i, j);
			}
		}
	}

	LL ans = 1;

	int groups = 0;
	for (int i = 0; i < N; ++i) {
		if (uf.root(i) == i) {
			++groups;
		}
	}
	for (int i = 0; i < 256; ++i) {
		if (same[i] >= 1) {
			bool f = false;
			for (int j = 0; j < N; ++j) {
				if (cars[j][0] == i || cars[j].back() == i) {
					f = true;
				}
			}

			for (LL x = 1; x <= same[i]; ++x) {
				ans *= x;
				ans %= 1000000007;
			}
			if (!f) {
				++groups;
			}
		}
	}

	for (LL x = groups; x > 1; --x) {
		ans *= x;
		ans %= 1000000007;
	}

	int check[256] = {};
	for (int i = 0; i < 256; ++i) {
		if (same[i] >= 1) {
			check[i] = 1;
		}
	}
	for (int i = 0; i < N; ++i) {
		string &s = cars[i];
		for (int j = 0; j < (int)s.length(); ++j) {
			check[s[j]] = 1;
		}
	}

	for (int i = 0; i < 256; ++i) {
		int w = used[i] != 0 || same[i] != 0;
		w = used[i] != 0;
		if (check[i] > 0) {
			for (int j = 0; j < N; ++j) {
				string &s = cars[j];
				int a = (int)s.find(i);
				int b = (int)s.rfind(i);
				if (a >= 0) {
					for (int k = a; k <= b; ++k) {
						if (s[k] != i) {
							return 0;
						}
					}
					if (a == 0 || b == (s.length() - 1)) {
						;
					} else {
						++w;
						if (w >= 2) {
							return 0;
						}
					}
				}
			}
		}
	}

	return ans;
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	if (T <= 0) return 0;

	for (int t = 1; t <= T; ++t) {
		int ans = solve();
		printf("Case #%d: %d\n", t, ans);
	}

	return 0;
}

