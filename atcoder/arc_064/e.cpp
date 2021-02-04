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
typedef long double LD;

static const LL INF = 1LL << 60;

LD solve(long long x_s, long long y_s, long long x_t, long long y_t, long long N, std::vector<long long> &x, std::vector<long long> &y, std::vector<long long> &r) {
	x.insert(x.begin(), x_s);
	y.insert(y.begin(), y_s);
	r.insert(r.begin(), 0);
	x.emplace_back(x_t);
	y.emplace_back(y_t);
	r.emplace_back(0);
	vector<LD> dist(N + 2, 1e+20);
	dist[0] = 0;
	priority_queue<pair<LD, int>, vector<pair<LD, int>>, greater<>> q;
	q.emplace(make_pair(0, 0));
	while (!q.empty()) {
		pair<LD, int> top = q.top();
		q.pop();
		LD cost = top.first;
		int node = top.second;
		if (cost > dist[node]) continue;
		for (int i = 1; i <= N + 1; ++i) {
			LD dx = x[i] - x[node], dy = y[i] - y[node];
			LD c = cost + max(0.0L, sqrt(dx * dx + dy * dy) - (r[i] + r[node]));
			if (c < dist[i]) {
				dist[i] = c;
 				q.emplace(make_pair(c, i));
			}
		}
	}
	return dist[N + 1];
}

int main() {
	cout.precision(12);
    long long x_s, y_s, x_t, y_t, N;
	std::cin >> x_s >> y_s >> x_t >> y_t >> N;
	std::vector<long long> x(N), y(N), r(N);
	for (int i = 0; i < N; i++) {
		std::cin >> x[i] >> y[i] >> r[i];
	}
	cout << solve(x_s, y_s, x_t, y_t, N, x, y, r) << endl;
	return 0;
}
