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

int64_t solve(int64_t N, int64_t K, int64_t M, int64_t R, std::vector<int64_t> S) {
	sort(S.rbegin(), S.rend());
	int64_t sum = accumulate(S.begin(), S.begin() + K - 1, int64_t(0));
	if (K < N && sum + S[K - 1] >= K * R) {
		return 0;
	}
	int64_t ans = max(int64_t(0), K * R - sum);
	return ans > M ? -1 : ans;
}

int main() {
	int64_t N, K, M, R;
	std::cin >> N >> K >> M >> R;
	std::vector<int64_t> S(N-1);
	for (int i = 0; i < N-1; i++) {
		std::cin >> S[i];
	}
	cout << solve(N, K, M, R, S) << endl;
	return 0;
}
