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
	LL ans = 0;
	for (LL i = 1; i <= N; ++i) {
		bool ok = true;
		for (LL j = i; j > 0; j /= 8) {
			if ((j % 8) == 7) ok = false;
		}
		for (LL j = i; j > 0; j /= 10) {
			if ((j % 10) == 7) ok = false;
		}
		ans += ok;
	}
	return ans;
}

int main() {
	long long N;
	std::cin >> N;
	cout << solve(N) << endl;
	return 0;
}
