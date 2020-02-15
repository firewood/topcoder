#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <chrono>
#include <cmath>
#include <cassert>
#include <cstring>

using namespace std;
using namespace std::chrono;

typedef pair<int, int> II;

int N;
int W;
int K;
int V;
vector<II> cv;

#ifdef _DEBUG
static const int TIME_LIMIT = 500;
#else
static const int TIME_LIMIT = 2000;
#endif
static const double TIME_SPAN = TIME_LIMIT - 50;
auto start_time = high_resolution_clock::now();
int past() {
	return (int)(duration_cast<milliseconds>(high_resolution_clock::now() - start_time).count());
}
bool is_timed_out() {
	return past() > TIME_SPAN;
}
double Temperature() {
	return max(0.0, 100.0 - pow(100.0, (double)past() / TIME_SPAN));
}

double Exchange_Probability(double temp, double exchange_cost) {
	return exp(-exchange_cost / temp);
}

static uint32_t _x = 2463534242;
static void xorshift32_seed(uint32_t seed)
{
	if (seed != 0) {
		_x = seed;
	}
}
static uint32_t xorshift32(void)
{
	_x ^= (_x << 13);
	_x ^= (_x >> 17);
	_x ^= (_x << 15);
	return _x;
}
static __inline uint32_t _rand() {
	return xorshift32();
}

struct Color {
	char c[8];
};
struct Value {
	short v[8];
};
struct History {
	int sb;
	short h[8];
	vector<Color> c;
	vector<Value> v;
	vector<int> hist;
	History() {
		sb = 0;
		memset(h, 0, sizeof(h));
	}
	int score() {
		int s = sb;
		int rows = 1 << 30;
		for (int i = 0; i < 8; ++i) {
			rows = min(rows, (int)h[i]);
		}
		for (int i = 0; i < rows; ++i) {
			int vv[6] = {};
			int mv = 0;
			for (int j = 0; j < 8; ++j) {
				int cc = c[i].c[j];
				vv[cc] += v[i].v[j];
				mv = max(mv, vv[cc]);
			}
			s += mv;
		}
		sb = s;
		return s;
	}

	void shrink() {
		int rows = 1 << 30;
		for (int i = 0; i < 8; ++i) {
			rows = min(rows, (int)h[i]);
		}
		c.erase(c.begin(), c.begin() + rows);
		v.erase(v.begin(), v.begin() + rows);
		for (int i = 0; i < 8; ++i) {
			h[i] -= rows;
		}
	}

	void gen(int offset, int count) {
		int ed = min(N, offset + count);
		for (int i = offset; i < ed; ++i) {
			int nx;
			int col = cv[i].first;
			int val = cv[i].second;
			for (int k = 0; k < W; ++k) {
				if (k > 0 && h[k - 1] > h[k] && c[h[k]].c[k - 1] == col) {
					nx = k;
					goto next;
				}
			}
			nx = _rand() % W;
		next:
			{
				hist.push_back(nx);
				int prev_height = h[nx];
				h[nx] = prev_height + 1;
				if (c.size() == prev_height) {
					c.resize(h[nx]);
					v.resize(h[nx]);
				}
				c[prev_height].c[nx] = col;
				v[prev_height].v[nx] = val;
			}
		}
	}
};

vector<int> c1(int offset, int count) {
	vector<int> c(K);
	for (int i = 0; i < count; ++i) {
		int j = i + offset;
		if (j >= N) break;
		c[cv[j].first] += 1;
	}
	return c;
}

int main(int argc, const char* argv[]) {
	cin >> N >> W >> K >> V;
	cv.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> cv[i].first >> cv[i].second;
	}

	vector<int> ans;
	History hist;
	vector<History> hists;
	for (int i = 0; i < 1; ++i) {
		hists.push_back(hist);
	}
	const int steps = 40;
	for (int i = 0; i < N; i += steps) {
		int te = (int)(((double)(min(N, i + steps)) / N) * TIME_SPAN);
		for (int j = 0; j < (int)hists.size(); ++j) {
			int ms = 0;
			History mh;
			for (int t = 0; t < 10000000; ++t) {
				History h = hists[j];
				h.gen(i, steps);
				int s = h.score();
				if (s > ms) {
					ms = s;
					mh = h;
				}
				if (t % 10 == 0 && past() > te) {
					goto done;
				}
			}
		done:
			mh.shrink();
			hists[j] = mh;
		}
	}

	History mh;
	int ms = 0;
	for (int j = 0; j < (int)hists.size(); ++j) {
		int s = hists[j].score();
		if (s > ms) {
			ms = s;
			mh = hists[j];
		}
	}
	ans = mh.hist;

	for (auto a : ans) {
		cout << a << endl;
	}

	fprintf(stderr, "PAST: %d\n", past());

	return 0;
}
