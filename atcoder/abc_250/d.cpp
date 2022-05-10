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

int64_t solve(int64_t N) {
	vector<int64_t> primes = { 2 };
	for (int i = 3; i <= 1000003; i += 2) {
		for (int prime : primes) {
			if (i < prime * prime) {
				primes.push_back(i);
				break;
			}
			if ((i % prime) == 0) {
				break;
			}
		}
	}

	int64_t ans = 0, pi = 0;
	for (auto q : primes) {
		int64_t mx = N / (q * q * q);
		if (mx < 2) break;
		mx = min(mx, q - 1);
		while (pi > 0 && primes[pi] > mx) {
			--pi;
		}
		while (primes[pi] <= mx) {
			++pi;
		}
		ans += pi;
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	cout << solve(N) << endl;
	return 0;
}
