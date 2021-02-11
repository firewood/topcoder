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

LL solve(long long N, long long K, std::vector<long long> &a, std::vector<long long> &b) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	// 値 x の位置を求める
	// K未満ならleft = mid
	// K以上ならright = mid
	auto calc_pos = [&](LL x) -> LL {
		LL sum = 0;
		for (int i = 0; i < N; i++) {
			sum += lower_bound(b.begin(), b.end(), x / a[i] + 1) - b.begin();
		}
		return sum;
	};

	LL left = -1, right = a.back() * b.back();
	while (right - left > 1) {
		LL mid = (left + right) / 2;
		LL pos = calc_pos(mid);
		if (pos >= K) {
			right = mid;
		} else {
			left = mid;
		}
	}
	return right;
}

int main() {
    long long N, K;
	std::cin >> N >> K;
	std::vector<long long> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	std::vector<long long> b(N);
	for (int i = 0; i < N; i++) {
		std::cin >> b[i];
	}
	cout << solve(N, K, a, b) << endl;
	return 0;
}
