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

#ifdef _MSC_VER
#define popcount __popcnt64
#else
#define popcount __builtin_popcountll
#endif

typedef pair<int64_t, int64_t> II;

int64_t solve(int64_t N, std::vector<int64_t> S, std::vector<int64_t> C) {
	int64_t ans = 0;
	priority_queue<II, vector<II>, greater<>> q;
	for (int i = 0; i < N; ++i) {
		q.emplace(II(S[i], C[i]));
	}
	while (!q.empty()) {
		int64_t x = q.top().first, c = 0;
		while (!q.empty() && q.top().first == x) {
			c += q.top().second;
			q.pop();
		}
		ans += c % 2;
		if (c > 1) {
			q.emplace(II(x * 2, c / 2));
		}
	}
	return ans;
}

int64_t solve2(int64_t N, std::vector<int64_t> S, std::vector<int64_t> C) {
	int64_t ans = 0;
	map<int64_t, int64_t> m;
	for (int i = 0; i < N; ++i) {
		m[S[i]] = C[i];
	}
	for (auto kv = m.rbegin(); kv != m.rend(); ++kv) {
		int64_t x = kv->first, y = x;
		while ((y % 2) == 0) {
			y /= 2;
		}
		while (y < x) {
			if (m.find(y) != m.end()) {
				int64_t c = m[y], d = c / 2;
				m[y * 2] += d;
				m[y] -= d * 2;
			}
			y *= 2;
		}
		ans += popcount(m[x]);
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> S(N), C(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i] >> C[i];
	}
	cout << solve(N, S, C) << endl;
	return 0;
}
