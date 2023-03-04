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
	vector<int64_t> cnt(N);
	for (int64_t a = 1; a < N; ++a) {
		for (int64_t ab = a; ab < N; ab += a) {
			cnt[ab] += 1;
		}
	}
	for (int64_t ab = 1; ab < N; ++ab) {
		ans += cnt[ab] * cnt[N - ab];
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	cout << solve(N) << endl;
	return 0;
}
