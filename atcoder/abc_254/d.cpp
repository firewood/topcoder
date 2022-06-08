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
	int64_t ans = 0;
	for (int64_t i = 1; i <= N; ++i) {
		int64_t k = i;
		for (int64_t j = 2; j * j <= k; ++j) {
			while ((k % (j * j)) == 0) {
				k /= j * j;
			}
		}
		for (int64_t j = 1; k * j * j <= N; ++j) {
			++ans;
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	cout << solve(N) << endl;
	return 0;
}
