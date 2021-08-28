#include <iostream>
#include <cassert>
#include <cmath>
#include <cstring>
#include <chrono>
#include <algorithm>
#include <numeric>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>

using namespace std;

#ifdef _MSC_VER
#include <intrin.h>
inline uint32_t calc_log_size(uint32_t size) { unsigned long i; _BitScanReverse(&i, size); return i + 1; }
#else
inline uint32_t calc_log_size(unsigned long size) { return 32 - __builtin_clz(size); }
#endif

typedef pair<int64_t, int64_t> II;

static uint32_t _x = 2463534242;
static void xorshift32_seed(uint32_t seed) { if (seed) _x = seed; }
static inline uint32_t xorshift32(void) { _x ^= (_x << 13); _x ^= (_x >> 17); _x ^= (_x << 15); return _x; }
static inline uint32_t _rand() { return xorshift32(); }

auto start_time = chrono::high_resolution_clock::now();
int get_elapsed_ms() { return int(chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count()); }

const static double END_TIME = 2000 - 50;

struct Solver {
	int64_t N;
	int64_t M;
	int64_t K;
	vector<int64_t> m;
	int prev_reported;
	vector<II> ans;

	void input() {
		cin >> N >> M >> K;
		m.resize(N);
		for (int i = 0; i < N; ++i) {
			cin >> m[i];
		}
	}

	void reset() {
		prev_reported = 0;
		ans.clear();
	}

public:
	Solver() : prev_reported(0) { }

	void init() {
		input();
		reset();
	}

	int calc_score(const vector<int64_t>& w) {
		double score = 0;
		double k = log2(K);
		for (int i = 0; i < N; ++i) {
			score += k - log2(w[i]);
		}
		return ceil(score);
	}

	void run() {
		vector<int> seq(N);
		iota(seq.begin(), seq.end(), 0);
		sort(seq.begin(), seq.end(), [&](int lhs, int rhs) {
			return m[lhs] < m[rhs];
		});

#ifdef _DEBUG
		const int T1 = 100;
		const int T2 = 100;
#else
		const int T1 = 2000;
		const int T2 = 2000;
#endif

		int best_score = calc_score(m);
#ifdef _CONSOLE
		cerr << "INITIAL SCORE: " << best_score << endl;
#endif

		vector<int64_t> w = m;
		while (ans.size() < M / 3) {
			int64_t mx = -1, p = -1, q;

			for (int t = 0; t < T1; ++t) {
				int src = seq[_rand() % (N / 2)];
				int dst = seq[N / 2 + (_rand() % (N / 2))];
				int64_t after = (w[src] + w[dst]) % K;
				int64_t diff = w[src] - after;
				if (diff > mx) {
					mx = diff;
					p = src;
					q = dst;
				}

				src = seq[N / 2 + (_rand() % (N / 2))];
				dst = seq[_rand() % (N / 2)];
				after = (w[src] + w[dst]) % K;
				diff = after - w[src];
				if (diff > mx) {
					mx = diff;
					p = src;
					q = dst;
				}
			}

			if (mx >= 0) {
				ans.emplace_back(II(p, q));
				w[p] = (w[p] + w[q]) % K;
			} else {
				break;
			}
		}

		m = w;
		best_score = calc_score(m);
#ifdef _CONSOLE
		cerr << "SCORE: " << best_score << endl;
#endif

		while (ans.size() < M) {
			double mx = -1;
			int64_t p, q;
			for (int t = 0; t < T2; ++t) {
				int src = _rand() % N;
				int dst = _rand() % N;
				int64_t after = (w[src] + w[dst]) % K;
				double bs = log2(m[src]);
				double as = log2(after);
				double x = bs - as;
				if (x > mx) {
					mx = x;
					p = src;
					q = dst;
				}
			}

			if (mx >= 0) {
				ans.emplace_back(II(p, q));
				w[p] = (w[p] + w[q]) % K;
			} else {
				break;
			}
		}
		m = w;
		best_score = calc_score(m);

#ifdef _CONSOLE
		cerr << "SCORE: " << best_score << endl;
#endif
	}
};

int main(int argc, char* argv[]) {
	Solver solver;
	solver.init();
	solver.run();
	for (auto kv : solver.ans) {
		cout << kv.first << " " << kv.second << endl;
	}
}
