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
	for (LL i = 1; i * i <= N; ++i) {
		LL j = N / i;
		if (i * j == N) {
			ans += i % 2 == 1;
			ans += i != j && j % 2 == 1;
		}
	}
	return ans * 2;
}

int main() {
    long long N;
	std::cin >> N;
	cout << solve(N) << endl;
	return 0;
}
