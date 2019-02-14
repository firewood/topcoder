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

int n, m;
vector< vector<int> > b(200, vector<int>(200));
vector< vector<int> > vis;
vector< vector<int> > vis2;
typedef pair<int, int> II;
typedef pair<int, II> III;
vector<III> cmd;

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

int dfs(int v, int i, int j, int t, int &cnt) {
	++cnt;
	int cost = v - b[i][j];
	const int dx[] = { -1,1,0,0 };
	const int dy[] = { 0,0,-1,1 };
	vis[i][j] = 1;
	for (int d = 0; d < 4; ++d) {
		int r = i + dy[d], c = j + dx[d];
		if (r >= 0 && r < n && c >= 0 && c < n && !vis[r][c]) {
			vis[r][c] = 1;
			if (b[r][c] >= v - t && b[r][c] <= v) {
				cost += dfs(v, r, c, t, cnt);
			}
		}
	}
	return cost;
}

void fill(int v, int i, int j, int t) {
	const int dx[] = { -1,1,0,0 };
	const int dy[] = { 0,0,-1,1 };
	vis2[i][j] = 1;
	int f = v - b[i][j];
	for (int x = 0; x < f; ++x) {
		cmd.push_back(III(1, II(i, j)));
		b[i][j] = 0;
	}
	for (int d = 0; d < 4; ++d) {
		int r = i + dy[d], c = j + dx[d];
		if (r >= 0 && r < n && c >= 0 && c < n && !vis2[r][c]) {
			vis2[r][c] = 1;
			if (b[r][c] >= v - t && b[r][c] <= v) {
				fill(v, r, c, t);
			}
		}
	}
}

int main(int argc, const char * argv[]) {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> b[i][j];
		}
	}

	const int th = 3;
	for (int v = 9; v >= 1; --v) {
		vis = vector< vector<int> >(200, vector<int>(200));
		vis2 = vector< vector<int> >(200, vector<int>(200));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (b[i][j] == v && !vis[i][j]) {
					int cnt = 0;
					int cost = 1 + dfs(v, i, j, th, cnt);
					int gain = cnt * v;
					if (cnt >= v && gain > 0 && cost < 100 && ((int)cmd.size() + cost) <= m) {
						fill(v, i, j, th);
						cmd.push_back(III(2, II(i, j)));
					}
//					if (cnt >= v && gain > 0) {
//						cout << v << ", gain: " << gain << ", cost:" << cost << "," << cnt << "," << endl;
//					}
				}
			}
		}
	}
	while ((int)cmd.size() < m) {
		cmd.push_back(III(2, II(0, 0)));
	}
	for (auto kv : cmd) {
		cout << kv.first << " " << kv.second.first << " " << kv.second.second << endl;
	}
	return 0;
}
