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

using namespace std;
using namespace std::chrono;

int n;
vector<int> x, y;
vector< vector<double> > dists;

static const int TIME_LIMIT = 2000;
auto start_time = high_resolution_clock::now();
int past() {
	return (int)(duration_cast<milliseconds>(high_resolution_clock::now() - start_time).count());
}
bool is_timed_out() {
	return past() > (TIME_LIMIT - 250);
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

static double calc_target_dist() {
	vector<double> flat_dists;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			flat_dists.push_back(dists[i][j]);
		}
	}
	sort(flat_dists.begin(), flat_dists.end());
	int rcnt = 0;
	double rsum = 0;
	for (double range = 15; range <= 25; range += 1) {
		++rcnt;
		double mv;
		size_t mx = 0;
		for (double low = 10; low <= 300; low += 2) {
			size_t cnt = lower_bound(flat_dists.begin(), flat_dists.end(), low + range) - lower_bound(flat_dists.begin(), flat_dists.end(), low);
			if (cnt >= mx) {
				mx = cnt;
				mv = low;
			}
		}
		rsum += mv + range / 2;
	}
	return rsum / rcnt;
}

void gen(double target_dist) {
	typedef pair<double, int> DI;
	typedef pair<int, int> II;
	typedef pair<double, II> DII;
	vector< vector<DI> > ddiffs(n);
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			double d = fabs(dists[i][j] - target_dist);
			ddiffs[i].push_back(DI(d, j));
			ddiffs[j].push_back(DI(d, i));
		}
	}
	for (int i = 0; i < n; ++i) {
		sort(ddiffs[i].begin(), ddiffs[i].end());
	}
	vector<int> conn(n, -1);
	int start_node = 0;
	int prev = start_node;
	for (int i = 0; i < n - 1; ++i) {
		for (auto kv : ddiffs[prev]) {
			int next = kv.second;
			if (conn[next] < 0) {
				conn[prev] = next;
				prev = next;
				break;
			}
		}
	}
	conn[prev] = start_node;
	int zc = 0;
	double avg;
	vector<DI> dd(n);
//	const int takes = n;
	while (!is_timed_out()) {
		avg = 0;
		for (int i = 0; i < n; ++i) {
			avg += dists[i][conn[i]];
			dd[i].second = i;
		}
		avg /= n;
		for (int i = 0; i < n; ++i) {
			dd[i].first = fabs(dists[i][conn[i]] - avg);
			dd[i].first = dd[i].first * dd[i].first;
		}
//		sort(dd.rbegin(), dd.rend());
		for (int t = 0; t < 1000; ++t) {
			int p = _rand() % n, q = _rand() % n;
			int a = dd[p].second, b = conn[a];
			int c = dd[q].second, d = conn[c];
			if (a != c) {
				double x = fabs(dists[a][c] - avg), y = fabs(dists[b][d] - avg);
				if (x * x + y * y < dd[p].first + dd[q].first) {
				prev = d;
					int curr = b;
					while (curr != d) {
						int next = conn[curr];
						conn[curr] = prev;
						prev = curr;
						curr = next;
					}
					conn[a] = c;
					++zc;
					break;
				}
			}
		}
	}
//	cout << zc << "," << avg << endl;
	prev = start_node;
	for (int i = 0; i < n; ++i) {
		int next = conn[prev];
		cout << next << endl;
		prev = next;
	}
}

int main(int argc, const char * argv[]) {
	cin >> n;
	x.resize(n);
	y.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	dists = vector< vector<double> >(n, vector<double>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int dx = x[i] - x[j], dy = y[i] - y[j];
			dists[i][j] = dists[j][i] = sqrt(dx * dx + dy * dy);
		}
	}
	double target_dist = calc_target_dist();
	gen(target_dist);
	return 0;
}
