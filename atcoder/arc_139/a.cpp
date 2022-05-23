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

#ifdef _MSC_VER
inline int64_t ctz(int64_t x) {
	unsigned long index = 0;
	_BitScanForward64(&index, x);
	return index;
}
#else
#define ctz __builtin_ctzll
#endif

int64_t solve(int64_t N, std::vector<int64_t> T) {
	int64_t ans = 0;
	for (auto x : T) {
		++ans;
		while (ctz(ans) != x) {
			ans |= (1LL << x) - 1;
			++ans;
		}
	}
	return ans;
}

int64_t solve2(int64_t N, std::vector<int64_t> T) {
	int64_t ans = 0;
	for (auto x : T) {
		++ans;
		while (ctz(ans) != x) {
			++ans;
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> T(N);
	for (int i = 0; i < N; i++) {
		std::cin >> T[i];
	}
	cout << solve(N, T) << endl;
	return 0;
}
