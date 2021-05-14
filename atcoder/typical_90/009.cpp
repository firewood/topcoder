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
typedef pair<LL, LL> II;
typedef pair<LL, II> III;

LD solve(long long N, std::vector<long long> &X, std::vector<long long> &Y) {
	LD ans = 0;
	for (int i = 0; i < N; i++) {
		vector<pair<LD, int>> v;
		for (int j = 0; j < N; ++j) {
			if (i != j) {
				v.emplace_back(make_pair(atan2(Y[j]-Y[i], X[j]-X[i]), j));
			}
		}
		sort(v.begin(), v.end());
		for (int j = 0; j < 2 * N; ++j) {
			v.emplace_back(make_pair(v[j].first + M_PI * 2, v[j].second));
		}
		for (int j = 0; j < N - 1; ++j) {
			size_t pos = lower_bound(v.begin(), v.end(), make_pair(v[j].first + M_PI, 0)) - v.begin();
			for (size_t k = pos - 1; k <= pos; ++k) {
				if (k <= j || v[j].second == v[k].second) continue;
				LD deg = (v[k].first - v[j].first) * 180 / M_PI;
				while (deg > 180) {
					deg = 360 - deg;
				}
				ans = max(ans, deg);
			}
		}
	}
	return ans;
}

int main() {
#if DEBUG
	freopen("in_1.txt", "r", stdin);
#endif
cout.precision(20);
	long long N;
	std::cin >> N;
	std::vector<long long> X(N), Y(N);
	for (int i = 0; i < N; i++) {
		std::cin >> X[i] >> Y[i];
	}
	cout << solve(N, X, Y) << endl;
	return 0;
}
