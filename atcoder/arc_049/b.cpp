#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
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

void solve(long long N, std::vector<double> &x, std::vector<double> &y, std::vector<double> &c) {
	double top = -1e5, bottom = 1e5, left = -1e5, right = 1e5;
	auto cost = [&](double center_x, double center_y) {
		double max_time = 0;
		for (LL i = 0; i < N; ++i) {
			max_time = max(max_time, max(abs(x[i] - center_x), abs(y[i] - center_y)) * c[i]);
		}
		return max_time;
	};
	auto get_center_x = [&](double y) {
		double left = -1e5, right = 1e5;
		for (int t = 0; t < 100; ++t) {
			if (cost((left * 2 + right) / 3, y) > cost((left + right * 2) / 3, y)) {
				left = (left * 2 + right) / 3;
			} else {
				right = (left + right * 2) / 3;
			}
		}
		return left;
	};
	for (int t = 0; t < 100; ++t) {
		double ay = (top * 2 + bottom) / 3, by = (top + bottom * 2) / 3;
		if (cost(get_center_x(ay), ay) > cost(get_center_x(by), by)) {
			top = ay;
		} else {
			bottom = by;
		}
	}
	double ans = cost(get_center_x(top), top);
	cout << ans << endl;
}

int main() {
	cout.precision(10);
    long long N;
	scanf("%lld", &N);
	std::vector<double> x(N);
	std::vector<double> y(N);
	std::vector<double> c(N);
	for (int i = 0; i < N; i++) {
		scanf("%lf", &x[i]);
		scanf("%lf", &y[i]);
		scanf("%lf", &c[i]);
	}
	solve(N, x, y, c);
	return 0;
}
