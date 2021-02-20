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

LL solve(const std::string &X, long long M) {
	LL md = *max_element(X.begin(), X.end()) - '0';
	LL left = md, right = INF;
	auto possible = [&](LL b) {
		LL x = 0;
		for (char c : X) {
			if (x > M / b) return false;
			x = x * b + (c - '0');
		}
		return x <= M;
	};
	while (right - left > 1) {
		LL mid = (left + right) / 2;
		if (!possible(mid)) {
			right = mid;
		} else {
			left = mid;
		}
	}
	return right >= INF ? 1 : left - md;
}

int main() {
    std::string X;
	long long M;
	std::cin >> X >> M;
	cout << solve(X, M) << endl;
	return 0;
}
