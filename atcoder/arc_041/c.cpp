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

LL solve(long long N, long long L, std::vector<long long> &x, std::vector<std::string> &d) {
	x.emplace_back(L + 1);
	d.emplace_back("L");
	LL prev = 0, count = 0, ans = 0;
	vector<LL> v(N + 1);
	for (LL i = N - 1; i >= 0; --i) {
		if (d[i] == "L") {
			ans += (prev - x[i] - 1) * count;
			count += 1;
			prev = x[i];
			v[i] = count;
		} else {
			count = 0;
		}
	}
	ans += (prev - 1) * count;
	count = 0;
	for (LL i = 0; i < N; ++i) {
		if (d[i] == "R") {
			ans += (x[i] - prev - 1) * count;
			count += 1;
			prev = x[i];
			if (d[i + 1] == "L") {
				ans += max(count, v[i + 1]) * (x[i + 1] - x[i] - 1);
			}
		} else {
			count = 0;
		}
	}
	return ans;
}

int main() {
    long long N, L;
	std::cin >> N >> L;
	std::vector<long long> x(N);
	std::vector<std::string> d(N);
	for (int i = 0; i < N; i++) {
		std::cin >> x[i] >> d[i];
	}
	cout << solve(N, L, x, d) << endl;
	return 0;
}
