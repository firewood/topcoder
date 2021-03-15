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

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

LL solve(long long N, std::vector<long long>& X) {
	LL ans = INF;
	vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };
	for (LL b = 1; b < (1 << primes.size()); ++b) {
		LL y = 1;
		for (int i = 0; i < primes.size(); ++i) {
			if (b & (1 << i)) y *= primes[i];
		}
		auto check = [&]() {
			for (auto x : X) {
				if (gcd(x, y) == 1) return false;
			}
			return true;
		};
		if (check()) {
			ans = min(ans, y);
		}
	}
	return ans;
}

int main() {
	long long N;
	std::cin >> N;
	std::vector<long long> X(N);
	for (int i = 0; i < N; i++) {
		std::cin >> X[i];
	}
	cout << solve(N, X) << endl;
	return 0;
}
