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

static uint32_t _x = 2463534242;

static const int TIME_LIMIT = 2000;
auto start_time = high_resolution_clock::now();
int past() {
	return duration_cast<milliseconds>(high_resolution_clock::now() - start_time).count();
}
bool is_timed_out() {
	return past() > (TIME_LIMIT - 250);
}

int n;
vector<int> x, y;
double target_dist;

vector< vector<int> > connected;


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

static void calc_target_dist() {
	vector<double> dists;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			double dx = x[i] - x[j], dy = y[i] - y[j];
			dists.push_back(sqrt(dx * dx + dy * dy));
		}
	}
	sort(dists.begin(), dists.end());
	int rcnt = 0;
	double rsum = 0;
	for (double range = 15; range <= 25; range += 1) {
		++rcnt;
		double mv;
		size_t mx = 0;
		for (double low = 10; low <= 300; low += 2) {
			size_t cnt = lower_bound(dists.begin(), dists.end(), low + range) - lower_bound(dists.begin(), dists.end(), low);
			if (cnt >= mx) {
				mx = cnt;
				mv = low;
			}
		}
		rsum += mv + range / 2;
//		cout << "RANGE: " << range << ", LOW: " << mv << ", MID: " << (mv + range/2) << ", CNT: " << mx << endl;
	}
	target_dist = rsum / rcnt;
//	cout << "TARGET_DIST: " << target_dist << endl;
}

void gen(double target_dist) {
	typedef bitset<200> BS;
	typedef pair<int, vector<int> > IVI;
	unordered_map<BS, IVI> m[10][200];

	typedef pair<double, int> DI;
	vector< vector<DI> > dists(n);
	vector< vector<double> > rawdists(n, vector<double>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			double dx = x[i] - x[j], dy = y[i] - y[j];
			double d = sqrt(dx * dx + dy * dy);
			double dd = fabs(target_dist - d);
			rawdists[i][j] = rawdists[j][i] = dd;
			if (dd <= 30) {
				dists[i].push_back(DI(dd, j));
				dists[j].push_back(DI(dd, i));
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		sort(dists[i].begin(), dists[i].end());
	}
#ifdef _DEBUG
	const int GENS = 10;
#else
	const int GENS = 500;
#endif
	for (int st = 0; st < n; ++st) {
		for (int i = 0; i < GENS; ++i) {
			BS bs;
			bs[st] = true;
			vector<int> v(1, st);
			int prev = st;
			for (int j = 0; j < 10; ++j) {
				const vector<DI> &di = dists[prev];
				int next = -1;
				for (int k = 0; k < 40; ++k) {
					const DI &r = di[_rand() % di.size()];
					if (!bs[r.second]) {
						next = r.second;
						break;
					}
				}
				if (next < 0) {
					break;
				}
				bs[next] = true;
				v.push_back(next);
				prev = next;
				m[j][st][bs] = IVI(next, v);
			}
		}
	}

	int node = 0;
	BS used, none;
	vector<int> t;
	for (auto kv : m[9][node]) {
		used = kv.first;
		t = kv.second.second;
		node = t.back();
		used[node] = false;
		break;
	}
	int mx = 9;
	while (true) {
		for (int i = 5; i >= 0; --i) {
			for (auto kv : m[i][node]) {
				if ((used & kv.first) == 0) {
					used |= kv.first;
					for (int n : kv.second.second) {
						if (n != node) {
							t.push_back(n);
						}
					}
					node = t.back();
					used[node] = false;
//					cout << "SZ: " << t.size() << endl;
					goto next;
				}
			}
			int rnode = t.front();
			BS rused = used;
			rused[node] = true;
			rused[rnode] = false;
			for (auto kv : m[i][rnode]) {
				if ((rused & kv.first) == 0) {
					reverse(t.begin(), t.end());
					used = rused;
					used |= kv.first;
					for (int n : kv.second.second) {
						if (n != rnode) {
							t.push_back(n);
						}
					}
					node = t.back();
					used[node] = false;
//					cout << "RSZ: " << t.size() << endl;
					goto next;
				}
			}
		}
		break;
	next:
		;
	}

	vector<int> remains;
	remains.push_back(node);
	used[node] = true;
	int rcnt = 0;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			++rcnt;
			remains.push_back(i);
		}
	}
	remains.push_back(t.front());
	vector<int> best = remains;
	double bs = 1e20;
#ifdef _DEBUG
	for (int tt = 0; tt < 1000; ++tt) {
#else
	while (!is_timed_out()) {
#endif
		random_shuffle(remains.begin() + 1, remains.begin() + 1 + rcnt);
		double s = 0;
		for (int i = 1; i <= rcnt; ++i) {
			double d = rawdists[remains[i - 1]][remains[i]];
			s += d * d;
		}
		if (s < bs) {
			bs = s;
			best = remains;
		}
	}
	for (int i = 0; i < rcnt; ++i) {
		t.push_back(remains[i + 1]);
	}
	for (int i = 0; i < n; ++i) {
		cout << t[i] << endl;
	}
}

int main(int argc, const char * argv[]) {
	cin >> n;
	x.resize(n);
	y.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	calc_target_dist();
	gen(target_dist);
	return 0;
}
