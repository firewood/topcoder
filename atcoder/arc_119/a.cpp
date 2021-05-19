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

LL solve(long long N) {
	LL ans = 1LL << 60;
	for (LL b = 0, b2 = 1; b2 <= N; ++b, b2 <<= 1) {
		LL a = N / b2;
		LL c = N - a * b2;
		ans = min(ans, a + b + c);
	}
	return ans;
}

int main() {
    long long N;
	std::cin >> N;
	cout << solve(N) << endl;
	return 0;
}
