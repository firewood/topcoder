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
#ifdef __GNUC__
#define int128_t __int128
#else
#include <boost/multiprecision/cpp_int.hpp>
typedef boost::multiprecision::int128_t int128_t;
#endif

LL solve(long long N) {
#if 1
	LL ans = 0;
	for (LL i = 1; i * i <= N; ++i) {
		LL j = N / i;
		if (i * j == N) {
			ans += i % 2 == 1;
			ans += i != j && j % 2 == 1;
		}
	}
	return ans * 2;
#else
	LL N2 = N * 2;
	LL ans = 0;
	for (LL i = 1; i * i <= N2; ++i) {
		LL j = N2 / i;
		if (i * j == N2) {
			ans += (N - (i * int128_t(i + 1)) / 2) % i == 0;
			if (i != j) {
				ans += (N - (j * int128_t(j + 1)) / 2) % j == 0;
			}
		}
	}
	return ans;
#endif
}

int main() {
    long long N;
	std::cin >> N;
	cout << solve(N) << endl;
	return 0;
}
