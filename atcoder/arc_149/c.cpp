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

static uint32_t _x = 2463534242;
static void xorshift32_seed(uint32_t seed) { if (seed) _x = seed; }
static inline uint32_t xorshift32(void) { _x ^= (_x << 13); _x ^= (_x >> 17); _x ^= (_x << 15); return _x; }
static inline uint32_t _rand() { return xorshift32(); }

inline void random_shuffle(vector<int>& seq, size_t size) {
	for (size_t i = 0; i < size; ++i) {
		swap(seq[i], seq[_rand() % size]);
	}
}

typedef pair<int, int> II;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

set<int> primes = { 2 };

void gen_primes() {
	for (int i = 3; i <= 2000002; i += 2) {
		for (int prime : primes) {
			if (i < prime * prime) {
				primes.insert(i);
				break;
			}
			if ((i % prime) == 0) {
				break;
			}
		}
	}
}

void solve(int N) {
	vector<int> eseq, oseq;
	for (int i = 1; i <= N * N; ++i) {
		if (i % 2) {
			oseq.push_back(i);
		} else {
			eseq.push_back(i);
		}
	}
	random_shuffle(eseq, eseq.size());
	random_shuffle(oseq, oseq.size());

	vector<vector<int>> a(N, vector<int>(N)), f(N, vector<int>(N));
	vector<int> ey, ex, oy, ox;
	int ei = 0, oi = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (ei < eseq.size()) {
				f[i][j] = 0;
				a[i][j] = eseq[ei++];
				ey.emplace_back(i);
				ex.emplace_back(j);

			} else {
				f[i][j] = 1;
				a[i][j] = oseq[oi++];
				oy.emplace_back(i);
				ox.emplace_back(j);
			}
		}
	}

	if (N == 3) {
		a = {
			{1,5,3},
			{8,7,9},
			{4,2,6}
		};
	}

	set<II> r;

	auto check = [&](int y, int x) {
		for (int d = 0; d < 4; ++d) {
			int ny = y + dy[d], nx = x + dx[d];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (primes.find(a[y][x] + a[ny][nx]) != primes.end()) {
					return false;
				}
			}
		}
		return true;
	};

	auto check_all = [&]() {
		r.clear();
		for (int i = (N - 1) / 2; i <= N / 2; ++i) {
			for (int j = 0; j < N; ++j) {
				if (!check(i, j)) {
					r.insert(II(i, j));
				}
			}
		}
		return r.empty();
	};

	auto validate = [&]() {
		set<II> rr = r;
		for (auto kv : rr) {
			int i = kv.first, j = kv.second;
			if (check(i, j)) {
				r.erase(kv);
			}
		}
		return r.empty();
	};

	while (!check_all()) {
		while (!validate()) {
			for (auto kv : r) {
				int yy = kv.first, xx = kv.second;
				if (f[yy][xx]) {
					int ai = _rand() % ox.size();
					swap(a[oy[ai]][ox[ai]], a[yy][xx]);
				} else {
					int ai = _rand() % ex.size();
					swap(a[ey[ai]][ex[ai]], a[yy][xx]);
				}
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (j)cout << " ";
			cout << a[i][j];
		}
		cout << endl;
	}
}

int main() {
	gen_primes();
	int N;
	std::cin >> N;
	solve(N);
	return 0;
}
