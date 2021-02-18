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

LL solve(long long N, long long M, std::vector<long long> &X) {
	LL left = -1, right = N * 2;
	auto possible = [&](LL t) -> bool {
		LL left = 1;
		for (int i = 0; i < M; i++) {
			LL r = X[i];
			if (r > left) {
				LL d = r - left;
				if (d > t) return false;
				left = max(r + (t - d * 2), r + (t - d) / 2) + 1;
			} else {
				LL d = left - r;
				if (d > t) return false;
				left = r + t + 1;
			}
			if (left > N) {
				return true;
			}
		}
		return false;
	};
	while (right - left > 1) {
		LL mid = (left + right) / 2;
		if (possible(mid)) {
			right = mid;
		} else {
			left = mid;
		}
	}
	return right;
}

int main() {
    long long N, M;
	std::cin >> N >> M;
	std::vector<long long> X(M);
	for (int i = 0; i < M; i++) {
		std::cin >> X[i];
	}
	cout << solve(N, M, X) << endl;
	return 0;
}
