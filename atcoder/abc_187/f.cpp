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

int solve(int N, int M, std::vector<int> &A, std::vector<int> &B) {
	int e[18][18] = {};
	for (int i = 0; i < M; ++i) {
		e[A[i]][B[i]] = 1;
		e[B[i]][A[i]] = 1;
	}
	int sz = 1 << N;
	vector<int> dp(sz, N);
	for (int b = 1; b < sz; ++b) {
		bool ok = true;
		for (int i = 0; i < N; ++i) {
			if (b & (1 << i)) {
				for (int j = i + 1; j < N; ++j) {
					if (b & (1 << j)) {
						if (!e[i][j]) {
							ok = false;
						}
					}
				}
			}
		}
		if (ok) {
			dp[b] = 1;
		} else {
			// •”•ªW‡—ñ‹“
			int c = N;
			for (int sb = b; sb > 0; sb = (sb - 1) & b) {
				c = min(c, dp[sb] + dp[b - sb]);
			}
			dp[b] = c;
		}
	}
	return dp[sz - 1];
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> A(M), B(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i] >> B[i];
		A[i]--; B[i]--;
	}
	cout << solve(N, M, A, B) << endl;
	return 0;
}
