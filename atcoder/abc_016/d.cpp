#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
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

struct Point {
	long double x;
	long double y;
	Point(long double x_, long double y_) : x(x_), y(y_) { }
	static bool is_cross(const Point& a, const Point& b, const Point& c, const Point& d) {
		auto calc = [](const Point& a, const Point& b, const Point& c) {
			return (a.x - b.x) * (c.y - a.y) - (a.y - b.y) * (c.x - a.x);
		};
		return calc(a, b, c) * calc(a, b, d) < 0 && calc(c, d, a) * calc(c, d, b) < 0;
	}
};

void solve(long long A_x, long long A_y, long long B_x, long long B_y, long long N, std::vector<long long>& X, std::vector<long long>& Y) {
	int cross = 0;
	Point a(A_x, A_y), b(B_x, B_y);
	for (LL i = 0; i < N; ++i) {
		Point c(X[i], Y[i]), d(X[(i + 1) % N], Y[(i + 1) % N]);
		cross += Point::is_cross(a, b, c, d);
	}
	int ans = cross / 2 + 1;
	cout << ans << endl;
}

int main() {
	long long A_x, A_y, B_x, B_y;
	std::cin >> A_x >> A_y >> B_x >> B_y;
	long long N;
	std::cin >> N;
	std::vector<long long> X(N);
	std::vector<long long> Y(N);
	for (int i = 0; i < N; i++) {
		std::cin >> X[i] >> Y[i];
	}
	solve(A_x, A_y, B_x, B_y, N, X, Y);
	return 0;
}
