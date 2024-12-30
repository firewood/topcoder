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
	int64_t ans = 0, rt = sqrtl(N);

	vector<int64_t> primes = { 2 };
	for (int i = 3; i <= 2000002; i += 2) {
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
	for (int i = 0; i < primes.size(); ++i) {
		for (int j = i + 1; j < primes.size(); ++j) {
			if (primes[i] * primes[j] > rt) {
				break;
			}
			++ans;
		}
	}
	for (int i = 0; i < primes.size(); ++i) {
		if (primes[i] * primes[i] * primes[i] * primes[i] > rt) {
			break;
		}
		++ans;
	}

	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	cout << solve(N) << endl;
	return 0;
}
