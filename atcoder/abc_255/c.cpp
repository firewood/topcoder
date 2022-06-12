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

#ifdef __GNUC__
#define int128_t __int128
#else
#include <boost/multiprecision/cpp_int.hpp>
typedef boost::multiprecision::int128_t int128_t;
#endif

int64_t solve(int128_t X, int128_t A, int128_t D, int128_t N) {
	int128_t ans, B = A + D * (N - 1);
	if (A > B) {
		swap(A, B);
		D = -D;
	}
	if (X <= A) {
		ans = A - X;
	} else if (X > B) {
		ans = X - B;
	} else {
		X = (X - A) % D;
		ans = min(X, D - X);
	}
	return (int64_t)ans;
}

int main() {
	int64_t X, A, D, N;
	std::cin >> X >> A >> D >> N;
	cout << solve(X, A, D, N) << endl;
	return 0;
}
