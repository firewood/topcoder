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

LL solve(long long N) {
	LL ans = 0;
	for (LL b = 1000; b <= N; b *= 1000) {
		ans += N + 1 - b;
	}
	return ans;
}

int main() {
	long long N;
	std::cin >> N;
	cout << solve(N) << endl;
	return 0;
}
