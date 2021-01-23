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
typedef pair<LL, LL> II;

void solve(long long N, long long C, std::vector<long long> &a, std::vector<long long> &b, std::vector<long long> &c) {
	vector<II> events;
	for (int i = 0; i < N; i++) {
		events.emplace_back(II(a[i], c[i]));
		events.emplace_back(II(b[i] + 1, -c[i]));
	}
	sort(events.begin(), events.end());
	LL ans = 0, sum = 0, last_day = 0;
	for (auto kv : events) {
		LL day = kv.first;
		ans += min(sum, C) * (day - last_day);
		last_day = day;
		sum += kv.second;
	}
	cout << ans << endl;
}

int main() {
	long long N, C;
	std::cin >> N >> C;
	std::vector<long long> a(N), b(N), c(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i] >> b[i] >> c[i];
	}
	solve(N, C, a, b, c);
	return 0;
}
