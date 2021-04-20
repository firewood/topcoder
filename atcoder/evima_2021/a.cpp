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
typedef long double LD;
typedef pair<LL, LL> II;
typedef pair<LL, II> III;

static const LL INF = 1LL << 60;

LL solve(long long N) {
	LL ans = INF;
	for (LL a = 0; a <= 80; ++a) {
		for (LL b = 0; b <= 80; ++b) {
			LL c = a * 8 + b * 10;
			if (c <= N && ((N - c) % 26 == 0)) {
				ans = min(ans, a + b);
			}
		}
	}
	return ans;
}

int main() {
    long long N;
	std::cin >> N;
	cout << solve(N) << endl;
	return 0;
}
