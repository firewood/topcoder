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

bool solve(int N, string S, std::string X) {
	vector<int> dp(7);
	dp[0] = 1;
	for (int i = N - 1, d = 1; i >= 0; --i, d = (d * 10) % 7) {
		vector<int> next(7);
		int x = ((S[i] - '0') * d) % 7;
		if (X[i] == 'T') {
			next = dp;
			for (int j = 0; j < 7; ++j) {
				if (dp[(j + x) % 7]) {
					next[j] = 1;
				}
			}
		} else {
			for (int j = 0; j < 7; ++j) {
				if (dp[(j + x) % 7]) {
					next[j] = dp[j];
				}
			}
		}
		dp = next;
	}
	return dp[0] != 0;
}

int main() {
    int N;
	std::string S, X;
	std::cin >> N >> S >> X;
	if (solve(N, S, X)) {
		cout << "Takahashi" << endl;
	} else {
		cout << "Aoki" << endl;
	}
	return 0;
}
