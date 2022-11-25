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

int64_t solve(int64_t N, std::vector<std::string> S) {
	int64_t ans = 0, cnt = 0;
	vector<int64_t> xcnt(N), sum(N), seq(N);
	for (int i = 0; i < N; ++i) {
		xcnt[i] = count(S[i].begin(), S[i].end(), 'X');
		for (auto c : S[i]) {
			if (c >= '1' && c <= '9') {
				sum[i] += c - '0';
			}
		}
	}
	iota(seq.begin(), seq.end(), 0);
	sort(seq.begin(), seq.end(), [&](int64_t lhs, int64_t rhs) { return sum[lhs] * xcnt[rhs] < sum[rhs] * xcnt[lhs]; });
	for (auto i : seq) {
		for (auto c : S[i]) {
			if (c >= '1' && c <= '9') {
				ans += cnt * (c - '0');
			} else {
				++cnt;
			}
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<std::string> S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}
	cout << solve(N, S) << endl;
	return 0;
}
