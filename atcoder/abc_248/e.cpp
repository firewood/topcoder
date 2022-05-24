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

typedef pair<int64_t, int64_t> II;

static const int64_t INF = 1LL << 60;

int64_t gcd(int64_t a, int64_t b) { return b ? gcd(b, a % b) : a; }
int64_t lcm(int64_t a, int64_t b) { return (a / gcd(a, b)) * b; }

int64_t solve(int64_t N, int64_t K, std::vector<int64_t> X, std::vector<int64_t> Y) {
	if (K == 1) {
		return INF;
	}
	int64_t ans = 0;
	set<II> s;
	for (int i = 0; i < N; ++i) {
		map<II, vector<int>> m;
		for (int k = 0; k < N; ++k) {
			if (i == k) continue;
			int64_t dx = X[k] - X[i], dy = Y[k] - Y[i], g;
			if (dx == 0) {
				g = dy;
			} else if (dy == 0) {
				g = dx;
			} else {
				if (dx < 0) {
					dx = -dx;
					dy = -dy;
				}
				g = gcd(abs(dx), abs(dy));
			}
			m[II(dx / g, dy / g)].emplace_back(k);
		}
		for (auto kv : m) {
			const vector<int>& v = kv.second;
			if (v[0] < i) {
				continue;
			}
			if (v.size() >= K - 1) {
				++ans;
			}
		}
	}
	return ans;
}

int main() {
	int64_t N, K;
	std::cin >> N >> K;
	std::vector<int64_t> X(N), Y(N);
	for (int i = 0; i < N; i++) {
		std::cin >> X[i] >> Y[i];
	}
	int64_t ans = solve(N, K, X, Y);
	if (ans == INF) {
		cout << "Infinity" << endl;
	} else {
		cout << ans << endl;
	}
	return 0;
}
