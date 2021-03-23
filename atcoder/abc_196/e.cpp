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

static const LL INF = 1LL << 60;

vector<LL> solve(long long N, std::vector<long long> &a, std::vector<long long> &t, long long Q, std::vector<long long> x) {
	LL add = 0, left = -INF, right = INF;
	for (int i = 0; i < N; i++) {
		switch (t[i]) {
		case 1:
			add += a[i];
			left += a[i];
			right += a[i];
			break;
		case 2:
			// max
			left = max(left, a[i]);
			right = max(right, a[i]);
			break;
		case 3:
			// min
			left = min(left, a[i]);
			right = min(right, a[i]);
			break;
		}
	}
	for (int i = 0; i < Q; i++) {
		x[i] = max(left, min(right, add + x[i]));
	}
	return x;
}

int main() {
    long long N, Q;
	std::cin >> N;
	std::vector<long long> a(N), t(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i] >> t[i];
	}
	std::cin >> Q;
	std::vector<long long> x(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> x[i];
	}
	vector<LL> ans = solve(N, a, t, Q, x);
	for (auto x : ans) {
		cout << x << endl;
	}
	return 0;
}
