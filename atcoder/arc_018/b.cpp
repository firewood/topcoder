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

void solve(int N, std::vector<long long> &x, std::vector<long long> &y) {
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			for (int k = j + 1; k < N; ++k) {
				long long s = (x[j] - x[i]) * (y[k] - y[i]) - (y[j] - y[i]) * (x[k] - x[i]);
				ans += (s != 0) && (abs(s) % 2 == 0);
			}
		}
	}
	cout << ans << endl;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<long long> x(N);
	std::vector<long long> y(N);
	for (int i = 0; i < N; i++) {
		std::cin >> x[i] >> y[i];
	}
	solve(N, x, y);
	return 0;
}
