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

typedef long double LD;
typedef pair<int64_t, int64_t> II;

static const int64_t INF = 1LL << 62;

int64_t solve(int64_t B, int64_t K, int64_t Sx, int64_t Sy, int64_t Gx, int64_t Gy) {
	int64_t ans = INF;
	map<II, int64_t> start_costs;
	vector<int64_t> sxv = { Sx, Sx - (Sx % B), ((Sx + B - 1) / B) * B };
	vector<int64_t> syv = { Sy, Sy - (Sy % B), ((Sy + B - 1) / B) * B };
	vector<int64_t> gxv = { Gx, Gx - (Gx % B), ((Gx + B - 1) / B) * B };
	vector<int64_t> gyv = { Gy, Gy - (Gy % B), ((Gy + B - 1) / B) * B };
	auto calc_cost = [&](int64_t x) {
		return x % B == 0 ? 1 : K;
	};
	auto calc_minimal_cost = [&](int64_t sx, int64_t sy, int64_t gx, int64_t gy) {
		return min(
			abs(gx - sx) * calc_cost(sy) + abs(gy - sy) * calc_cost(gx),
			abs(gy - sy) * calc_cost(sx) + abs(gx - sx) * calc_cost(gy)
		);
	};
	for (const auto& x : sxv) {
		for (const auto& y : syv) {
			start_costs[II(x, y)] = calc_minimal_cost(Sx, Sy, x, y);
		}
	}
	for (const auto& x : gxv) {
		for (const auto& y : gyv) {
			int64_t goal_cost = calc_minimal_cost(x, y, Gx, Gy);
			for (const auto& kv : start_costs) {
				ans = min(ans, kv.second + calc_minimal_cost(kv.first.first, kv.first.second, x, y) + goal_cost);
			}
		}
	}
	return ans;
}

int main() {
	int64_t T, B, K, Sx, Sy, Gx, Gy;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> B >> K >> Sx >> Sy >> Gx >> Gy;
		cout << solve(B, K, Sx, Sy, Gx, Gy) << endl;
	}
	return 0;
}
