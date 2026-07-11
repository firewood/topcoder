#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int64_t solve(int64_t N, string S, vector<int64_t> X, vector<int64_t> Y) {
	vector<int64_t> dp = {
		-X[0] * (S[0] == 'R'),
		-X[0] * (S[0] == 'S')
	};
	for (int64_t i = 1; i < N; ++i) {
		dp = {
			max(dp[0], dp[1] + Y[i - 1]) - X[i] * (S[i] == 'R'),
			max(dp[0], dp[1]) - X[i] * (S[i] == 'S')
		};
	}
	return max(dp[0], dp[1]);
}

void process_case() {
	int64_t N;
	cin >> N;
	string S;
	cin >> S;
	vector<int64_t> X(N);
	for (int64_t i = 0; i < N; ++i) {
		cin >> X[i];
	}
	vector<int64_t> Y(N - 1);
	for (int64_t i = 0; i < N - 1; ++i) {
		cin >> Y[i];
	}
	auto ans = solve(N, S, X, Y);
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		process_case();
	}
}
