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

typedef long long LL;
typedef pair<LL, LL> LLLL;
const LL INF = 1LL << 60;

LL a, b, c, d;
map<LL, LL> memo;

LL solve(LL n) {
	if (n <= 1) return n * d;
	if (memo.find(n) != memo.end()) {
		return memo[n];
	}
	const LL v[3] = { 2, 3, 5 };
	const LL w[3] = { a, b, c };
	LL mn = INF / d > n ? n * d : INF;
	for (LL i = 0; i < 3; ++i) {
		mn = min(mn, (n % v[i]) * d + w[i] + solve(n / v[i]));
		mn = min(mn, (v[i] - n % v[i]) * d + w[i] + solve((n + v[i] - 1) / v[i]));
	}
	return memo[n] = mn;
}

LL solve2(LL n) {
	LL ans = 1LL << 60;
	priority_queue<LLLL, vector<LLLL>, greater<>> q;
	q.emplace(make_pair(0, n));
	map<LL, LL> memo;
	const LL divs[3] = { 2, 3, 5 };
	const LL costs[3] = { a, b, c };
	while (!q.empty()) {
		LLLL top = q.top();
		q.pop();
		LL cost = top.first;
		LL x = top.second;
		if (cost > memo[x]) continue;
		memo[x] = cost;
		if ((x >> 32) * d < (1LL << 30)) {
			ans = min(ans, cost + x * d);
		}
		for (LL i = 0; i < 3; ++i) {
			LL y = x / divs[i];
			LL c = cost + costs[i] + (x - y * divs[i]) * d;
			if (memo.find(y) == memo.end() || memo[y] > c) {
				memo[y] = c;
				q.emplace(make_pair(c, y));
			}
			if (x != y * divs[i]) {
				++y;
				c = cost + costs[i] + (y * divs[i] - x) * d;
				if (memo.find(y) == memo.end() || memo[y] > c) {
					memo[y] = c;
					q.emplace(make_pair(c, y));
				}
			}
		}
	}
	return ans;
}

int main() {
	LL T, n;
	cin >> T;
	for (LL t = 0; t < T; ++t) {
		cin >> n >> a >> b >> c >> d;
		memo.clear();
		cout << solve(n) << endl;
	}
	return 0;
}
