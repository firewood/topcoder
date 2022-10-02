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
#include <bitset>

using namespace std;

typedef bitset<100> BS;

bool solve(int64_t N, int64_t S, std::vector<int64_t> a, std::vector<int64_t> b) {
	vector<int> dp(10102);
	vector<BS> memo(10102);
	dp[0] = 1;
	for (int i = 0; i < N; ++i) {
		vector<int> next(10102);
		vector<BS> next_memo(10102);
		for (int j = 0; j <= 10000; ++j) {
			if (dp[j]) {
				next[j + a[i]] = 1;
				next_memo[j + a[i]] = memo[j];
				next[j + b[i]] = 1;
				next_memo[j + b[i]] = memo[j];
				next_memo[j + b[i]][i] = true;
			}
		}
		dp = next;
		memo = next_memo;
	}

	if (!dp[S]) {
		return false;
	} else {
		cout << "Yes" << endl;
		for (int i = 0; i < N; ++i) {
			cout << (memo[S][i] ? "T" : "H");
		}
		cout << endl;

		return true;
	}
}

int main() {
	int64_t N, S;
	std::cin >> N >> S;
	std::vector<int64_t> a(N), b(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i] >> b[i];
	}
	if (!solve(N, S, a, b)) {
		cout << "No" << endl;
	}
	return 0;
}
