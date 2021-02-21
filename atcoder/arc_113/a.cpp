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

LL solve(long long K) {
	LL ans = 0;
	for (LL a = 1; a <= K; ++a) {
		for (LL b = 1; b <= K; ++b) {
			if (a * b > K) break;
			ans += K / a / b;
		}
	}
	return ans;
}

int main() {
    long long K;
	std::cin >> K;
	cout << solve(K) << endl;
	return 0;
}
