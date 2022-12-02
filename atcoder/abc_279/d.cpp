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

LD solve(int64_t A, int64_t B) {
	int64_t left = 0, right = 1LL << 60;
	auto cost = [&](int64_t t) {
		return LD(t) * B + LD(A) / sqrt(1 + LD(t));
	};
	for (int tt = 0; tt < 100; ++tt) {
		if (cost((left * 2 + right) / 3) < cost((left + right * 2) / 3)) {
			right = (left + right * 2) / 3;
		} else {
			left = (left * 2 + right) / 3;
		}
	}
	LD ans = 1e20;
	for (int64_t tt = max(int64_t(0), left - 2); tt <= left + 2; ++tt) {
		ans = min(ans, cost(tt));
	}
	return ans;
}

int main() {
	cout.precision(20);
	int64_t A, B;
	std::cin >> A >> B;
	cout << solve(A, B) << endl;
	return 0;
}
