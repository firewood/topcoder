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

int64_t solve(int64_t N, std::vector<int64_t> a) {
	int64_t same_cnt = 0, diff_cnt = 0;
	for (int i = 0; i < N; ++i) {
		if (a[i] == i) {
			++same_cnt;
		} else {
			diff_cnt += a[a[i]] == i;
		}
	}
	return (same_cnt - 1) * same_cnt / 2 + diff_cnt / 2;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
		--a[i];
	}
	cout << solve(N, a) << endl;
	return 0;
}
