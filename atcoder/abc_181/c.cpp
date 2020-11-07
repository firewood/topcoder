#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
static const LL INF = 1LL << 60;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
LL lcm(LL a, LL b) { return (a / gcd(a, b)) * b; }

void solve(long long N, std::vector<long long> &x, std::vector<long long> &y) {
	bool ans = false;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; ++j) {
			for (int k = j + 1; k < N; ++k) {
				vector<II> v({ II(x[i], y[i]), II(x[j], y[j]), II(x[k], y[k]) });
				sort(v.begin(), v.end());
				LL dx = v[2].first - v[0].first, dy = v[2].second - v[0].second;
				LL dx2 = v[1].first - v[0].first, dy2 = v[1].second - v[0].second;
				LL g = gcd(dx, dy), g2 = gcd(dx2, dy2);
				if (dx / g == dx2 / g2 && dy / g == dy2 == g2) {
					ans = true;
				}
			}
		}
	}
	cout << (ans ? "Yes" : "No") << endl;
}

int main() {
    long long N;
	std::cin >> N;
	std::vector<long long> x(N);
	std::vector<long long> y(N);
	for (int i = 0; i < N; i++) {
		std::cin >> x[i];
		std::cin >> y[i];
	}
	solve(N, x, y);
	return 0;
}
