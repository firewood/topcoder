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

int64_t solve(int64_t N, std::vector<std::string> S) {
	int64_t ans = INF;
	for (int d = '0'; d <= '9'; ++d) {
		vector<int> used(N);
		int done = 0;
		int64_t t;
		for (t = 0; done < N; ++t) {
			for (int i = 0; i < N; ++i) {
				if (!used[i] && S[i][t % 10] == d) {
					used[i] = 1;
					done += 1;
					break;
				}
			}
		}
		ans = min(ans, t - 1);
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
