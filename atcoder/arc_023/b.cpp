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

int64_t solve(int64_t R, int64_t C, int64_t D, std::vector<std::vector<int64_t>> A) {
	int64_t ans = 0;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (i + j <= D && ((i + j) % 2) == (D % 2)) {
				ans = max(ans, A[i][j]);
			}
		}
	}
	return ans;
}

int main() {
	int64_t R, C, D;
	std::cin >> R >> C >> D;
	std::vector<std::vector<int64_t>> A(R, std::vector<int64_t>(C));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			std::cin >> A[i][j];
		}
	}
	cout << solve(R, C, D, A) << endl;
	return 0;
}
