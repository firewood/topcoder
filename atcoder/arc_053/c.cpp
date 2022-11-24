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

typedef long double LD;
typedef pair<int64_t, int64_t> II;
typedef pair<int64_t, II> III;

static const int64_t INF = 1LL << 60;

int64_t solve(int64_t N, std::vector<int64_t> a, std::vector<int64_t> b) {
	int64_t ans = -INF, sum = 0;
	vector<II> v, w;
	for (int i = 0; i < N; ++i) {
		if (b[i] > a[i]) {
			v.emplace_back(II(a[i], i));
		} else {
			w.emplace_back(II(-b[i], i));
		}
	}
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	for (auto kv : v) {
		sum += a[kv.second];
		ans = max(ans, sum);
		sum -= b[kv.second];
	}
	for (auto kv : w) {
		sum += a[kv.second];
		ans = max(ans, sum);
		sum -= b[kv.second];
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> a(N), b(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i] >> b[i];
	}
	cout << solve(N, a, b) << endl;
	return 0;
}
