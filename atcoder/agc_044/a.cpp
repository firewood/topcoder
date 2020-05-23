// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> LLLL;

int main(int argc, char* argv[]) {
	LL t, n, a, b, c, d, ans;
	cin >> t;
	for (LL tt = 0; tt < t; ++tt) {
		cin >> n >> a >> b >> c >> d;
		ans = 1LL << 60;
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
		cout << ans << endl;
	}
	return 0;
}
