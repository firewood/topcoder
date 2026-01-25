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

static const int64_t INF = 1LL << 60;

int64_t solve(int64_t N, std::vector<std::string> &S) {
	for (int i = 0; i < N; ++i) {
		// 全部白いものも作れるように、右端に番兵を置く 
		S[i] += '#';
	}

	vector<vector<int64_t>> dp(2, vector<int64_t>(N + 1, 0));
	vector<int64_t> left_black_cnt(N + 2);
	int curr = 0, next = 1;
	for (int i = 0; i < N; ++i) {
		curr ^= 1;
		next ^= 1;
		for (int j = 0; j <= N; ++j) {
			left_black_cnt[j + 1] = left_black_cnt[j] + (S[i][j] != '.');
		}
		int64_t right_white_cnt = 0, prev = INF;
		for (int j = N; j >= 0; --j) {
			prev = min(prev, dp[curr][j]);
			int64_t is_white = (S[i][j] == '.');
			// jまでを白く、jから黒く塗る 
			dp[next][j] = is_white + left_black_cnt[j] + right_white_cnt + prev;
			right_white_cnt += is_white;
		}
	}
	return *min_element(dp[next].begin(), dp[next].end());
}

int main() {
	{
		int64_t N;
		std::cin >> N;
		std::vector<std::string> S(N);
		for (int i = 0; i < N; i++) {
			std::cin >> S[i];
		}
		cout << solve(N, S) << endl;
	}
	return 0;
}
